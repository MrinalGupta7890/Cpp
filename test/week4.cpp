#include <iostream>
#include <vector>
#include <string>

class Observer
{
public:
    virtual ~Observer() {}
    virtual void update(const std::string &diagnosticStatus) = 0;
};

class Display : public Observer
{
public:
    void update(const std::string &diagnosticStatus) override
    {
        std::cout << "Display: Diagnostic Status Changed to: " << diagnosticStatus << std::endl;
    }
};

class Logging : public Observer
{
public:
    void update(const std::string &diagnosticStatus) override
    {
        std::cout << "Logging: Recorded Diagnostic Status: " << diagnosticStatus << std::endl;
    }
};

class ExternalAlert : public Observer
{
public:
    void update(const std::string &diagnosticStatus) override
    {
        std::cout << "ExternalAlert: Alert sent with status: " << diagnosticStatus << std::endl;
    }
};

class DiagnosticManager
{
private:
    std::vector<Observer *> observers;
    std::string diagnosticStatus;
    DiagnosticManager() : diagnosticStatus("OK") {}

public:
    DiagnosticManager(const DiagnosticManager &) = delete;
    DiagnosticManager &operator=(const DiagnosticManager &) = delete;
    
    static DiagnosticManager &getInstance()
    {
        static DiagnosticManager instance;
        return instance;
    }

    void addObserver(Observer *observer)
    {
        observers.push_back(observer);
    }

    void notifyObservers()
    {
        for (Observer *observer : observers)
        {
            observer->update(diagnosticStatus);
        }
    }

    void setDiagnosticStatus(const std::string &status)
    {
        diagnosticStatus = status;
        notifyObservers();
    }

    std::string getDiagnosticStatus() const
    {
        return diagnosticStatus;
    }
};

int main()
{
    DiagnosticManager &diagManager = DiagnosticManager::getInstance();
    Display display;
    Logging logging;
    ExternalAlert externalAlert;
    diagManager.addObserver(&display);
    diagManager.addObserver(&logging);
    diagManager.addObserver(&externalAlert);
    diagManager.setDiagnosticStatus("Engine Error");
    diagManager.setDiagnosticStatus("Low Oil");
    diagManager.setDiagnosticStatus("OK");

    return 0;
}