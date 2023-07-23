# Amazona Shopping Application

## Overview
Amazona is a command-line-based shopping application that allows customers to browse, buy, and manage their shopping cart. The application is designed to provide a smooth and interactive shopping experience for users. It offers the following functionalities:

1. **User Registration and Login:**
   - Customers can register with their first name, last name, and password.
   - Registered customers can log in using their credentials.
   - Authentication is managed by the `AUTH` class and uses a file-based system to store user details.

2. **Product Listing and Browsing:**
   - The application loads product information from a data file ("data.txt") using the `PRODUCT` class.
   - Customers can browse through the list of available products, including their names, prices, descriptions, and quantities.
   - The `UI` class handles the display of product information.

3. **Adding Products to Cart:**
   - Customers can select products they want to purchase by providing the product ID.
   - The selected products are added to the shopping cart, managed by the `CART` class.
   - The `CART` class keeps track of the total number of items in the cart and the total price.

4. **Managing the Shopping Cart:**
   - Customers can view their shopping cart to see the products they have selected.
   - The `UI` class displays a summary of the cart, including the product names and prices.
   - Customers can choose to proceed with the purchase or go back to browsing products.

5. **Purchase and Receipt:**
   - Once customers decide to purchase the items in their cart, the `UI` class generates a receipt.
   - The receipt includes the list of purchased products, the total number of items bought, and the total cost.
   - The `UI` class also writes the purchase statistics to a file ("statistics.txt") using the `CASHIER` class.

6. **Manager Access:**
   - Managers can log in to the application using their first name, last name, and password.
   - Manager authentication is handled by the `AUTH` class, similar to customer login.
   - Upon successful login, managers can choose to restock the products in the shop.
   - The `MANAGER` class manages the restocking process, allowing the manager to add new products to the data file ("data.txt").

7. **User Interface Interaction:**
   - The `UI` class provides a smooth and interactive user interface.
   - It delays printing messages to create a more user-friendly experience.
   ```c++
     for (char c : message) {
        cout << c;
        fflush(stdout);
        this_thread::sleep_for(chrono::milliseconds(60)); // 60-millisecond delay
    }

   ```
   - Customers and managers interact with the application through the command-line interface.

Overall, the "Amazona" application is a simple yet effective shopping system that provides users with a convenient way to browse and buy products. It incorporates various classes to manage different functionalities, making the application modular and easy to maintain.

## Technologies Used
- C++ programming language
- Command-line interface (CLI) for user interaction
- File handling for storing user and product data
- Object-oriented programming (OOP) principles for code organization and modularity

## How to Run the Application
1. Clone the GitHub repository to your local machine.
2. Compile and build the C++ code using your preferred compiler.
3. Run the executable file from the command line to start the "Amazona" application.
4. Follow the prompts to register or log in as a customer or manager.
5. Use the provided options to browse products, add items to the cart, and complete the purchase.
6. Managers can also choose to restock the products in the shop.

## Manger Login
Replace `<firstname>`, `<lastname>`, and `<password>` with the manager's actual first name, last name, and password, respectively.

If the provided credentials match those of an existing manager, the manager will gain access to the dashboard and can perform actions like restocking the shop. If the login fails, the manager will receive appropriate feedback and can try again.

Please note that the manager's login credentials are separate from those of the regular customers. Regular customers can create accounts or log in through the user interface.

## Notes
- The application uses various C++ classes to manage different functionalities, making it easy to extend and maintain.
- Users can enjoy a smooth and interactive shopping experience through the CLI interface.
- Purchase statistics are saved to the "statistics.txt" file for later reference.

Feel free to explore and enhance the "Amazona" shopping application for your personal or educational purposes!
