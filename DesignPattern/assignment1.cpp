/**
Assignment Task: Fuel Efficiency Monitoring System using Strategy Pattern
Objective:
Design a Fuel Efficiency Monitoring System where different fuel efficiency calculation strategies are used based on driving conditions. The system should allow for the easy addition of new strategies (e.g., City Driving, Highway Driving, Combined).

Strategy Pattern should be used to define multiple fuel efficiency calculation strategies.

Implement an Observer Pattern to notify the driver (Display) when fuel efficiency is updated.

Use advanced C++ features such as smart pointers, lambda functions, and modern C++ STL (Standard Template Library).

Requirements:
Create a FuelEfficiencyManager class that manages fuel consumption data and selects the appropriate calculation strategy.

Define different Fuel Efficiency Strategies based on driving conditions:

City Driving (stop-and-go, lower efficiency)
Highway Driving (constant speed, higher efficiency)
Combined Driving (a mix of city and highway)
The system should:

Monitor the fuel consumption data.
Calculate fuel efficiency based on the current driving condition strategy.
Notify the driver via a Display subsystem when the fuel efficiency is updated.
Utilize C++11 and later features:

std::shared_ptr or std::unique_ptr for memory management.
std::function for callback mechanisms.
Use constexpr and enum class for defining driving conditions and strategy types.
The system should allow runtime switching between different strategies (e.g., when the vehicle transitions between city and highway driving).

Detailed Implementation Plan
Step 1: Define Fuel Efficiency Strategy Interface

Define an interface for the fuel efficiency strategy.

Step 2: Implement Concrete Strategy Classes

Create different fuel efficiency calculation strategies for City, Highway, and Combined driving.

Step 3: Define Observer Interface

Define an observer interface to notify subsystems like the Display when fuel efficiency is updated.

Step 4: Create the FuelEfficiencyManager Singleton

Create a Singleton class to manage the fuel efficiency data, switch strategies, and notify observers.

Step 5: Implement Concrete Observer Subsystems

Implement the Display subsystem to show fuel efficiency updates.

Step 6: Main Function

Demonstrate the functionality by creating instances of strategies, managers, and observers.
 */





#include <iostream>
#include <memory>
#include <vector>
#include <functional>
#include <mutex>
#include <string>
#include <cmath>

// Step 1: Define Fuel Efficiency Strategy Interface
class IFuelEfficiencyStrategy {
public:
    virtual ~IFuelEfficiencyStrategy() = default;
    virtual double calculateEfficiency(double fuelConsumed, double distanceTraveled) = 0;
};

// Step 2: Implement Concrete Strategy Classes

class CityDrivingStrategy : public IFuelEfficiencyStrategy {
public:
    double calculateEfficiency(double fuelConsumed, double distanceTraveled) override {
        // Formula for city driving efficiency: lower efficiency due to stop-and-go
        return (distanceTraveled / fuelConsumed) * 0.8;  // 20% less efficient in city
    }
};

class HighwayDrivingStrategy : public IFuelEfficiencyStrategy {
public:
    double calculateEfficiency(double fuelConsumed, double distanceTraveled) override {
        // Formula for highway driving efficiency: higher efficiency due to constant speed
        return (distanceTraveled / fuelConsumed) * 1.2;  // 20% more efficient on highway
    }
};

class CombinedDrivingStrategy : public IFuelEfficiencyStrategy {
public:
    double calculateEfficiency(double fuelConsumed, double distanceTraveled) override {
        // Formula for combined driving efficiency: a mix of city and highway
        return distanceTraveled / fuelConsumed;  // no adjustment, average efficiency
    }
};

// Step 3: Define Observer Interface
class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void update(double fuelEfficiency) = 0;
};

// Step 4: Create the FuelEfficiencyManager Singleton
class FuelEfficiencyManager {
private:
    std::shared_ptr<IFuelEfficiencyStrategy> strategy;
    std::vector<std::shared_ptr<IObserver>> observers;
    double currentFuelEfficiency = 0.0;
    std::mutex mtx;

    // Singleton implementation
    FuelEfficiencyManager() = default;
    FuelEfficiencyManager(const FuelEfficiencyManager&) = delete;
    FuelEfficiencyManager& operator=(const FuelEfficiencyManager&) = delete;

public:
    static FuelEfficiencyManager& getInstance() {
        static FuelEfficiencyManager instance;
        return instance;
    }

    void setStrategy(std::shared_ptr<IFuelEfficiencyStrategy> newStrategy) {
        std::lock_guard<std::mutex> lock(mtx);
        strategy = newStrategy;
    }

    void addObserver(std::shared_ptr<IObserver> observer) {
        std::lock_guard<std::mutex> lock(mtx);
        observers.push_back(observer);
    }

    void removeObserver(std::shared_ptr<IObserver> observer) {
        std::lock_guard<std::mutex> lock(mtx);
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void updateFuelEfficiency(double fuelConsumed, double distanceTraveled) {
        std::lock_guard<std::mutex> lock(mtx);
        if (strategy) {
            currentFuelEfficiency = strategy->calculateEfficiency(fuelConsumed, distanceTraveled);
            notifyObservers();
        }
    }

    void notifyObservers() {
        for (auto& observer : observers) {
            observer->update(currentFuelEfficiency);
        }
    }
};

// Step 5: Implement Concrete Observer Subsystems
class Display : public IObserver {
public:
    void update(double fuelEfficiency) override {
        std::cout << "Current Fuel Efficiency: " << fuelEfficiency << " km/l\n";
    }
};

// Step 6: Main Function
int main() {
    // Create Strategy instances
    auto cityStrategy = std::make_shared<CityDrivingStrategy>();
    auto highwayStrategy = std::make_shared<HighwayDrivingStrategy>();
    auto combinedStrategy = std::make_shared<CombinedDrivingStrategy>();

    // Get the Singleton instance of FuelEfficiencyManager
    auto& manager = FuelEfficiencyManager::getInstance();

    // Create an observer (Display) and register it with the manager
    auto display = std::make_shared<Display>();
    manager.addObserver(display);

    // Set strategy to City Driving and update fuel efficiency
    manager.setStrategy(cityStrategy);
    manager.updateFuelEfficiency(50.0, 500.0);  // 50 liters of fuel, 500 km

    // Change strategy to Highway Driving and update fuel efficiency
    manager.setStrategy(highwayStrategy);
    manager.updateFuelEfficiency(40.0, 600.0);  // 40 liters of fuel, 600 km

    // Switch to Combined Driving and update fuel efficiency
    manager.setStrategy(combinedStrategy);
    manager.updateFuelEfficiency(60.0, 700.0);  // 60 liters of fuel, 700 km

    return 0;
}
