#include <iostream>
#include "tshirts.h"

char Tshirts::size(int cms)
{
    char sizeName = '\0';
    if (cms < 38) {
        sizeName = 'S';
    }
    else if (cms > 38 && cms < 42) {
        sizeName = 'M';
    }
    else if (cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

void TestTshirts::testforTshirtSizes()
{
    assert(Tshirts::size(37) == 'S');
    assert(Tshirts::size(38) == 'S');
    assert(Tshirts::size(40) == 'M');
    assert(Tshirts::size(42) == 'M');
    assert(Tshirts::size(43) == 'L');
    std::cout << "All is well (maybe!)\n";
}

int main() {

    TestTshirts::testforTshirtSizes();

    return 0;
}