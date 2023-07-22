#include "UI.hpp"
#include "PRODUCT.hpp"
#include "CART.hpp"
#include "AUTH.hpp"
#include "COLOR.h++"
#include <stdlib.h>
#include <iostream>
#include <iomanip>
// #inc<lude<c++/11/algorithm>
using namespace std;
UI* UI::instance = NULL;

UI* UI::getUIInstace()
{
    if (instance ==  NULL)
    {
        instance = new UI();
        return instance;
    }
    else{
        return instance;
    }
    
}

void UI::loadProducts()
{
    // read file
ifstream file("data.json");
// json reader
Json::Reader reader;
// this will contain complete JSON data
Json::Value completeJsonData;

// reader reads the data and stores it in completeJsonData
reader.parse(file, completeJsonData);

// cout << "Name: " << completeJsonData["item5"]["name"].asString()<< endl;

    if (completeJsonData.isObject()) {
        cout<< right<< setw(40)<< "These are the world best products we have for you today!!!\n\v";
        cout <<  right<< setw(40)<< "Enjoy your shopping\n\v";
        // For objects, recursively print the key-value pairs
        // cout << "product\tprice\tdescription\tquantity\n";
        cout << setw(5) << "Name |\t";
        cout << setw(5) << "price |\t";
        cout << setw(20) << "description |\t";
        cout << setw(5) << "quantity |\t\n";



        for (const auto& member : completeJsonData.getMemberNames()) {
            
        string name = completeJsonData[member]["name"].asString() ;


        string description = completeJsonData[member]["description"].asString() ;

        float price = completeJsonData[member]["price"].asFloat();

        int quantity = completeJsonData[member]["quantity"].asInt();

        PRODUCT::addToProducts(name,description, price,quantity);

        // cout << right << setfill(' ') << setw(40) << " hello\n";
    //   cout  << setw(35) << setfill('-') <<"\n";
      cout  << setw(5)<< name  <<"|\t";

      cout << setw(5)<< price  <<"|\t";

      cout  <<  setw(20)<< description  <<"\t";
      cout  << setw(5)<< quantity  <<"\n\t";

    //   cout  << "---------------------------\n";

        }

        // 
        string ans = "";
        do
        {
            cout << "choose product to add to cart \n ";
        cout << "choose by number "<< endl;
       
        cin >> ans;
        if (ans == "buy")
            {
            cout << "I am great\n ";
                break;
            }
        size_t ansNum =  stoi(ans);
        cout << ans << "\n";

        PRODUCT itemChosen = PRODUCT::products.at(ansNum);
        // for (auto &pr : PRODUCT::products)
        // {
        //     cout << pr.getdesc() << "\n";
        // }

        CART *cart = CART::getinStance();
        cart->addToCart(itemChosen);
        } while (ans != "buy");
        CART *cart = CART::getinStance();
        cart->showCart();
            
    } 

}

void UI::loadAuthPage()
{       
        cout << "\v\v\v"<<endl;
        // cout << Color::BG_BLUE << Color::FG_RED;
        cout <<  right << setw(40)<< Color::FG_RED << Color::BOLD  << "Welcome to Amazona\n\n";
        cout << right << setw(40) << Color::FG_RED<< Color::BOLD<< "Press 1  register an account with us\n\n";
        cout << right << setw(40) <<  Color::FG_RED << Color::BOLD <<"Already have an account?  Press 2 to login\n\n"<< Color::FG_DEFAULT << Color::NORMAL <<Color::BG_DEFAULT;
        cout<<endl;
    // UI * uiState = UI::getUIInstace();
    // uiState->loadProducts();
    string choice;
    cin >> choice;

    if (choice == "1")
    {
        string firstname,lastname,password;
        cout << right << setw(40) << Color::FG_YELLOW<<"Enter your first name: "  << Color::FG_DEFAULT;
        cout<< Color::FG_BLUE;
        cin >> firstname;
        cout <<  Color::FG_DEFAULT;
        cout<< "\n";
        cout << right << setw(40) << Color::FG_YELLOW<< "Enter your last name: "  << Color::FG_DEFAULT;
        cout << Color::FG_BLUE;
        cin >> lastname;
        cout << Color::FG_DEFAULT;
        cout<< "\n";
        cout << right << setw(40) << Color::FG_YELLOW<< "Enter your password: ";
        cout<< Color::FG_BLUE;
        cin >> password;
        cout << Color::FG_DEFAULT;
        cout << "\n" << Color::FG_DEFAULT;

                AUTH authToken(firstname, lastname, password);
                authToken.Register();
                UI *ui =  UI::getUIInstace();
                ui->loadProducts();
        
    }
    else if (choice == "2")
    {
        bool isLoggedIn = false;
        do
        {
           string firstname,lastname,password;
        cout << Color::FG_YELLOW<<"Enter your first name: "  << Color::FG_DEFAULT;
        cout<< Color::FG_BLUE;
        cin >> firstname;
        cout <<  Color::FG_DEFAULT;
        cout<< "\n";
        cout << Color::FG_YELLOW<< "Enter your last name: "  << Color::FG_DEFAULT;
        cout<< Color::FG_BLUE;
        cin >> lastname;
        cout<< Color::FG_DEFAULT;
        cout<< "\n";
        cout << Color::FG_YELLOW<< "Enter your password: ";
        cout<< Color::FG_BLUE;
        cin >> password;
        cout << Color::FG_DEFAULT;
        cout<< "\n" << Color::FG_DEFAULT;


        AUTH authToken(firstname, lastname, password);
    

        
           isLoggedIn =  authToken.Login();
            if (isLoggedIn)
            {
                
                break;
            }
            
            cout << "Credentials incorrect \n";
            cout << "You have < "<<(authToken.trial_limit - authToken.number_of_trials) << "trials left\n";

        } while ((AUTH::trial_limit > AUTH::number_of_trials) && !isLoggedIn);
        
        if (isLoggedIn)
        {
            UI *ui =  UI::getUIInstace();
            ui->loadProducts();
        }
        if (!isLoggedIn)
        {
            
        string firstname,lastname,password;
        cout << "Please register with us\n";

        cout << "Enter your first name";
        cin >> firstname;
        cout<< "\n";
        cout << "Enter your last name";
        cin >> lastname;
        cout<< "\n";cout << "Enter your password";
        cin >> password;
        cout<< "\n";

        UI *ui =  UI::getUIInstace();
        ui->loadProducts();

        }
        // display products

    }
}