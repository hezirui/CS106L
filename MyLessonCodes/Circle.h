//
// Created by admin on 2024/5/11.
//

#ifndef CS106L_CIRCLE_H
#define CS106L_CIRCLE_H


#include "Shape.h"

class Circle : public Shape{
public:
    Circle (double radius) : _radius(radius) {}
    double area() const{
        return _radius*_radius*3.14;
    }
private:
    double _radius;
};


#endif //CS106L_CIRCLE_H
