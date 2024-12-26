#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include <memory>
#include <string>
#include "shape.h"
#include "brush.h"
#include "stroke.h"
class Canvas{
private:
    std::vector<std::shared_ptr<Shape>> shapes;
    std::shared_ptr<Brush> brush;
    std::vector<std::shared_ptr<Stroke>> strokes;
public:
    void addShape(const std::shared_ptr<Shape>& shapes);
    void removeShape(size_t index);
    void drawStroke(std::shared_ptr<Brush> brush);
    void removeStroke(size_t index);
    std::string exportToFile() const;
    void importFromFile(const std::string& data);
};
#endif