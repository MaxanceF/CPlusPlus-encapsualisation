#include <iostream>
#include <vector>
//#include "../C++ encapsualisation/Point.h"

class Point
{
public:
    float x, y, z;
};

int main() {
    Point p;
    std::cout << p.x << ", " << p.y << ", " << p.z;
    return 0;
}