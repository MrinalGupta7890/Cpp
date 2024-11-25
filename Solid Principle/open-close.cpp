// OOOOOOOO - Open/Closed Principle (OCP) - Software entities (classes, modules, functions, etc.) should be open for extension, but closed for modification.
// Before OCP:


#include <iostream>
#include <vector>
#include <string>

class Shape {
public:
    std::string type;
    double radius; // For Circle
    double side;   // For Square
};

class AreaCalculator {
public:
    double calculateArea(const std::vector<Shape>& shapes) {
        double totalArea = 0;
        for (const auto& shape : shapes) {
            if (shape.type == "circle") {
                totalArea += 3.14 * shape.radius * shape.radius;
            } else if (shape.type == "square") {
                totalArea += shape.side * shape.side;
            }
        }
        return totalArea;
    }
};

int main() {
    AreaCalculator calculator;
    std::vector<Shape> shapes = {
        {"circle", 5, 0},
        {"square", 4, 0}
    };

    std::cout << "Total Area: " << calculator.calculateArea(shapes) << std::endl;

    return 0;
}


// Explanation: - The AreaCalculator class checks the shape type directly. If a new shape type is added, this class needs modification, violating OCP.





// After OCP:

#include <iostream>
#include <vector>
#include <memory>

class Shape {
public:
    virtual double area() const = 0; // Abstract method
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return 3.14 * radius * radius;
    }
};

class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    double area() const override {
        return side * side;
    }
};

class AreaCalculator {
public:
    double calculateTotalArea(const std::vector<std::shared_ptr<Shape>>& shapes) {
        double totalArea = 0;
        for (const auto& shape : shapes) {
            totalArea += shape->area();
        }
        return totalArea;
    }
};

int main() {
    AreaCalculator calculator;
    std::vector<std::shared_ptr<Shape>> shapes = {
        std::make_shared<Circle>(5),
        std::make_shared<Square>(4)
    };

    std::cout << "Total Area: " << calculator.calculateTotalArea(shapes) << std::endl;

    return 0;
}


// Explanation: - Shape is now an abstract class. Each shape implements its area calculation. The AreaCalculator can handle new shapes without modification, adhering to OCP.

