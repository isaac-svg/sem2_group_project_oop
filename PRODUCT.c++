#include "PRODUCT.hpp"
#include <iostream>
PRODUCT::PRODUCT(string name, string desc, float price ,int quantity)
{
    this->name = name;
    this->desc =  desc;
    this->quantity = quantity;
    this->price =  price;
}
 void PRODUCT::addToProducts(string name, string description, float price, int quantity)
{
    PRODUCT newProduct(name, description, price, quantity);
    products.push_back(newProduct);
 
}

PRODUCT::~PRODUCT()
{
}