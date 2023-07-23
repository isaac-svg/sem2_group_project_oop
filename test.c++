// void load()
// {
//         // read file
// ifstream file("data.json");
// // json reader
// Json::Reader reader;
// // this will contain complete JSON data
// Json::Value completeJsonData;

// // reader reads the data and stores it in completeJsonData
// reader.parse(file, completeJsonData);

// // cout << "Name: " << completeJsonData["item5"]["name"].asString()<< endl;

//     if (completeJsonData.isObject()) {
//         cout<< Color::ITALIC<< setw(80)<<right << "These are the world best products we have for you today!!!\n\v";
//         cout <<  right<< setw(60)<< "Enjoy your shopping\n\v"<<Color::NORMAL;
//         // For objects, recursively print the key-value pairs
//         // cout << "product\tprice\tdescription\tquantity\n";
//         cout << setw(6) << Color::BG_GREEN<<"  ID |";
//         cout << setw(11) <<right <<"NAME |";
//         cout << setw(11) <<right <<"PRICE |";
//         cout << setw(41) <<right <<"DESCRIPTION |";
//         cout << setw(16) <<right <<"QUANTITY |"<< Color::BG_DEFAULT<<"\n";


//         int id = 0;
//         for (const auto& member : completeJsonData.getMemberNames()) {
            
//         string name = completeJsonData[member]["name"].asString() ;


//         string description = completeJsonData[member]["description"].asString() ;

//         float price = completeJsonData[member]["price"].asFloat();

//         int quantity = completeJsonData[member]["quantity"].asInt();

//         PRODUCT::addToProducts(name,description, price,quantity);

//         // cout << right << setfill(' ') << setw(40) << " hello\n";
//     //   cout  << setw(35) << setfill('-') <<"\n";
//     cout << setfill(' ');
//     cout<<Color::BG_DEFAULT<<"";

//     cout<< setw(6) << Color::BG_RED<<"";
//       cout  << setw(5) << left<<++id<< right<<"|";
//       cout  << setw(10)<< left<<name<<right<<"|";

//       cout << setw(10)<< left<<price<<right<<"|";

//       cout  <<  setw(40)<< left<<description << right<<"|";
//       cout  << setw(15)<< left<<quantity<< right<<"|"  << Color::BG_DEFAULT << "\n";
    
//       cout << Color::BG_DEFAULT<< "\n";


//         }

//         // 
//         cout <<Color::FG_YELLOW << Color::ITALIC<< "Add a product to cart by the ID\n";
//         cout << "Type buy to go to cart          \n";
//         cout << "--------------------------------\n" << Color::FG_DEFAULT<< Color::NORMAL;
//         string ans = "";
//         do
//         {
            
//             cout << Color::FG_GREEN <<">> "<<Color::NORMAL;
       
       
//         cin >> ans;
//         if (ans == "buy")
//             {
//             CART *cart = CART::getinStance();
//         cart->showCart();
//         break;
//             }
//         size_t ansNum =  stoi(ans);
        

//         PRODUCT itemChosen = PRODUCT::products.at(ansNum);

//         CART *cart = CART::getinStance();
//         cart->addToCart(itemChosen);
//         } while (ans != "buy");
//         // CART *cart = CART::getinStance();
//         // cart->showCart();
            
//     } 
// }



        // cout << right << setfill(' ') << setw(40) << " hello\n";
    //   cout  << setw(35) << setfill('-') <<"\n";
    