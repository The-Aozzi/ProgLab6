#include "canvasView.h"

void CanvasView::render(const Canvas& canvas) const{
    std::string elements=canvas.exportToFile();
    std::string element="";
    std::cout<<"Canvas content:\n"+canvas.exportToFile();
    for(int i=0;i<elements.size();i++){
        if(elements[i]!='\n' && elements[i]!='\0'){
            element+=elements[i];
        }
        else{
            if(element=="Line"){
                std::cout<<"_____________________\n";
            }
            else if(element=="Circle"){
                std::cout << R"(
                ****       
              **    **     
             *        *    
            *          *   
            *          *   
             *        *    
              **    **     
                ****       
            )" << std::endl;
            }
            else if(element=="Rectangle"){
                std::cout << R"(
                ********
                *      *
                *      *
                *      *
                *      *
                ********
                )" << std::endl;

            }
            element="";
        }
    }
}