/**
Question 1: HMI for Managing a List of Users in a System (Non-Modifying & Modifying Algorithms)
Scenario: You are designing an HMI for managing a list of user data in a system. The system should allow you to:

Iterate through the users and display their details.
Find a user by ID.
Count how many users are over the age of 30.
Modify the list (e.g., replacing a user’s email address or removing users with certain criteria).
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct user {
    int id;
    string name;
    string email;
    int age;

    user(int id, const string& name, const string& email, int age) : id(id), name(name), email(email), age(age){}
};

class userManager{
private:
    vector<User> users;

public:
    void addUser (const User& user){
        users.push_back(user);
    }

    void displayUsers() const{
        for(const auto& user : users){
            cout << "ID: " << user.id << ", Name: " << user.name << ", Email: " << user.email << ", Age: " << user.age << endl;
        }
    }

    User* findUser ById(int id) {
        for(auto& user : users){
            if(user.id == id){
                return &user;
            }
        }

        return nullptr;
        
    }

    int countUsersOver30() const{
        int count = 0;
        for(const auto& user : users){
            if(user.age > 30){
                count++;
            }
        }
        return count;
    }
    bool modifyUser Email(int id, const string& newEmail){
        User* user = findUser ById(id);
        if(user){
            user->email = newEmail;
            return true;
        }
        return false;
    }

    void removeUserByAge(int ageLimit){
        users.erase(remove_if(user.begin(), users.end(), [ageLimit](const User& user){
            return user.age < ageLimit;
        }),
        users.end());
    }
};

int main() {
    userManager userManager;

    userManager.addUser(User(1, "John Doe", "john.doe@example.com", 25));
    userManager.addUser(User(2, "Alice", "alice@example.com", 28));
    userManager.addUser(User(3, "Bob", "bob@example.com", 35));
    userManager.addUser(User(4, "Charlie", "charlie@example.com", 23));
    userManager.addUser(User(5, "David Becham", "david.becham@example.com", 40));


    cout << "User List:" << endl;
    userManager.displayUsers();

    int searchId = 2;
    User* foundUser = userManager.findUser ById(searchId);
    if(foundUser){
        cout << "User Found: " << foundUser ->name << endl;
    }else{
        cout << "User with ID " << searchId << " not found." << endl;
    }

    int count = userManager.countUsersOver30();
    cout << "Number of users over 30: " << count << endl;

    userManager.removeUsersByAge(30);
    cout << "User List after removing users under age 30:" << endl;
    userManager.displayUsers();

    return 0;
};