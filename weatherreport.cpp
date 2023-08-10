#include <iostream>
#include <assert.h>
#include "weatherreport.h"

namespace WeatherSpace
{    
    int SensorStub::Humidity() const
    {
        return 72;
    }
    int SensorStub::Precipitation() const
    {
        return 70;
    }
    double SensorStub::TemperatureInC() const
    {
        return 26;
    }
    int SensorStub::WindSpeedKMPH() const
    {
        return 52;
    }

    int HighPrecipitationStub::Precipitation() const
    {
        //high precipitation(> 60)
        return 61;
    }

    int HighPrecipitationStub::WindSpeedKMPH() const
    {
        //low wind - speed(< 50)
        return 49;
    }

   std::string Report(const IWeatherSensor& sensor)
    {
        int precipitation = sensor.Precipitation();
        // precipitation < 20 is a sunny day
        std::string report = "Sunny Day";

        if (sensor.TemperatureInC() > 25)
        {
            if (precipitation >= 20 && precipitation < 60)
                report = "Partly Cloudy";
            else if (sensor.WindSpeedKMPH() > 50)
                report = "Alert, Stormy with heavy rain";
        }
        return report;
    }
    
   void TestRainy()
    {
        SensorStub sensor;
        std::string report = Report(sensor);
        std::cout << report << std::endl;
        assert(report.find("rain") != std::string::npos);
    }

    void TestHighPrecipitation()
    {
        // This instance of stub needs to be different-
        // to give high precipitation (>60) and low wind-speed (<50)
        SensorStub sensor;

        // strengthen the assert to expose the bug
        // (function returns Sunny day, it should predict rain)
        std::string report = Report(sensor);
        assert(report.length() > 0);
        assert(report == "Alert, Stormy with heavy rain");

        HighPrecipitationStub possiblePrecipitation;
        report = Report(possiblePrecipitation);
        assert(report == "Alert, Stormy with heavy rain");
    }   
}

void TestWeatherSpace::testForWeatherReport()
{
    WeatherSpace::TestRainy();
    WeatherSpace::TestHighPrecipitation();
    std::cout << "All is well (maybe)\n";
}

int main() {

    TestWeatherSpace::testForWeatherReport();

    return 0;
}

