/**
Question 4: HMI for Implementing Design Patterns in User Preferences (Design Patterns)
Scenario:You are working on a user preferences system for an HMI. The system must:
Use the Singleton pattern to ensure that there is only one instance of the user preferences manager.
Use the Factory pattern to create different types of user preference settings.
Use the Observer pattern to notify other components when a preference is updated.
 */

#include <iostream>
#include <vector>
#include <string> // Singleton Pattern: Ensures only one instance of UserPreferencesManagerclass
UserPreferencesManager
{
public:
    static UserPreferencesManager &getInstance()
    {
        static UserPreferencesManager instance;
        return instance;
    }
    void setPreference(const std::string &key, const std::string &value)
    {
        preferences[key] = value;
        notifyObservers(key, value);
    }
    std::string getPreference(const std::string &key)
    {
        return preferences[key];
    }
    void addObserver(class Observer * observer);

private:
    std::unordered_map<std::string, std::string> preferences;
    std::vector<class Observer *> observers;
    void notifyObservers(const std::string &key, const std::string &value);
};
// Observer Pattern: Observers listen for changes to user preferencesclass Observer {public:
virtual void update(const std::string &key, const std::string &value) = 0;
}
;
void UserPreferencesManager::addObserver(Observer *observer)
{
    observers.push_back(observer);
}
void UserPreferencesManager::notifyObservers(const std::string &key, const std::string &value)
{
    for (auto observer : observers)
    {
        observer->update(key, value);
    }
} // Concrete Observerclass UserPreferenceDisplay : public Observer {public:
void update(const std::string &key, const std::string &value) override
{
    std::cout << "User preference updated: " << key << " = " << value << std::endl;
}
}
; // Factory Pattern: Factory method to create user preference settingsclass UserPreferenceFactory {
public:
static std::shared_ptr<UserPreferencesManager> createPreferences()
{
    return std::make_shared<UserPreferencesManager>();
}
}
;

int main()
{
    auto manager = UserPreferenceFactory::createPreferences();
    UserPreferenceDisplay display;
    manager->addObserver(&display);

    manager->setPreference("theme", "dark");
    manager->setPreference("language", "English");

    return 0;
}
