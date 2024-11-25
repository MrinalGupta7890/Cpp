/*** 1. Question: Managing Sensor Data Using Pointers ?
You have an array of sensor data in your system, and each data point is a floating-point number. Write a C++ function that uses a pointer to calculate the average of the sensor data. ***/

#include <iostream>

float calculateAverage(float* data, int size){
    float sum  = 0.0;
    for(int i = 0 ; i < size; i++){
        sum += *(data + i);
    }
    return sum / size;
}

int main(){
    float sensorData[] = {23.4, 56.7, 78.1, 45.6, 98.7};
    int size = sizeof(sensorData) / sizeof(sensorData[0]);

    float average = calculateAverage(sensorData, size);
    std::cout << "The average sensordata is: " << average << std::endl;

    return 0;
}