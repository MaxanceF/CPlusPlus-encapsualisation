#ifndef POINT_H
#define POINT_H
#include <string>

class Vector2{
    public:
    Vector2();
    Vector2(float _x, float _y);

    float GetX() const;
    float GetY() const;

    void SetX(float _x);
    void SetX(std::string _xStr);

    void SetY(float _y);


    Vector2 operator+(const Vector2& _rigth);
};

#endif