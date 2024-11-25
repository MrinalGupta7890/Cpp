// LLLLLLL - Liskov Substitution Principle (LSP) - Derived or child classes must be substitutable for their base or parent classes.

// Before LSP:

#include <iostream>

class Bird {  //base class with a virtual method fly()
public:
    virtual void fly() {  
        std::cout << "Flying..." << std::endl;
    }
};

class Sparrow : public Bird {   // subclass that correctly overrides fly
public:
    void fly() override {
        std::cout << "Sparrow flying!" << std::endl;
    }
};

class Ostrich : public Bird {    //Another subclass that also overrides fly
public:
    void fly() override {
        throw std::runtime_error("Ostriches can't fly!");
    }
};

void letBirdFly(Bird& bird) {
    bird.fly(); // May cause an error for Ostrich
}

int main() {
    Sparrow sparrow;  // Instances
    Ostrich ostrich;

    letBirdFly(sparrow);
    // letBirdFly(ostrich); // This will throw  a runtime error because the Ostrich class violates the expected behavior of the Bird class.

    return 0;
}


// Explanation: - Ostrich cannot fly, which causes an error when using the letBirdFly function. This violates LSP, as subclasses should be substitutable for their base classes.

// To adhere to the LSP, you could redesign the class hierarchy. For instance:

// Introduce an interface or abstract class that defines flying behavior.
// Separate classes for flying and non-flying birds.




// After LSP:

#include <iostream>

class Bird {    // Base class
public:
    // Pure virtual function to enforce that all derived classes must implement makeSound
    virtual void makeSound() const = 0; // All birds can make sounds
};

class FlyingBird : public Bird {   // subclass of Bird that adds a pure virtual function fly()
public:
    virtual void fly() = 0; // Only for flying birds
};

// inherits from FlyingBird and provides implementations for both fly() and makeSound().
class Sparrow : public FlyingBird {
public:

    void fly() override {
        std::cout << "Sparrow flying!" << std::endl;
    }

    void makeSound() const override {
        std::cout << "Chirp!" << std::endl;
    }
};

// Ostrich class, a specific type of Bird that cannot fly
class Ostrich : public Bird {
public:
    // Implementation of sound-making behavior for Ostriches
    void makeSound() const override {
        std::cout << "Boom!" << std::endl;
    }
};

// Function that takes any Bird and calls its makeSound method
void letBirdSound(const Bird& bird) {
    bird.makeSound(); // Works for any Bird type, adhering to the Liskov Substitution Principle
}

int main() {
    Sparrow sparrow;   // Create a Sparrow instance
    Ostrich ostrich;   // Create an Ostrich instance

    // Call the function to let each bird make its sound
    letBirdSound(sparrow); // Output: Chirp!
    letBirdSound(ostrich); // Output: Boom!

    return 0;
}



// Explanation: - Bird now includes makeSound(), while FlyingBird has the fly() method. Ostrich does not implement fly(), allowing it to be used safely. This adheres to LSP.

