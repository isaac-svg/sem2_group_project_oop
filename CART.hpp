#ifndef CART_H
#define CART_H
#include <vector>
#include <stddef.h>
#include <iostream>
#include <set>

#include "PRODUCT.hpp"
using namespace std;

// making CART a singleton class since we only want to instantiate cart one
class CART
{
private:
    int totalItems;
    // use the momey beuatifier
    double totalPrice;
    static CART* instance;
    vector<PRODUCT>items;
     CART()
    {
    }
    
public:

    /**
 * @brief Deleted copy constructor to prevent copying of CART instances.
 */
    CART(const CART &obj) =  delete;

/**
 * @brief Get the singleton instance of the CART class.
 * @return A pointer to the CART instance.
 */
    static CART* getinStance();

    /**
 * @brief Add a product to the cart.
 * @param item The product to be added to the cart.
 */
    void addToCart(PRODUCT item);

    /**
 * @brief Clear the cart, removing all products.
 */
    void clearCart();

    /**
 * @brief Display the contents of the cart.
 */
    void showCart();
    /**
 * @brief Print a receipt of the cart contents.
 * @param sum The total sum of the cart.
 * @param unq A set of unique product IDs.
 * @param id An identifier for the receipt i.e the highest count.
 */
    void printReceipt(int sum,  set<string> unq, int id);

    /**
 * @brief Get the vector of products in the cart.
 * @return A vector containing the products in the cart.
 */
    vector<PRODUCT> getItems(){
        return this->items;
    }

};

#endif