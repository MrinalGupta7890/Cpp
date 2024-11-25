/**
Assignment Task 3: Event Handling System using the Observer Pattern
Objective:
Design an Event Handling System where multiple listeners (subscribers) can subscribe to specific events (e.g., button clicks, sensor triggers). When an event occurs, all subscribers should be notified.

Observer Pattern should be used to decouple the event source from the event listeners.

Implement event handling using C++11 features such as std::shared_ptr, lambdas, and std::function.

Requirements:
Define an Event class to represent different types of events.
Implement a Publisher class that generates events and notifies listeners.
Create Listeners that will handle different types of events.
Use std::function to allow dynamic event handling with lambdas.
Demonstrate subscribing to events and notifying listeners when events occur.
 */




#include <iostream>
#include <memory>
#include <vector>
#include <functional>
#include <string>

// Step 1: Define Event Class
class Event {
public:
    std::string name;

    Event(const std::string& eventName) : name(eventName) {}
};

// Step 2: Define Observer Interface
class IListener {
public:
    virtual ~IListener() = default;
    virtual void onEvent(const Event& event) = 0;
};

// Step 3: Define Publisher (Event Source)
class Publisher {
private:
    std::vector<std::function<void(const Event&)>> listeners;

public:
    // Subscribe a listener to the event
    void subscribe(std::function<void(const Event&)> listener) {
        listeners.push_back(listener);
    }

    // Notify all listeners about an event
    void notify(const Event& event) {
        for (const auto& listener : listeners) {
            listener(event);
        }
    }
};

// Step 4: Define Concrete Listeners
class ButtonClickListener : public IListener {
public:
    void onEvent(const Event& event) override {
        std::cout << "Button Clicked! Event: " << event.name << std::endl;
    }
};

class SensorTriggerListener : public IListener {
public:
    void onEvent(const Event& event) override {
        std::cout << "Sensor Triggered! Event: " << event.name << std::endl;
    }
};

// Step 5: Main function to demonstrate the event system
int main() {
    // Create a Publisher instance
    Publisher publisher;

    // Create listener instances
    auto buttonListener = std::make_shared<ButtonClickListener>();
    auto sensorListener = std::make_shared<SensorTriggerListener>();

    // Subscribe listeners to the publisher
    publisher.subscribe([buttonListener](const Event& event) {
        buttonListener->onEvent(event);
    });
    publisher.subscribe([sensorListener](const Event& event) {
        sensorListener->onEvent(event);
    });

    // Trigger some events
    Event buttonClickEvent("ButtonClick");
    Event sensorEvent("SensorTriggered");

    // Notify all listeners
    publisher.notify(buttonClickEvent);
    publisher.notify(sensorEvent);

    return 0;
}
