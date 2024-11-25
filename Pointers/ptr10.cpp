/***
5. Question: Pointer to a Pointer for Managing Multiple Data Sets ?
In an HMI system, you may need to manage multiple sensor data sets dynamically. Implement a program that uses a pointer to a pointer to manage an array of sensor data sets.
 */

#include <iostream>
using namespace std;

 int main(){
    const int NUM_SENSOR = 3;
    int *sensorData[NUM_SENSOR];

    for(int i = 0; i < NUM_SENSOR; i++){
        sensorData[i] = new int[5];
    }

    for(int i = 0; i < NUM_SENSOR; i++){
        cout << "Enter 5 reading for sensor " << i + 1 << ": " << endl;
        for(int j = 0; j < 5; j++){
            cin >> sensorData[i][j];
        }
    }

    for(int i = 0; i < NUM_SENSOR; i++){
        cout << "Sensor " << i + 1 << "readings: ";
        for(int j = 0; j < 5; j++){
            cout << sensorData[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < NUM_SENSOR; i++){
        delete[] sensorData[i];
    }

    return 0;

 }