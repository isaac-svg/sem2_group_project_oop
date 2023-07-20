#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class CUSTOMER 
{
    public:
    CUSTOMER(string first_name, string last_name,string password);
      
    void buy();

    void addToCart(PRODUCT item);

    void removeFromCart(int _position);

    void createAccount();

    bool login(string first_name, string last_name, string password);

    void logout();

    void clearCart();

    void giveDiscount(float percent);

    void showCart();

    private:
    string id;
    string first_name;
    string last_name;
    string password;
    // vector<PRODUCT> cart;
    double totalAmout;
    int totalProducts;   
};

#endif