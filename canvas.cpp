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
std::string Canvas::exportToFile() const{
    std::ostringstream oss;
    for(const auto& shape: shapes){
        oss<<shape->toString()<<"\n";
    }
    return oss.str();
}

void Canvas::importFromFile(const std::string& data){
    shapes.clear();
    std::istringstream iss(data);
    std::string line;
    while(std::getline(iss, line)){
        if(line=="Line"){
            shapes.push_back(std::make_shared<Line>());
        }
        if(line=="Circle"){
            shapes.push_back(std::make_shared<Circle>());
        }
        if(line=="Rectangle"){
            shapes.push_back(std::make_shared<Rectangle>());
        }
    }
}