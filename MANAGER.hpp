/**

    @file MANAGER.h
    @brief Header file for the MANAGER class, representing a manager with managerial functionalities.
    */

#ifndef MANAGER_H
#define MANAGER_H
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
typedef fstream FileHandler;

/**

    @class MANAGER

    @brief Class representing a manager with managerial functionalities.

    The MANAGER class provides functionalities for managing the workforce, including restocking items.
    */
class MANAGER 
{
    public:

    /**

    @brief Constructor for the MANAGER class.
    */
    MANAGER();
    
    /**

    @brief Function for the manager to restock items.
    */
   static void restock();
    
    private:
    string _id;
    string _name;
    double _salary;
    string _position;
    static int _number_of_workers;  

};

#endif