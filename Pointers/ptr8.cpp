/****
3. Question: Using Pointers to Manipulate Data in an Array ?
Suppose we are building an HMI system where the user interacts with sensor data stored in an array. Implement a function to calculate the average of an array of sensor readings using pointers.
 */
#include <iostream>
using namespace std;

double calculateAverage(double *arr, int size){
    double sum = 0;
    for(int i = 0; i < size; i++){
        sum += *(arr + i);
    }
    return sum / size;
}

int main(){
    const int NUM_SENSOR = 5;
    double sensorData[NUM_SENSOR] = {23.5, 34.7, 45.2, 28.1, 39.6};

    double average = calculateAverage(sensorData, NUM_SENSOR);

    cout << "The average sensor reading is: " << average << endl;

    return 0;
}