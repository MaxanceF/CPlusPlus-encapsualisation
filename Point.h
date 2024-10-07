#ifndef POINT_H
#define POINT_H

#include <string>
#include <sstream> // Pour utiliser std::ostringstream

class Point {
public:
    // Membres publics
    float x, y, z;

    // Constructeur par défaut (initialise le point à l'origine)
    Point() : x(0), y(0), z(0) {}

    // Fonction qui renvoie une chaîne de caractères représentant le point
    std::string ToString() const {
        std::ostringstream oss;
        oss << "Point: x: " << x << ", y: " << y << ", z: " << z;
        return oss.str();
    }

    // Fonction d'affichage
    void display() const {
        std::cout << ToString() << std::endl;
    }
};

#endif // POINT_H