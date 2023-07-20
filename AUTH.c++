#include "AUTH.hpp"



AUTH::AUTH(string first_name, string last_name, string password)
{
    this->first_name = first_name;
    this->last_name =  last_name;
    this->password = password;
}

int AUTH::number_of_trials = 0;
const int AUTH::trial_limit = 3;
void AUTH::Register()
{
    file FileName;
    FileName.open("auth.txt",ios::app);
    FileName << first_name + last_name + password << "\n";
    FileName.close();
}
void AUTH::Logout(string filename, string detailToDelete){
    ifstream oldFile;
    oldFile.open("auth.txt",ios::out);
    string details = first_name + last_name + password;

    // loop through the file and find a line containing details

    string line;
    ofstream newFile("newFile.txt"); // create a temporary file
     
  

    while (getline(oldFile, line));
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

bool AUTH::Login(){

    string details = this->first_name + this->last_name + this->password;

    ifstream db("auth.txt");

    string line;
    while (getline(db,line))
    {
        if (line == details){

            return true;
        }
    }
    ++number_of_trials;
    return false;
}

AUTH::~AUTH()
{

}
