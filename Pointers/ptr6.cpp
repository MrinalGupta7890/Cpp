/****
1. Question: Implement a Simple Menu Using Pointers ?
Create a simple console-based menu system for an HMI. The menu should present different options, and each option should be implemented as a separate function. Use function pointers to implement the menu options and invoke the corresponding function.
****/

#include <iostream>
using namespace std;

void option1();
void option2();
void option3();

typedef void (*MenuOption) ();

int main(){
    MenuOption menu[] = {option1, option2, option3};

    int choice;

    while(true){
        cout << "HMI Menu:\n";
        cout << "1 Option 1\n";
        cout << "2 Option 2\n";
        cout << "3 Option 3\n";
        cout << "4 Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 4) {
            cout << "Exiting Program....\n";
            break;
        }

        if(choice >= 1 && choice <= 3) {
            menu[choice - 1]();
        }else{
            cout << "Invalid choice, try again.\n";
        }
    }

    return 0;
}

void option1(){
    cout << "You selected Option 1.\n";
}

void option2(){
    cout << "You selected Option 2.\n";
}

void option3(){
    cout << "You selected Option 3.\n";
}