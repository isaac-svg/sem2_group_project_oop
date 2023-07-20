#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
// #include 
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




#endif /* PRODUCT_H*/
