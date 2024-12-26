#ifndef SHAPE_H
#define SHAPE_H
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
class Shape{
public:
    virtual ~Shape()=default;
    virtual void draw() const = 0;
    virtual double area() const = 0;
    virtual std::string toString() const=0;
};

class Line: public Shape{
public:
    void draw() const override{
        std::cout<<"draw a line"<<"\n";
    }
    double area() const override{return 0;}
    std::string toString() const override{
        return "Line";
    }
private:
    double length;
};

class Circle: public Shape{
public:
    void draw() const override{
        std::cout<<"draw a circle"<<"\n";
    }
    double area() const override{
        return 3.14*pow(radius, 2);
    }
    std::string toString() const override{
        return "Circle";
    }
private:
    double radius;
};

class Rectangle: public Shape{
public:
    void draw() const override{
        std::cout<<"draw a rectangle"<<"\n";
    }
    double area() const override{
        return height*width;
    }
    std::string toString() const override{
        return "Rectangle";
    }
private:
    double height;
    double width;
};
#endif 
