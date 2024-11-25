/***
4. Question: Using Pointers to Interact with HMI Data Structures ?
Consider a scenario where you have a struct representing a sensor device in a system, and you need to pass its address to a function to update its status.
***/

#include <iostream>

struct Sensor{
    int id;
    std::string name;
    bool isActive;
};

void updateSensorStatus(Sensor* sensor, bool status){
    sensor->isActive = status;
}

int main(){
    Sensor sensor1 = {101, "Temprature Sensor", false};

    std::cout << "Sensor Status (Before): " << (sensor1.isActive ? "Active" : "Inactive") << std::endl;

    updateSensorStatus(&sensor1, true);

    std::cout << "Sensor Status (After): " << (sensor1.isActive ? "Active" : "Inactive") << std::endl;

    return 0;
}