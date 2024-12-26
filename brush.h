#ifndef BRUSH_H
#define BRUSH_H
class Brush{
public:
    virtual ~Brush()=default;
    virtual void draw() const=0;
private:
    int brush_size;
    int density;
};

class CircleBrush:public Brush{
public:
    void draw() const override{}
};

class SquareBrush:public Brush{
public:
    void draw() const override{}
};

#endif