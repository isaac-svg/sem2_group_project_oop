/**

    @file PRODUCT.h
    @brief Header file for the PRODUCT class, representing a product with various attributes.
    */

#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <vector>
using namespace std;

/**

    @class PRODUCT
    @brief Class representing a product with various attributes.
    The PRODUCT class provides functionalities for handling product information, including its name, description, price, and quantity.
    */
class PRODUCT
{
private:
    
    float price = 0 /* The price of the product. */;
    string name;  /* The name of the product */
    string desc; /*The description for the product*/
    string category; /*The category for the product*/
    int quantity; /*The qunatity in stock */
  
public:

/**
* @brief Constructor for the PRODUCT class.
* @param name The name of the product.
* @param desc The description of the product.
* @param price The price of the product.
* @param quantity The quantity of the product.
*/
  PRODUCT(string name, string desc, float price ,int quantity);
  /**
 * @brief Destructor for the PRODUCT class.
 */
    ~PRODUCT();

/**
* @brief member function to the price
*/
 inline const int getPrice(){ return price; }

 /**
 * @brief Static vector to store all products created at runtime.
 */
static  vector<PRODUCT> products;

/**
 * @brief Function to add a new product to the products vectora t run time.
 * @param name The name of the product.
 * @param description The description of the product.
 * @param price The price of the product.
 * @param quantity The quantity of the product.
 */
 static void addToProducts(string name, string description, float price, int quantity);


/**
 * @brief Getter function to retrieve the name of the product.
 * @return The name of the product.
 */
 inline const string getname(){return name;}

 /**
 * @brief Getter function to retrieve the description of the product.
 * @return The description of the product.
 */
 inline const string getdesc(){return desc;}

 /**
 * @brief Getter function to retrieve the quantity of the product.
 * @return The quantity of the product.
 */
 inline const int getquantity(){return quantity;}

 /**
 * @brief Getter function to retrieve the price of the product.
 * @return The price of the product.
 */
 inline const float getprice(){return price;}
 
};




#endif /* PRODUCT_H*/
