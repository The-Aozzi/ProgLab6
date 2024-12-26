#ifndef CANVAS_VIEW_H
#define CANVAS_VIEW_H
#include "canvas.h"
#include <iostream>
class CanvasView{
public:
    void render(const Canvas& canvas) const;
};
#endif