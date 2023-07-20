#include <string>
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <vector>
#include <iostream>
#include "PRODUCT.hpp"
#include <string>
using namespace std;
class CUSTOMER 
{
    public:
    CUSTOMER(string first_name, string last_name, string password);
      
    void buy();

    void selectItem(PRODUCT item);

    void removeFromCart(int _position);

    void createAccount();

    bool login(string first_name, string last_name, string password);

    void logout();


    private:
    string id;
    string first_name;
    string last_name;
    string password;  
};

#endif