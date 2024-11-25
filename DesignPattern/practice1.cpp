/**
Question:
Design an HMI System for a Smart Home Control Panel.

Imagine you're designing a smart home control panel (HMI) system that allows users to control various devices like lights, HVAC systems, and security cameras. The system needs to be modular, with the ability to add new devices easily in the future. The system should allow users to:

Turn devices on and off.
Adjust device settings (e.g., temperature for HVAC, brightness for lights).
Display the current state of devices.
In the context of this system, you must decide on a suitable design pattern for creating a modular and extensible HMI system. How would you implement it in C++?
 */




/*Step 1: Strategy Pattern for Device Control
The Strategy Pattern is useful for providing different behaviors for controlling devices. Each device (like lights, HVAC, or cameras) might have different control strategies. This allows us to define a family of algorithms (turning on/off, adjusting brightness, temperature) and make them interchangeable without altering the device classes.*/

#include <iostream>
#include <string>
#include <memory>

// Abstract strategy class
class DeviceControlStrategy {
public:
    virtual ~DeviceControlStrategy() = default;
    virtual void execute() = 0;  // Abstract method for device control
};

// Concrete strategy for turning a device ON
class TurnOnStrategy : public DeviceControlStrategy {
public:
    void execute() override {
        std::cout << "Device turned ON." << std::endl;
    }
};

// Concrete strategy for turning a device OFF
class TurnOffStrategy : public DeviceControlStrategy {
public:
    void execute() override {
        std::cout << "Device turned OFF." << std::endl;
    }
};

// Concrete strategy for adjusting brightness of a light
class AdjustBrightnessStrategy : public DeviceControlStrategy {
private:
    int brightness;
public:
    AdjustBrightnessStrategy(int b) : brightness(b) {}
    void execute() override {
        std::cout << "Light brightness adjusted to " << brightness << "." << std::endl;
    }
};

// Context class that uses a strategy
class Device {
private:
    std::shared_ptr<DeviceControlStrategy> controlStrategy;
public:
    void setControlStrategy(std::shared_ptr<DeviceControlStrategy> strategy) {
        controlStrategy = strategy;
    }

    void executeControl() {
        controlStrategy->execute();
    }
};


/*Step 2: Observer Pattern for Device State Updates
The Observer Pattern is suitable for scenarios where you need to notify multiple parts of the system (e.g., different HMI panels or users) whenever the state of a device changes. In this case, the device can notify the HMI system about the current state (on/off, brightness, etc.).*/


#include <vector>

// Abstract Observer class
class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void update(const std::string& state) = 0;
};

// Concrete Observer (HMI Panel)
class HMIPanel : public IObserver {
public:
    void update(const std::string& state) override {
        std::cout << "HMI Panel updated with device state: " << state << std::endl;
    }
};

// Subject (Device)
class DeviceState {
private:
    std::string state;
    std::vector<IObserver*> observers;

public:
    void addObserver(IObserver* observer) {
        observers.push_back(observer);
    }

    void removeObserver(IObserver* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void setState(const std::string& newState) {
        state = newState;
        notifyObservers();
    }

    void notifyObservers() {
        for (auto* observer : observers) {
            observer->update(state);
        }
    }
};

/*Step 3: Factory Method for Creating Devices
The Factory Method Pattern can be used to instantiate devices dynamically based on the type of device. This pattern abstracts the instantiation logic and makes it easier to add new device types in the future.
*/

#include <memory>

// Abstract Product class
class DeviceType {
public:
    virtual ~DeviceType() = default;
    virtual void interact() = 0; // Device interaction
};

// Concrete product classes
class Light : public DeviceType {
public:
    void interact() override {
        std::cout << "Interacting with Light" << std::endl;
    }
};

class HVAC : public DeviceType {
public:
    void interact() override {
        std::cout << "Interacting with HVAC system" << std::endl;
    }
};

// Abstract Factory class
class DeviceFactory {
public:
    virtual ~DeviceFactory() = default;
    virtual std::shared_ptr<DeviceType> createDevice() = 0;
};

// Concrete Factory classes
class LightFactory : public DeviceFactory {
public:
    std::shared_ptr<DeviceType> createDevice() override {
        return std::make_shared<Light>();
    }
};

class HVACFactory : public DeviceFactory {
public:
    std::shared_ptr<DeviceType> createDevice() override {
        return std::make_shared<HVAC>();
    }
};


// Main Program to Integrate All Patterns:

int main() {
    // Strategy Pattern Example
    Device light;
    light.setControlStrategy(std::make_shared<AdjustBrightnessStrategy>(75)); // Adjust brightness to 75
    light.executeControl();

    // Observer Pattern Example
    DeviceState deviceState;
    HMIPanel panel;
    deviceState.addObserver(&panel);
    deviceState.setState("ON");

    // Factory Method Pattern Example
    DeviceFactory* lightFactory = new LightFactory();
    auto lightDevice = lightFactory->createDevice();
    lightDevice->interact();

    delete lightFactory;

    return 0;
}


/**Explanation:
Strategy Pattern:
The DeviceControlStrategy class defines an interface for device control. Concrete strategies like TurnOnStrategy or AdjustBrightnessStrategy implement specific control behaviors. The Device class uses the strategy to execute the appropriate behavior.
Observer Pattern:
The DeviceState class is the subject that tracks the state of a device and notifies observers (like the HMIPanel) whenever the state changes. This allows the HMI to display the updated state dynamically.
Factory Method Pattern:
The DeviceFactory class provides an abstract interface for creating devices, allowing for easy addition of new device types in the future. Concrete factories like LightFactory and HVACFactory implement the logic for creating specific devices.
Benefits:
Modularity: New devices or control behaviors can be added without modifying existing code.
Extensibility: Additional device types or control strategies can be easily integrated into the system.
Maintainability: The code is organized into separate classes with clear responsibilities, making it easier to maintain and scale.
This design provides a robust and flexible architecture for building an HMI system for a smart home, adhering to object-oriented principles and design patterns. */



