/*** 3. Question: Dynamically Allocating Memory for a Data Buffer ?
You are creating a buffer for storing data collected from multiple sensors. Write a C++ function that dynamically allocates memory using pointers and returns the allocated buffer. ****/

#include <iostream>

float* allocateBuffer(int size){
    float* buffer = new float[size];
    return buffer;
}

void deallocateBuffer(float* buffer){
    delete[] buffer;
}

int main() {
    int bufferSize = 5;
    float* dataBuffer = allocateBuffer(bufferSize);

    for(int i = 0; i < bufferSize; i++){
        dataBuffer[i] = (i + 1) * 10.0f;
    }

    std::cout << "Data in buffer:" << std::endl;
    for(int i = 0; i < bufferSize; i++){
        std::cout << "Data[" << i << "] = " << dataBuffer[i] << std::endl;
    }

    deallocateBuffer(dataBuffer);

    return 0;
}