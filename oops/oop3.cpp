/**
Design an HMI application using C++ to simulate a simple system with different types of machines (e.g., Printer, Scanner, and Copier). Each machine should have common attributes like name and status, and each should have its own method to perform specific tasks.).
 */

#include <iostream>
#include <string>
using namespace std;

class Machine{
protected:
    string name;
    bool status;

public:
    Machine(string n) : name(n), status(false) {}

    virtual void turnOn(){
        status = true;
        cout << name << " is now ON." << endl;
    }

    virtual void turnOff() {
        status = false;
        cout << name << " is now OFF." << endl;
    }

    virtual void performTask() = 0;
};

class Printer : public Machine {
public:
    Printer(string n) : Machine(n) {}

    void performTask() override {
        if(status)
            cout << name << " is printing documents...." << endl;
        else
            cout << name << " is OFF. Turn it ON to print." << endl;
    }
};

class Scanner : public Machine{
public:
    Scanner(string n) : Machine(n){}

    void performTask() override{
        if(status)
            cout << name << " is scanning documents..." << endl;
        else
            cout << name << " is OFF. Turn it ON to scan." << endl;
    }
};

class Copier : public Machine {
public:
    Copier(string n) : Machine(n) {}

    void performTask() override{
        if(status)
            cout << name << " is copying documents..." << endl;
        else
            cout << name << " is OFF. Turn it ON to copy." << endl;
    }
};

int main() {
    Printer p("HP Printer");
    Scanner s("Cannon Scanner");
    Copier c("Xerox Copier");

    p.turnOn();
    s.turnOn();
    c.turnOn();

    p.performTask();
    s.performTask();
    c.performTask();

    p.turnOff();
    s.turnOff();
    c.turnOff();

    return 0;
}