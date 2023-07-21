#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <vector>
using namespace std;

class PRODUCT
{
private:
    
    float price = 0 ;
    string name;
    string desc;
    string category;
    int quantity;
  
public:
  PRODUCT(string name, string desc, float price ,int quantity);
    ~PRODUCT();

 inline const int getPrice(){ return price; }
static inline vector<PRODUCT> products;

 static void addToProducts(string name, string description, float price, int quantity);

 inline const string getname(){return name;}
 inline const string getdesc(){return desc;}
 inline const int getquantity(){return quantity;}
 inline const float getprice(){return price;}
 
};




#endif /* PRODUCT_H*/
