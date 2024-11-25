/**
4. Question: Using Pointers to Update Configuration Values in an HMI System ?
Consider a scenario in an HMI system where configuration parameters (e.g., brightness, volume) are stored in a structure. Write a program to update the configuration values using pointers.
 ***/

#include <iostream>
using namespace std;

struct Config{
    int brightness;
     int volume;
};

void updateConfig(Config *config, int newBrightness, int newVolume){
    config->brightness = newBrightness;
    config->volume = newVolume;
}

int main(){
    Config config = {50, 75};

    cout << "Initial setting: Brightness = " << config.brightness << ", volume = " << config.volume << endl;

    updateConfig(&config, 80, 60);

    cout << "Updated setting: Brightness = " << config.brightness << ", volume = " << config.volume << endl;

    return 0;
}