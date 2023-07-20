#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
using namespace std;
class PRODUCT
{
private:
    
    int price = 0 ;
    string name;
    string desc;
    string category;

public:
  PRODUCT(string name, string desc, float price ,string category);
    ~PRODUCT();

 inline const int getPrice(){ return price; }

};

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


#endif /* PRODUCT_H*/
