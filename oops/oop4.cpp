/**
Implement a C++ program using OOP that simulates a simple ATM machine. The ATM machine should have functionalities like checking balance, withdrawing money, and depositing money. Use appropriate OOP concepts to design the ATM system.
 */

#include <iostream>
#include <string>
using namespace std;

class BankAccount{
protected:
    string accountHolderName;
    double balance;

public:
    BankAccount(string name, double initialBalance) : accountHolderName(name), balance(initialBalance) {}

    virtual void checkBalance(){
        cout << "Current balance: $" << balance << endl;
    }

    virtual void deposit(double amount){
        balance += amount;
        cout << "Deposited: $" << amount << ". New balance: $" << balance << endl;
    }

    virtual void withdraw(double amount){
        if(amount <= balance){
            balance -= amount;
            cout << "Withdraw: $" << amount << ". New balance: $" << balance << endl;
        }else{
            cout << "Insufficient funds for withdrawal!" << endl;
        }
    }
};

class ATM : public BankAccount{
public:
    ATM(string name, double initialBalance) : BankAccount(name, initialBalance) {}

    void showMenu(){
        cout << "\nATM Menu: \n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. withdraw Money\n";
        cout << "4. Exit\n";
    }

    void performTransaction(int choice){
        double amount;
        switch (choice)
        {
        case 1:
            checkBalance();
            break;
        case 2:
            cout << "Enter deposit amount: $";
            cin >> amount;
            deposit(amount);
            break;
        case 3:
            cout << "Enter withdrawl amount: $";
            cin >> amount;
            withdraw(amount);
            break;
        case 4:
            cout << "Thank you for using ATM\n";
            break;
        
        default:
            cout << "Invalid option. please try again.\n";
        }
    }
};

int main(){
    string name;
    double initialBalance;

    cout << "Enter account holder name: ";
    getline(cin, name);
    cout << "Enter initial balance: $";
    cin >> initialBalance;

    ATM atm(name, initialBalance);
    int choice;

    do{
        atm.showMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        atm.performTransaction(choice);
    }while(choice != 4);

    return 0;
}