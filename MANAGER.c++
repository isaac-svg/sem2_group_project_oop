#include "MANAGER.hpp"


MANAGER::MANAGER(){
        this->_id  = "",
        this->_name  = "";
        this->_position = "";
}
// ~MANAGER::MANAGER(){

// }

void MANAGER::restock()
{
      
    // Open the file for writing
    ofstream outputFile("data.txt", ios::app); 

    if (!outputFile) {
        cerr << "Error opening file. Try contacting the manager" << endl;
        return;
    }

        size_t num ;
        cout << "Enter the number of products you want to add: ";
        cout << ">> ";
        cin >> num;
        cout << "\n";

    // Get product information from the manager
        for (size_t i = 0; i < num; i++)
        {
                string name, description;
    double price;
    int quantity;

    cout << "Enter product name: ";
    
    cin >> name;
        // cin.ignore();
    cout << "Enter product price: ";
    cin >> price;


    cout << "Enter product description use - to represent spaces: ";
   cin >> description;
       
    cout << "Enter product quantity: ";
    cin >> quantity;

    // Write the data to the file with comma-separated values on the same line
    outputFile << name << ',' << price << ',' << description << ',' << quantity << '\n';

    // Close the file

        cout << "Product information saved to file." << endl;
    
        }
    outputFile.close(); 
}