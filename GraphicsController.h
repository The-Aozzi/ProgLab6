#ifndef GRAPHICS_CONTROLLER_H
#define GRAPHICS_CONTROLLER_H
#include<memory>
#include<map>
#include "canvas.h"
#include "canvasView.h"
class GraphicsController{
private:
    std::shared_ptr<Canvas> canvas;
    std::shared_ptr<CanvasView> view;
public:
    GraphicsController(const std::shared_ptr<Canvas> canv, const std::shared_ptr<CanvasView>& vw);
    void createNewCanvas();
    void importCanvas(std::shared_ptr<Canvas>);
    void exportCanvas(std::map<int, std::shared_ptr<Canvas>>&) const;
    void addShape(const std::shared_ptr<Shape>& shape);
    void deleteShape(size_t index);
    void renderView() const; 
};
#endif