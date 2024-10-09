#include <iostream>
#include <vector>
#include "Vector2.h"


Vector2::Vector2() : x(0.f), y(0.f) {

}

Vector2::Vector2(float _x, float _y) : x(_x), y(_y) {

}

float Vector2::GetX() const{
    return this->x;
}

float Vector2::GetY() const {
    return this->y;
}

void Vector2::SetX(float _x) {
    this->x = _x;
}

void Vector2::SetX(std::string _xStr) {
        this->x = std::stof(_xStr);
}

void Vector2::SetY(float _y) {
    this->y = _y;
}

Vector2 Vector2::operator+(const Vector2& _rigth) {
    Vector2 tmp(this->x + _rigth.GetX(), this->y + _rigth.GetY());
    return tmp;
}

int main() {


}