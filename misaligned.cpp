#include <iostream>
#include "misaligned.h"

int Misaligned::findPairNumber(int majorCol, int minorCol)
{
    return majorCol * 5 + minorCol;
}

int Misaligned::printColorMap()
{    
    int i = 0, j = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            std::cout << findPairNumber(i, j)<< " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return i * j;
}

void TestMisaligned::testForMisalignment()
{
    int result = Misaligned::printColorMap();
    assert(Misaligned::findPairNumber(0, 0) == 1);
    assert(Misaligned::findPairNumber(5, 5) == 25);
    assert(result == 25);
    std::cout << "All is well (maybe!)\n";
}

int main() {

    TestMisaligned::testForMisalignment();

    return 0;
}