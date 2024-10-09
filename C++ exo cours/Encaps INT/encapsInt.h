#ifndef POINT_H
#define POINT_H
#include <vector>
#include <iostream>

class Integer{
    private:
        int value;
    public:
    Integer();
    Integer(int v): value(v){};

    // +
    Integer operator+(const Integer& other) const {
        return Integer(value + other.value);
    }

    // +=
    Integer& operator+=(const Integer& other) {
        value += other.value;
        return *this; 
    }

    // -
    Integer operator-(const Integer& other) const {
        return Integer(value - other.value);
    }

    // -=
    Integer& operator-=(const Integer& other) {
        value -= other.value;
        return *this;
    }

    // *
    Integer operator*(const Integer& other) const {
        return Integer(value * other.value);
    }

    // *=
    Integer& operator*=(const Integer& other) {
        value *= other.value;
        return *this; 
    }

    // /
    Integer operator/(const Integer& other) const {
        if (other.value == 0) {
            throw std::runtime_error("Division par zéro !");
        }
        return Integer(value / other.value);
    }

    // /=
    Integer& operator/=(const Integer& other) {
        if (other.value == 0) {
            throw std::runtime_error("Division par zéro !");
        }
        value /= other.value;
        return *this; 
    }

    // %
    Integer operator%(const Integer& other) const {
        if (other.value == 0) {
            throw std::runtime_error("Modulo par zéro !");
        }
        return Integer(value % other.value);
    }

    // %=
    Integer& operator%=(const Integer& other) {
        if (other.value == 0) {
            throw std::runtime_error("Modulo par zéro !");
        }
        value %= other.value;
        return *this; 
    }

    // <<
    friend std::ostream& operator<<(std::ostream& os, const Integer& obj) {
        os << obj.value;
        return os; 
        }

    void pow(int exponent) {
        value = std::pow(value, exponent);
    }

};


#endif