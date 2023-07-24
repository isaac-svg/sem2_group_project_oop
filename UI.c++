#include "UI.hpp"
#include "PRODUCT.hpp"
#include "CART.hpp"
#include "AUTH.hpp"
#include "COLOR.h++"
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include "CASHIER.hpp"
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
    
        std::ifstream inputFile("data.txt");
        UI * ui =  UI::getUIInstace();

    if (!inputFile) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    // welcome th user
        cout<< Color::ITALIC<< setw(80)<<right << "These are the world best products we have for you today!!!\n\v";
        cout <<  right<< setw(60)<< "Enjoy your shopping\n\v"<<Color::NORMAL;
        // For objects, recursively print the key-value pairs
        // cout << "product\tprice\tdescription\tquantity\n";
        cout << setw(6) << Color::BG_GREEN<<"  ID |";
        cout << setw(11) <<right <<"NAME |";
        cout << setw(11) <<right <<"PRICE |";
        cout << setw(41) <<right <<"DESCRIPTION |";
        cout << setw(16) <<right <<"QUANTITY |"<< Color::BG_DEFAULT<<"\n";


        int id = 0;
        std::string line;
        
                while (std::getline(inputFile, line)) {
        // Use a stringstream to split the line using the comma as a delimiter
        std::stringstream ss(line);
        std::string name, description;
        double price;
        int quantity;

        std::getline(ss, name, ',');
        ss >> price;
        ss.ignore(); // Ignore the comma after the price
        std::getline(ss, description, ',');
        ss >> quantity;

        // add item to products vector
        PRODUCT::addToProducts(name,description, price,quantity);

        //  display table

        cout << setfill(' ');
    cout<<Color::BG_DEFAULT<<"";

    cout<< setw(6) << Color::BG_RED<<"";
      cout  << setw(5) << left<<++id<< right<<"|";
      cout  << setw(10)<< left<<name<<right<<"|";

      cout << setw(10)<< left<<price<<right<<"|";

      cout  <<  setw(40)<< left<<description << right<<"|";
      cout  << setw(15)<< left<<quantity<< right<<"|"  << Color::BG_DEFAULT << "\n";
    
      cout << Color::BG_DEFAULT<< "\n";
        
    }


        inputFile.close();

        // 
        cout <<Color::FG_YELLOW << Color::ITALIC<< "Add a product to cart by the ID\n";
        cout << "Type buy to go to cart          \n";
        cout << "--------------------------------\n" << Color::FG_DEFAULT<< Color::NORMAL;

        string ans = "";
       try
       {
         do
        {
            
            cout << Color::FG_GREEN <<">> "<<Color::NORMAL;
       
       
        cin >> ans;
        if (ans == "buy")
        {
            CART *cart = CART::getinStance();
        cart->showCart();
        break;
        }
        size_t ansNum =  stoi(ans);
        

        PRODUCT itemChosen = PRODUCT::products.at(ansNum);

        CART *cart = CART::getinStance();
        cart->addToCart(itemChosen);
        } while (ans != "buy");
       }
       catch(invalid_argument& e){
        
        ui->delayPrint("Invalid Input !!!!\n");
         cerr << "Invalid input\n" ;
        ui->loadProducts();
       
       }
       catch(const std::out_of_range& e){
        ui->delayPrint("Please we dont have a product with that id please check you input \n");
        cerr << "check the product ids\n" ;

        ui->loadProducts();
        
       }
       catch(const std::exception& e)
       {
        std::cerr << e.what() << '\n';
        ui->loadAuthPage();
       }
       catch(...){

        ui->delayPrint("Unknown error please contact the administrator!!!!!\n");
        cerr << "Unknown error please contact the administrator\n";
       }
       
}

void UI::loadAuthPage()
{       
    
            UI *ui =  UI::getUIInstace();
    
        cout << "\v\v\v"<<endl;
        // cout << Color::BG_BLUE << Color::FG_RED;
        cout <<  right << setw(40)<< Color::FG_RED << Color::BOLD  ; this->delayPrint("Welcome to Amazona\n\n");
        cout << right << setw(25) << Color::FG_RED<< Color::BOLD; this->delayPrint("Press 1 to register an account with us\n\n");
        cout << right << setw(25) <<  Color::FG_RED << Color::BOLD <<"Already have an account?  Press 2 to login\n\n"<< Color::FG_DEFAULT << Color::NORMAL <<Color::BG_DEFAULT;
        cout<<endl;
    

    string choice;
    cout << Color::FG_GREEN << ">> ";
    cin >> choice;
    cout << Color::FG_DEFAULT << "\n";
    if (choice == "1")
    {
        string firstname,lastname,password;
        cout << right << setw(40) <<Color::ITALIC<< Color::FG_YELLOW<<"Enter your first name: "  << Color::FG_DEFAULT;
        cout<< Color::FG_WHITE;
        cin >> firstname;
        cout <<  Color::FG_DEFAULT;
        cout<< "\n";
        cout << right << setw(40) << Color::FG_YELLOW<< "Enter your last name: "  << Color::FG_DEFAULT;
        cout << Color::FG_WHITE;
        cin >> lastname;
        cout << Color::FG_DEFAULT;
        cout<< "\n";
        cout << right << setw(40) << Color::FG_YELLOW<< "Enter your password: ";
        cout<< Color::FG_WHITE;
        cin >> password;
        cout << Color::FG_DEFAULT;
        cout << "\n" << Color::FG_DEFAULT<<Color::NORMAL;

                AUTH authToken(firstname, lastname, password);
                authToken.Register();
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
            
            cout << Color::FG_RED<< "Credentials incorrect \n";
            cout << "You have < "<<Color::FG_MAGENTA<< (authToken.trial_limit - authToken.number_of_trials)<< " >" <<Color::FG_RED << "trials left\n" << Color::FG_DEFAULT;

        } while ((AUTH::trial_limit > AUTH::number_of_trials) && !isLoggedIn);
        
        if (isLoggedIn)
        {
            ui->loadProducts();
        }
        if (!isLoggedIn)
        {
            
        string firstname,lastname,password;
        ui->delayPrint("It seems you are finding problems logging in\n") ;
       ui->delayPrint("Please sign up again\n");

        cout << "Enter your first name";
        cin >> firstname;
        cout<< "\n";
        cout << "Enter your last name";
        cin >> lastname;
        cout<< "\n";cout << "Enter your password";
        cin >> password;
        cout<< "\n";

        
        // display products
        ui->loadProducts();

        }

    }
}

void UI::printReceipt(int sum,  set<string> unq, int id)
{
    
    cout<< "\v";
  cout << right << setw(20)<< Color::BOLD<<Color::FG_LIGHT_BLUE;
    this->delayPrint("THANKS FOR SHOPPING WITH US!!\n");
  cout << right << setw(20);
    this->delayPrint("THIS IS YOUR RECEIPT OF PURCHASE\n");
    cout << Color::FG_DEFAULT;
    
            for (auto &&i : unq)
            {
                cout << right << setw(20)<< Color::FG_YELLOW;

                this->delayPrint(i);
                cout <<"\n";
                cout << Color::FG_DEFAULT;
            }
            cout << right << setw(20)<< "Number of items bought: " << id<< "\n";
            cout << right << setw(20)<< "Total cost for your purchase is: " << sum<< "\n";
            cout << Color::FG_DEFAULT;
            // write to statistics file
            CASHIER::writeStat(id, sum);

            string choice;
            this->delayPrint("Do you want to continue the shopping (Y/N)\n");
            cout << ">> ";
            cin >> choice ;
            cout << "\n";

            if (choice ==  "Y" || choice == "y")
            {
                this->delayPrint("We are redirecting to the home page\n");
                this->loadProducts();
            }
            else {
                this->delayPrint(" :( Thanks for shopping with us see you soon!!!\n");
                return;
            }

}

void UI::showCart()
{
        CART *readyCart =  CART::getinStance();
   vector<PRODUCT>cartItems  = readyCart->getItems();
   UI *ui =  UI::getUIInstace();

        cout << "\v\v";
        cout << setw(20);
        cout << Color::FG_MAGENTA<< Color::BOLD;
        this->delayPrint("THIS IS A SUMMARY OF YOU CART\n\n");
        cout << Color::FG_DEFAULT<< Color::NORMAL;
        cout << setw(6) << Color::BG_GREEN<<"  ID |";
        cout << setw(11) <<right <<"NAME |";
        cout << setw(11) <<right <<"PRICE |" <<
        Color::BG_DEFAULT<<"\n";
    int id = 0;
    int sum = 0;
    set<string> unq;
   for (auto &&itm : cartItems)
   {
   
   sum += itm.getPrice();
    cout << setfill(' ');
    cout<<Color::BG_DEFAULT<<"";

    cout<< setw(6) << Color::BG_RED<<"";
      cout  << setw(5) << left<<++id<< right<<"|";
      cout  << setw(10)<< left<<itm.getname()<<right<<"|";

    unq.insert(itm.getname());

      cout << setw(10)<< left<<itm.getPrice()<<right<<"|"
       << Color::BG_DEFAULT << "\n";
    
      cout << Color::BG_DEFAULT<< "\n";

   }
   cout << "\v";
   cout << "Total  Items: "<< id << "\n";
   cout << "Total Price: "<< sum<<"\n";

   string choice;

   this->delayPrint("Do yo want to buy these products? (Y/N) \n");
   cout << Color::FG_GREEN << ">> "<< Color::FG_DEFAULT;
   cin >> choice;
   cout << "\n";

   if (choice == "Y" || choice == "y"){
    ui->printReceipt(sum, unq, id);
   }
   else
   {
    cout << "We are redirection you to the main page\n";
    this->delayPrint("press X to leave the shop or any other key to continue shopping\n");
    cout << Color::FG_GREEN<< ">> " << Color::FG_DEFAULT;
    cin >> choice;
    cout << "\n";
    if (choice == "X" || choice == "x")
            return;
    UI *newUI =  UI::getUIInstace();
    newUI->loadProducts();
   }
}




 void UI::delayPrint(string message)
 {
        for (char c : message) {
        cout << c;
        fflush(stdout);
        this_thread::sleep_for(chrono::milliseconds(60)); // 60-millisecond delay
    }
 }