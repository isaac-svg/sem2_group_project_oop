#include "UI.hpp"
#include "PRODUCT.hpp"
#include "CART.hpp"
#include "AUTH.hpp"
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
          cout <<  "Welcome to the Shop";
        cout << "press 1  register\n";
        cout << "already have an account press 2 to login\n";

    // UI * uiState = UI::getUIInstace();
    // uiState->loadProducts();
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

                UI *ui =  UI::getUIInstace();
                ui->loadProducts();
        
    }
    else if (choice == "2")
    {
        bool isLoggedIn = false;
        do
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