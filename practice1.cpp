#include <iostream>    // Include the iostream library for input/output operations
#include <vector>      // Include the vector container from the STL
#include <string>      // Include the string class for string manipulation

// Abstract Observer class - defines the interface for all concrete observers
class Observer
{
public:
    virtual ~Observer() {}  // Virtual destructor to allow proper cleanup of derived classes
    virtual void update(const std::string &diagnosticStatus) = 0;  // Pure virtual method for receiving updates
};

// Display class - concrete observer that handles displaying diagnostic status
class Display : public Observer
{
public:
    void update(const std::string &diagnosticStatus) override
    {
        // This method will be called when the diagnostic status changes
        std::cout << "Display: Diagnostic Status Changed to: " << diagnosticStatus << std::endl;
    }
};

// Logging class - concrete observer that handles logging the diagnostic status
class Logging : public Observer
{
public:
    void update(const std::string &diagnosticStatus) override
    {
        // Log the diagnostic status
        std::cout << "Logging: Recorded Diagnostic Status: " << diagnosticStatus << std::endl;
    }
};

// ExternalAlert class - concrete observer that sends alerts when the diagnostic status changes
class ExternalAlert : public Observer
{
public:
    void update(const std::string &diagnosticStatus) override
    {
        // Sends an external alert with the updated diagnostic status
        std::cout << "ExternalAlert: Alert sent with status: " << diagnosticStatus << std::endl;
    }
};

// DiagnosticManager class - manages the diagnostic status and notifies observers
class DiagnosticManager
{
private:
    std::vector<Observer *> observers;  // Vector to store pointers to all registered observers
    std::string diagnosticStatus;       // Holds the current diagnostic status
    DiagnosticManager() : diagnosticStatus("OK") {}  // Constructor initializes the status to "OK"

public:
    DiagnosticManager(const DiagnosticManager &) = delete;  // Delete the copy constructor to prevent copying
    DiagnosticManager &operator=(const DiagnosticManager &) = delete;  // Delete the assignment operator to prevent assignment

    // Singleton pattern: returns a reference to the unique instance of DiagnosticManager
    static DiagnosticManager &getInstance()
    {
        static DiagnosticManager instance;  // Static instance to ensure only one instance exists
        return instance;  // Return the reference to the instance
    }

    // Adds an observer to the list of observers
    void addObserver(Observer *observer)
    {
        observers.push_back(observer);  // Add the observer to the vector
    }

    // Notifies all registered observers of a status change
    void notifyObservers()
    {
        for (Observer *observer : observers)  // Iterate through all observers
        {
            observer->update(diagnosticStatus);  // Call the update method on each observer
        }
    }

    // Sets a new diagnostic status and notifies all observers
    void setDiagnosticStatus(const std::string &status)
    {
        diagnosticStatus = status;  // Update the diagnostic status
        notifyObservers();  // Notify all observers about the status change
    }

    // Returns the current diagnostic status
    std::string getDiagnosticStatus() const
    {
        return diagnosticStatus;  // Return the current status
    }
};

// Main function - entry point of the program
int main()
{
    // Get the singleton instance of the DiagnosticManager
    DiagnosticManager &diagManager = DiagnosticManager::getInstance();

    // Create instances of concrete observers
    Display display;      
    Logging logging;      
    ExternalAlert externalAlert;

    // Add the observers to the DiagnosticManager
    diagManager.addObserver(&display);     // Add Display observer
    diagManager.addObserver(&logging);     // Add Logging observer
    diagManager.addObserver(&externalAlert); // Add ExternalAlert observer

    // Change the diagnostic status to "Engine Error" and notify observers
    diagManager.setDiagnosticStatus("Engine Error");

    // Change the diagnostic status to "Low Oil" and notify observers
    diagManager.setDiagnosticStatus("Low Oil");

    // Change the diagnostic status to "OK" and notify observers
    diagManager.setDiagnosticStatus("OK");

    return 0;  // Return 0 to indicate successful execution
}
