/**

    @file CUSTOMER.h
    @brief Header file for the CUSTOMER class, representing a customer with shopping-related functionalities.
    */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include <iostream>
#include "PRODUCT.hpp"
#include <string>
using namespace std;



/**

    @class CUSTOMER
    @brief Class representing a customer with shopping-related functionalities. The CUSTOMER class provides functionalities for customers, including buying products, managing the shopping cart,creating an account, logging in and out, etc.
    */
class CUSTOMER 
{
    public:

    /*

    @brief Constructor for the CUSTOMER class.
    @param first_name The first name of the customer.
    @param last_name The last name of the customer.
    @param password The password for the customer's account.
    */
    CUSTOMER(string first_name, string last_name, string password);
      
      /**
    @brief Function for customers to buy products.
    */
    void buy();

    /**
    @brief Function for customers to select a product to add to their shopping cart.
    @param item The product to be added to the shopping cart.
    */
    void selectItem(PRODUCT item);


/**

    @brief Function for customers to remove a product from their shopping cart.
    @param _position The position of the product in the shopping cart.
    */
    void removeFromCart(int _position);

/**
    @brief Function for customers to create a new account.
    */
    void createAccount();


/**
    @brief Function for customers to log in to their account.
    @param first_name The first name of the customer.
    @param last_name The last name of the customer.
    @param password The password for the customer's account.
    @return true if login is successful, false otherwise.
    */
    bool login(string first_name, string last_name, string password);

/**
    @brief Function for customers to log out of their account.
    */
    void logout();


    private:
    string id;
    string first_name;
    string last_name;
    string password;  
};

#endif