/**

    @file UI.h
    @brief Header file for the UI class, providing user interface functionalities.
*/

#ifndef UI_H
#define UI_H
#include <stddef.h>
#include <fstream>
#include <iostream>

#include <set>
using namespace std;

/**

    @class UI
    @brief Class providing user interface functionalities.
    The UI class provides functionalities for handling user interface components, such as loading products, displaying authentication pages,
    showing the shopping cart, printing receipts, and implementing a delay in printing messages.
    */
class UI
{
private:
/**
   @brief Private constructor for the UI class to enforce singleton pattern.
    */
  UI(){}

  /**
    @brief Static pointer to UI instance to enforce singleton pattern.
    */
  static UI *instance;
public:

/**
* @brief Deleted default copy constructor to prevent duplication of UI instance.
*/
    UI(const UI &obj ) =  delete;

    /**
 * @brief Function to get the singleton instance of the UI class.
 * @return Pointer to the UI instance.
 */
    static UI* getUIInstace();

/**
 * @brief Function to load products from a data source.
 * Loads the data into  @see PRODUCT::products
 * 
 */
    static void loadProducts();

    /**
 * @brief Function to load the authentication page.
 */
    void loadAuthPage();

    /**
     * @brief function to print the cart.
    */
    void showCart();
   /**
 * @brief Function to print a message with a delay.
 * Simulates animation on the terminal
 * @param message The message to be printed.
 */
  void delayPrint(string message);

    /**
 * @brief Function to print the receipt.
 * @param sum The total sum of the purchase.
 * @param unq A set containing unique product identifiers.
 * @param id The customer's unique identifier.
 */
    void printReceipt(int sum,  set<string> unq, int id);


};

#endif /* UI_H */
