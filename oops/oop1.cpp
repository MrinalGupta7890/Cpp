/**
1. Question: Implementing a Button Class for an HMI Application ?
You need to implement a simple button class that can be displayed on an HMI screen. The button should have the following properties:

Text label (e.g., "Start", "Stop").
Position (X, Y coordinates).
Size (Width, Height).
A method to simulate a click event.
A method to display the button on the screen (just print out the button’s details).
 */

#include <iostream>
#include <string>

class Button {
private:
    std::string label;
    int x, y;
    int width, height;

public:
    Button(std::string lbl, int posX, int posY, int w, int h) : label(lbl), x(posX), y(posY), width(w), height(h) {};

    void click(){
        std::cout << "Button '" << label << "' clicked!" << std::endl;
    }

    void display(){
        std::cout << "Button: " << label << std::endl;
        std::cout << "Position: (" << x << ", " << y << ")" << std::endl;
        std::cout << "Size: " << width << "x" << height << std::endl;
    }
};

int main(){
    Button startButton("Start", 100, 150, 80, 30);
    startButton.display();
    startButton.click();
    return 0;
}