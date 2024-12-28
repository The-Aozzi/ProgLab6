#include <iostream>
#include<map>
#include "GraphicsController.h"
#include "canvas.h"
#include "canvasView.h"
void show_icon();
void show_main_menu();
void create_canvas(GraphicsController& controller);
void import_canvas(GraphicsController& controller);
void export_canvas(GraphicsController& controller);
void add_shape(GraphicsController& controller);
void delete_shape(GraphicsController& controller);
void render_view(GraphicsController& controller);

std::map<int, std::shared_ptr<Canvas>> exported;

int main(){
    
    std::cout<<"\nWelcome to the Vector Graphics Editor\n";
    show_icon();
    auto canvas=std::make_shared<Canvas>();
    auto view = std::make_shared<CanvasView>();
    GraphicsController controller(canvas, view);

    int choice=-1;
    while(choice!=0){
        show_main_menu();
        std::cin>>choice;
        switch(choice){
            case 1: create_canvas(controller); break;
            case 2: import_canvas(controller);break;
            case 3: export_canvas(controller);break;
            case 4: add_shape(controller); break;
            case 5: delete_shape(controller); break;
            case 6: render_view(controller); break;
            case 0: 
            std::cout<<"Exit is completed"; 
            break;
            default:
            std::cout<<"Incorrect choice. Try again.\n";
        }
    }
    /*
    controller.createNewCanvas();
    controller.addShape(std::make_shared<Line>());
    controller.addShape(std::make_shared<Circle>());
    controller.addShape(std::make_shared<Rectangle>());
    controller.renderView();
    controller.exportCanvas();

    controller.deleteShape(0);
    controller.renderView();*/
    return 0;
}

void show_main_menu()
{
    std::cout<<"\nMenu:\n"
    << "1. Create a new canvas\n"
    << "2. Import a canvas\n"
    << "3. Export a canvas\n"
    << "4. Add shape\n"
    << "5. Delete shape\n"
    << "6. Show canvas\n"
    << "0. Exit\n"
    << "Command: ";
}

void create_canvas(GraphicsController &controller)
{
    controller.createNewCanvas();
}

void import_canvas(GraphicsController &controller)
{
    std::cout <<"Enter data for import:\n";
    int index;
    std::cin >> index;
    controller.importCanvas(exported[index]);
}

void export_canvas(GraphicsController &controller)
{
    controller.exportCanvas(exported);
}

void add_shape(GraphicsController &controller)
{
    std::cout <<"Choose shape to add on the canvas\n"
    <<"1.Line\n2.Circle\n3.Rectangle\n:";
    int choice;
    std::cin>>choice;
    if(choice==1){
        controller.addShape(std::make_shared<Line>());
    }
    else if(choice==2){
        controller.addShape(std::make_shared<Circle>());
    }
    else if(choice==3){
        controller.addShape(std::make_shared<Rectangle>());
    }
    else{
        std::cout <<"invalid choice.\n";
    }
}

void delete_shape(GraphicsController &controller)
{
    std::cout <<"Enter index:\n";
    size_t index;
    std::cin>>index;
    controller.deleteShape(index);
}

void render_view(GraphicsController &controller)
{
    controller.renderView();
}

void show_icon()
{
    std::cout << R"(
 ________________________
|.----------------------.|
||                      ||
||                      ||
||     .-"````"-.       ||
||    /  _.._    `\     ||
||   / /`    `-.   ; . .||
||   | |__  __  \   |   ||
||.-.| | e`/e`  |   |   ||
||   | |  |     |   |'--||
||   | |  '-    |   |   ||
||   |  \ --'  /|   |   ||
||   |   `;---'\|   |   ||
||   |    |     |   |   ||
||   |  .-'     |   |   ||
||'--|/`        |   |--.||
||   ;    .     ;  _.\  ||
||    `-.;_    /.-'     ||
||         ````         ||
||jgs___________________||
'------------------------'
    )" << std::endl;
}
