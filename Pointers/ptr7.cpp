/** 
2. Question: Dynamic Memory Allocation for Storing User Inputs ?
In an HMI system, you might need to dynamically allocate memory to store input strings provided by the user. Use pointers to allocate memory for a string entered by the user, store the input, and then release the memory after use.
**/

#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char *input = nullptr;
    int size;

    cout << "Enter the Maximum Number of Character you want to input: ";
    cin >> size;
    cin.ignore();

    input = new char[size + 1];

    cout << "Enter your input: ";
    cin.getline(input, size + 1);

    cout << "You entered: " << input << endl;

    delete[] input;

    return 0;

}