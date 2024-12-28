#include "canvas.h"
#include <sstream>

void Canvas::addShape(const std::shared_ptr<Shape>& shape){
    shapes.push_back(shape);
}

void Canvas::removeShape(size_t index){
    if(index<shapes.size()){
        shapes.erase(shapes.begin()+index);
    }
}
std::string Canvas::exportToFile(std::map<int, std::shared_ptr<Canvas>>& exported) const{
    static int index = 0;
    std::ostringstream oss;
    oss<<index;
    index++;
    exported.insert({0, std::make_shared<Canvas>(*this)});
    return oss.str();
}

std::string Canvas::exportToFile() const{
    std::ostringstream oss;
    for(const auto& shape: shapes){
        oss<<shape->toString()<<"\n";
    }
    return oss.str();
}

void Canvas::importFromFile(std::shared_ptr<Canvas> canvas){
    *this = *canvas;
}