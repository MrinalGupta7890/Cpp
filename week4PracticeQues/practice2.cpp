/**
Question 2: HMI for Sorting User Orders (Sorting, Binary Search)
Scenario:In an e-commerce application, you need to manage a list of user orders. You must implement functionality to:
Sort the orders by price.
Perform binary search to find an order by its price range.
Ensure the sort order is stable.
 */

#include <iostream>
#include <vector>
#include <algorithm>

struct Order
{
    int orderId;
    double price;
    std::string product;
};
bool compareOrders(const Order &a, const Order &b)
{
    return a.price < b.price; // Sort by price in ascending order}
    int main()
    {
        std::vector<Order> orders = {{1, 250.50, "Laptop"},
                                     {2, 150.75, "Smartphone"},
                                     {3, 50.99, "Headphones"},
                                     {4, 300.00, "Tablet"}};
        // Sorting orders by price using std::stable_sort to preserve original relative order if prices are the same    std::stable_sort(orders.begin(), orders.end(), compareOrders);

        std::cout << "Sorted Orders by Price:" << std::endl;
        for (const auto &order : orders)
        {
            std::cout << "Order ID: " << order.orderId << ", Price: $" << order.price << ", Product: " << order.product << std::endl;
        }
        // Binary search for an order within a price range using lower and upper boundsdouble targetPrice = 150.75;
        auto it = std::lower_bound(orders.begin(), orders.end(), Order{0, targetPrice, ""}, compareOrders);

        if (it != orders.end() && it->price == targetPrice)
        {
            std::cout << "\nFound order with price " << targetPrice << ": Order ID " << it->orderId << std::endl;
        }
        else
        {
            std::cout << "\nOrder with price " << targetPrice << " not found." << std::endl;
        }

        return 0;
    }
