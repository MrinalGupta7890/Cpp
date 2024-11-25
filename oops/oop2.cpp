/**
2. Question: Implementing a Slider for Adjusting HMI Parameters ?
You are tasked with implementing a slider for adjusting parameters on an HMI screen. The slider should have the following functionality:

A minimum and maximum value.
A current value that changes within the given range.
A method to simulate moving the slider.
A method to display the current state of the slider.
 **/

#include <iostream>
#include <string>

class Slider {
private:
    int minValue, maxValue, currentValue;

public:
    Slider(int min, int max, int start) : minValue(min), maxValue(max), currentValue(start){}

    void move(int value){
        if(value < minValue){
            currentValue = minValue;
        }else if(value > maxValue){
            currentValue = maxValue;
        }else{
            currentValue = value;
        }
        std::cout << "Slider moved to: " << currentValue << std::endl;
    }

    void display(){
        std::cout << "Slider range: [" << minValue << ", " << maxValue << "]" << std::endl;
        std::cout << "Current value: " << currentValue << std::endl;
    }
};

int main(){
    Slider volumeSlider(0, 100, 50);
    volumeSlider.display();

    volumeSlider.move(70);
    volumeSlider.move(120);
    volumeSlider.move(-10);

    return 0;
}