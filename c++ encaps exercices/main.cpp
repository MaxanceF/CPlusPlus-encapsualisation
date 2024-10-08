#include <iostream>
#include "exercice.h"
#include <vector>


// Define the operator<< for std::vector<float>
std::ostream& operator<<(std::ostream& os, const std::vector<float>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i != vec.size() - 1) {
            os << ", ";  // Add comma between elements, but not after the last one
        }
    }
    os << "]";
    return os;
}

int main()
{
    Vector2 v;
    Entity e;
    v.setVector2(5.5f,15.9f);
    e.Entitypos(777.5f, 150.9f);
    std::cout << v.getVector2() << std::endl;
    std::cout << e.getEntitypos() << std::endl;
    return 0;
}