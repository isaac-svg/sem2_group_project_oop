#include <iostream>
#include <string>
#include <stdlib.h>
#include "AUTH.hpp"
#include "customer.hpp"
#include "CART.hpp"
#include "PRODUCT.hpp"
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/reader.h>


using namespace std;

int main(int argc, char *argv[])
{

    if (argc == 1){
        cout <<  "Welcome to the Shop";
        cout << "press 1  register\n";
        cout << "already have an account press 2 to login\n";


    string choice;
    cin >> choice;

    if (choice == "1")
    {
        string firstname,lastname,password;
        cout << "Enter your first name";
        cin >> firstname;
        cout<< "\n";
        cout << "Enter your last name";
        cin >> lastname;
        cout<< "\n";cout << "Enter your password";
        cin >> password;
        cout<< "\n";

    AUTH authToken(firstname,lastname,password);
    authToken.Register();
        
    }
    else if (choice == "2")
    {
        string firstname,lastname,password;
        cout << "Enter your first name";
        cin >> firstname;
        cout<< "\n";
        cout << "Enter your last name";
        cin >> lastname;
        cout<< "\n";cout << "Enter your password";
        cin >> password;
        cout<< "\n";

    AUTH authToken(firstname,lastname,password);
    bool isregistered =   authToken.Login();

    cout << isregistered<< "\n";

    // display products

    }
    }
    

// read file
ifstream file("data.json");
// json reader
Json::Reader reader;
// this will contain complete JSON data
Json::Value completeJsonData;
// reader reads the data and stores it in completeJsonData
reader.parse(file, completeJsonData);
// complete JSON data
// cout << "Complete JSON data: " << endl << completeJsonData << endl;// get the value associated with name key
cout << "Name: " << completeJsonData["item5"]["name"].asString()<< endl;
// get the value associated with grade key
// cout << "Grade: " << completeJsonData["item5"] << endl;

    
}