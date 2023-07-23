#include "AUTH.hpp"

/**
 * @brief Constructor for the AUTH class.
 * @param first_name The first name of the user.
 * @param last_name The last name of the user.
 * @param password The password of the user.
 */
AUTH::AUTH(string first_name, string last_name, string password)
{
    this->first_name = first_name;
    this->last_name =  last_name;
    this->password = password;
}

/**
 * @brief Static member to keep track of the number of login trials.
 */
int AUTH::number_of_trials = 0;

/**
 * @brief Constant representing the maximum number of login trials allowed.
 */
const int AUTH::trial_limit = 3;

/**
 * @brief Function to register a new user in the system and store their details in a file.
 */
void AUTH::Register()
{
    file FileName;
    FileName.open("auth.txt",ios::app);
    FileName << first_name + last_name + password << "\n";
    FileName.close();
}

/**
 * @brief Function to log out a user and delete their details from the file.
 * @param filename The name of the file containing user details.
 * @param detailToDelete The details of the user to be deleted.
 */
void AUTH::Logout(string filename, string detailToDelete)
{
    ifstream oldFile;
    oldFile.open("auth.txt",ios::out);
    string details = first_name + last_name + password;

    // loop through the file and find a line containing details
    string line;
    ofstream newFile("newFile.txt"); // create a temporary file
    while (getline(oldFile, line))
    {
        if (line != detailToDelete)
        {
            newFile << line << endl;
        }
    }
    oldFile.close();
    newFile.close();

    // delete old file
    remove(filename.c_str());

    // rename the file 
    rename("newFile.txt",filename.c_str());    
}

/**
 * @brief Function to check if a user's login details match those stored in the file.
 * @return True if login is successful, otherwise false.
 */
bool AUTH::Login()
{
    string details = this->first_name + this->last_name + this->password;

    ifstream db("auth.txt");

    string line;
    while (getline(db,line))
    {
        if (line == details)
        {
            return true;
        }
    }
    ++number_of_trials;
    return false;
}

/**
 * @brief Destructor for the AUTH class.
 */
AUTH::~AUTH()
{

}
