/**** 2. Question: Modifying a Configuration Setting via Pointer?
You are working on a device with configurable settings, and you need to write a function that modifies the configuration setting via a pointer. The setting is an integer value. ***/

#include <iostream>

void updateSetting(int* setting, int newValue) {
    *setting = newValue;
}

int main(){
    int configSetting = 5;
    std::cout << "Initial Setting" << configSetting << std::endl;

    updateSetting(&configSetting, 10);
    std::cout << "Setting Updated" << configSetting << std::endl;

    return 0;
}