#include "PRODUCT.hpp"
#include <iostream>

// Constructor to initialize product attributes
PRODUCT::PRODUCT(string name, string desc, float price, int quantity)
{
    this->name = name;
    this->desc = desc;
    this->quantity = quantity;
    this->price = price;
}

// Function to add a new product to the products vector
void PRODUCT::addToProducts(string name, string description, float price, int quantity)
{
    PRODUCT newProduct(name, description, price, quantity);
    products.push_back(newProduct);
}

// Destructor
PRODUCT::~PRODUCT()
{
}
