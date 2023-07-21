#include "UI.hpp"
#include "PRODUCT.hpp"
#include "CART.hpp"
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

cout << "Name: " << completeJsonData["item5"]["name"].asString()<< endl;

    if (completeJsonData.isObject()) {
        // For objects, recursively print the key-value pairs
        for (const auto& member : completeJsonData.getMemberNames()) {
            



        string name = completeJsonData[member]["name"].asString() ;


        string description = completeJsonData[member]["description"].asString() ;

        float price = completeJsonData[member]["price"].asFloat();

        int quantity = completeJsonData[member]["quantity"].asInt();

        PRODUCT::addToProducts(name,description, price,quantity);

      cout << "---------------------------\n";
      cout<<  "name :"<< completeJsonData[member]["name"].asString()  <<"\n";

      cout<<  "description :"<< completeJsonData[member]["description"].asString()  <<"\n";

      cout<<  "price :"<< completeJsonData[member]["price"].asFloat()  <<"\n";
      cout << "---------------------------\n";

        }
        cout << "choose product to add to cart \n ";
        cout << "choose by number "<< endl;
        string ans ;
        cin >> ans;
        cout << "HELLO" << "\n";
        size_t ansNum =  stoi(ans);
        cout << ans << "\n";

        PRODUCT itemChosen = PRODUCT::products.at(ansNum);
        for (auto &pr : PRODUCT::products)
        {
            cout << pr.getdesc() << "\n";
        }

        CART *newCart = CART::getinStance();
        newCart->addToCart(itemChosen);

    } 

}

void UI::loadAuthPage()
{
          cout <<  "Welcome to the Shop";
        cout << "press 1  register\n";
        cout << "already have an account press 2 to login\n";

    UI * uiState = UI::getUIInstace();
    uiState->loadProducts();
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

    // display products

    }
}