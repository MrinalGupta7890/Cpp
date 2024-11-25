/**
Design a C++ program using OOP to simulate a simple Employee Management System. The system should be able to store employee details such as name, age, and salary, and have functions to display the employee's information.
 */

#include <iostream>
#include <string>
using namespace std;

class Employee{
protected:
    string name;
    int age;
    double salary;

public:
    Employee(string n, int a, double s) : name(n), age(a), salary(s) {}

    virtual void displayEmployeeDetails(){
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Salary: " << salary << "\n";
     }
};

class FullTimeEmployee : public Employee {
public:
    FullTimeEmployee(string n, int a, double s) : Employee(n, a, s){}

    void displayEmployeeDetails() override {
        cout << "Full-Time Employee Details:\n";
        Employee::displayEmployeeDetails();
    }
};

class PartTimeEmployee : public Employee{
public:
    PartTimeEmployee(string n, int a, double s) : Employee(n, a, s){}

    void displayEmployeeDetails() override{
        cout << "Part-time Employee Details:\n";
        Employee::displayEmployeeDetails();
    }
};

int main(){
    
}
