// Create a base class "Shape" with methods to calculate the area and perimeter (pure virtual). Implement derived classes "Rectangle" and "Circle" that inherit from "Shape" and provide their own area and perimeter calculations.

#include <iostream>

class Shape
{
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() const override
    {
        return length * width;
    }

    double perimeter() const override
    {
        return 2 * (length + width);
    }
};

class circle : public Shape
{
private:
    double raidus;

public:
    circle(double r) : raidus(r) {}

    double area() const override
    {
        return 3.141592653589793 * raidus * raidus;
    }

    double perimeter() const override
    {
        return 2 * 3.141592653589793 * raidus;
    }
};

int main()
{

    Shape* shape1 = new Rectangle(5, 3);
    Shape* shape2 = new circle(4);

    std::cout << "Rectangle Area: " << shape1->area() << std::endl;
    std::cout << "Rectangle perimeter: " << shape1->perimeter() << std::endl;


    std::cout << "Circle Area: " << shape2->area() << std::endl;
    std::cout << "Circle perimeter: " << shape2->perimeter() << std::endl;

    delete shape1;
    delete shape2;

    return 0;
}