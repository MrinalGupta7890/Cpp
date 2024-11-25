#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
class Demo
{
private:
    static Demo *d1; // Static pointer to a Demo object . here we are storing the address of the object in the static pointer
    int num1;
    int num2;
 
private:
    // Private constructor
    Demo() {}
 
public:
    // Static function to get the instance of the class
    static Demo *getObj()
    {
        if (d1 == NULL)
        {
            return d1 = new Demo();
        }
        return d1;
    }
 
    // Setter to assign values to num1 and num2
    void setNum1AndNum2(int a, int b)
    {
        num1 = a;
        num2 = b;
    }
 
    // Function to add num1 and num2
    void add()
    {
        cout << num1 + num2 << endl;
    }
};
 
// Define the static member outside the class
Demo *Demo::d1 = NULL;
 
int main()
{
    // Get the instance of the singleton
    Demo *obj1 = Demo::getObj();
    Demo *obj2 = Demo::getObj();
    Demo *obj3 = Demo::getObj();
    // Output the addresses of both objects
    obj1->setNum1AndNum2(10, 20);
    obj1->add();
 
    return 0;
}
 