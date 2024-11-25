// IIIIIIII - Interface Segregation Principle (ISP) - do not force any client to implement an interface which is irrelevant to them.

// Before ISP:

#include <iostream>

class MultiFunctionDevice {
public:
    virtual void print() = 0;
    virtual void fax() = 0;
    virtual void scan() = 0;
};

class Printer : public MultiFunctionDevice {
public:
    void print() override {
        std::cout << "Printing document." << std::endl;
    }

    void fax() override {
        // Not applicable
    }

    void scan() override {
        // Not applicable
    }
};

int main() {
    Printer printer;
    printer.print();
    // printer.fax(); // Not applicable

    return 0;
}


// Explanation: - The MultiFunctionDevice interface forces Printer to implement methods it doesn’t use. This violates ISP as clients are forced to implement unused methods.

// Benefits of This Design:
// Adheres to ISP: Each class implements only the interfaces that are relevant to its functionality, avoiding unnecessary methods. This keeps the design clean and focused.

// Improved Clarity: The separation of interfaces makes it clear what functionalities each class provides, improving code readability and maintainability.

// Flexibility: This design allows for easy extension. If a new device needs to be added (e.g., a scanner), you can create a new interface (IScanner) and implement it in a relevant class without affecting existing implementations.



// After ISP:

#include <iostream>

class IPrinter {
public:
    virtual void print() = 0;
};

class IFax {
public:
    virtual void fax() = 0;
};

class MultiFunctionPrinter : public IPrinter, public IFax {
public:
    void print() override {
        std::cout << "Printing document." << std::endl;
    }

    void fax() override {
        std::cout << "Faxing document." << std::endl;
    }
};

class SimplePrinter : public IPrinter {
public:

    void print() override {
        std::cout << "Printing document." << std::endl;
    }
};

int main() {
    MultiFunctionPrinter mfp;
    SimplePrinter sp;

    mfp.print();
    mfp.fax();
    sp.print();

    return 0;
}


// Explanation: - Interfaces are divided into smaller ones. MultiFunctionPrinter implements both IPrinter and IFax, while SimplePrinter only implements IPrinter. This prevents clients from implementing unused methods, adhering to ISP.

