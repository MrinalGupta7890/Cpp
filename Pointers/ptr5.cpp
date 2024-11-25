/***
5. Question: Implementing a Circular Buffer Using Pointers ?
A circular buffer is often used in embedded systems to manage sensor data streams. Write a simple implementation using pointers to manage the buffer.
**/

#include <iostream>

class CircularBuffer {
private:
    int* buffer;
    int size;
    int head;
    int tail;

public:
    CircularBuffer(int size) : size(size), head(0), tail(0) {
        buffer = new int[size];
    }

    ~CircularBuffer(){
        delete[] buffer;
    }

    void addData(int data) {
        buffer[head] = data;
        head = (head + 1) % size;
        if(head == tail){
            tail = (tail + 1) % size;
        }
    }

    void displayBuffer() {
        int i = tail;
        while(i != head) {
            std::cout << buffer[i] << " ";
            i = (i + 1) % size;
        }
        std::cout << std::endl;
    }
};

int main() {
    CircularBuffer cb(5);

    cb.addData(10);
    cb.addData(20);
    cb.addData(30);
    cb.addData(40);
    cb.addData(50);
    cb.addData(60);

    std::cout << "Buffer contents: ";
    cb.displayBuffer();

    return 0;
}