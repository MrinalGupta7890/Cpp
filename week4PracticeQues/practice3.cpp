/**
Question 3: HMI for Merging and Finding Min/Max Price in Orders (Merge, Heap, Min/Max Algorithms)
Scenario:You have two different lists of orders, one from a local store and another from an online marketplace. You need to:
Merge the two lists of orders into a single list.
Find the order with the minimum and maximum price from the merged list.
 */

#include <iostream>
#include <vector>#include <algorithm>
#include <limits>

struct Order
{
    int orderId;
    double price;
    std::string product;
};
int main()
{
    std::vector<Order> localOrders = {{1, 100.99, "Laptop"},
                                      {2, 50.75, "Smartphone"}};
    std::vector<Order> onlineOrders = {{3, 300.00, "Tablet"},
                                       {4, 250.00, "Monitor"}};
    // Merging the two order listsstd::vector<Order> allOrders(localOrders.size() + onlineOrders.size());
    std::merge(localOrders.begin(), localOrders.end(), onlineOrders.begin(), onlineOrders.end(), allOrders.begin(),
               [](const Order &a, const Order &b)
               {
                   return a.price < b.price;
               });
    std::cout << "Merged Orders:" << std::endl;
    for (const auto &order : allOrders)
    {
        std::cout << "Order ID: " << order.orderId << ", Price: $" << order.price << ", Product: " << order.product << std::endl;
    }
    // Finding the minimum and maximum priced ordersauto minOrder = std::min_element(allOrders.begin(), allOrders.end(), [](const Order& a, const Order& b) {
    return a.price < b.price;
});

auto maxOrder = std::max_element(allOrders.begin(), allOrders.end(), [](const Order &a, const Order &b)
                                 { return a.price < b.price; });

std::cout << "\nMinimum Price Order: Order ID " << minOrder->orderId << ", Price: $" << minOrder->price << std::endl;
std::cout << "Maximum Price Order: Order ID " << maxOrder->orderId << ", Price: $" << maxOrder->price << std::endl;

return 0;
}
