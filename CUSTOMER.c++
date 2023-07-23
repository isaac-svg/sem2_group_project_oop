#include "customer.hpp"
#include "AUTH.hpp"
#include "CART.hpp"
#include "PRODUCT.hpp"
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

// Constructor to initialize customer information
CUSTOMER::CUSTOMER(string first_name, string last_name, string password)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->password = password;
}

// Function to perform the purchase
void CUSTOMER::buy()
{
    // Implementation of purchase functionality can be added here
    // Currently, it is left empty as it will depend on specific requirements
}

// Function to select an item and add it to the cart
void CUSTOMER::selectItem(PRODUCT item)
{
    CART *cart = CART::getinStance();
    cart->addToCart(item);
}

// Function to remove an item from the cart (not implemented in current code)
void CUSTOMER::removeFromCart(int _position)
{
    // Implementation of removing items from the cart can be added here
    // Currently, it is left empty as it will depend on specific requirements
}

// Function to create a customer account and register in the authentication system
void CUSTOMER::createAccount()
{
    AUTH newCustomer(this->first_name, this->last_name, this->password);
    newCustomer.Register();
}

// Function to handle customer login using authentication credentials
bool CUSTOMER::login(string first_name, string last_name, string password)
{
    // Create an authentication token using provided credentials
    AUTH authToken(first_name, last_name, password);
    bool isloggedin = authToken.Login();

    if (!isloggedin)
    {
        cout << "Incorrect credentials. You have " << authToken.trial_limit - authToken.number_of_trials << " attempts left.\n";
        return false;
    }

    return true;
}

// Function to handle customer logout and remove authentication details
void CUSTOMER::logout()
{
    string details = this->first_name + this->last_name + this->password;
    AUTH authToken(this->first_name, this->last_name, this->password);
    authToken.Logout("auth.txt", details);
}
