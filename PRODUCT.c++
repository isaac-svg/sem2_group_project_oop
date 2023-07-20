#include "PRODUCT.hpp"

PRODUCT::PRODUCT(string name, string desc, float price ,string category)
{
    this->name = name;
    this->desc =  desc;
    this->category = category;
    this->price =  price;
}

PRODUCT::~PRODUCT()
{
}