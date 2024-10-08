#ifndef POINT_H
#define POINT_H

#include <string>
#include <sstream>

class Point {
public:
    float x, y, z;
    Point() : x(0.f), y(0.f), z(0.f) {}

    // Fonction qui renvoie une chaîne de caractères représentant le point
    std::string ToString() const {
        std::stringstream stream;
        stream << "Point: x: " << x << ", y: " << y << ", z: " << z;
        return stream.str();
    }

    // Fonction d'affichage
    void display() const {
        std::cout << ToString() << std::endl;
    }
};

#endif