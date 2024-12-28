#include "GraphicsController.h"
#include <iostream>

GraphicsController::GraphicsController(const std::shared_ptr<Canvas> canv, const std::shared_ptr<CanvasView>& vw):canvas(canv), view(vw){}

void GraphicsController::createNewCanvas(){
    canvas=std::make_shared<Canvas>();
    std::cout<< "New canvas created.\n";
}

void GraphicsController::importCanvas(std::shared_ptr<Canvas> canvas_){
    canvas->importFromFile(canvas_);
    std::cout<<"Canvas imported.\n";
}

void GraphicsController::exportCanvas(std::map<int, std::shared_ptr<Canvas>>& exported) const{
    std::cout<<"Exported canvas:\n"<<canvas->exportToFile(exported);
}

void GraphicsController::addShape(const std::shared_ptr<Shape>& shape){
    canvas->addShape(shape);
    std::cout <<"Added shape.\n";
}

void GraphicsController::deleteShape(size_t index){
    canvas->removeShape(index);
    std::cout <<"Shape is deleted.\n";
}

void GraphicsController::renderView() const{
    view->render(*canvas);
}