#include <iostream>
#include "exercice.h"
#include <vector>


std::ostream& operator<<(std::ostream& os, const std::vector<float>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i != vec.size() - 1) {
            os << ", "; 
        }
    }
    os << "]";
    return os;
}

int main()
{
    Vector2 v;
    v.setVector2(5.5f,15.9f);
    Entity e(100.5f, 200.7f);
    std::cout << v.getVector2() << std::endl;
    std::cout << e.getEntitypos() << std::endl;

    StaticObject staticObj(5, 10);

    BreakableObject breakableObj(50.0f, 15, 20);
    breakableObj.TakeDamage(20.0f);
    breakableObj.TakeDamage(40.0f); 

    Mob mob(30, 40, 100, 1, 1);
    mob.SetterMove();
    mob.TakeDamage(30.0f);
    mob.TakeDamage(80.0f); 

    return 0;
}