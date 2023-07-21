#include <iostream>
#include <string>
#include <stdlib.h>
#include "AUTH.hpp"
#include "customer.hpp"
#include "CART.hpp"
#include "UI.hpp"
#include "PRODUCT.hpp"



using namespace std;

int main(int argc, char *argv[])
{

    if (argc == 1){
    UI *authPage =  UI::getUIInstace();
    authPage->loadAuthPage();
    }
    else if (argc > 1)
    {
        string firstname = argv[1];
        string lastname = argv[2];
        string password =  argv[3];

        AUTH manAuth(firstname, lastname, password);
     bool islogin =   manAuth.Login();

    if (islogin){
        cout << "Your are logedin as " << firstname << " " <<lastname<< endl;
    }
    else {
        cout << "You are not logedin";
    }

    }

    // CART *cart = CART::getinStance();
    // cart->showCart();
}