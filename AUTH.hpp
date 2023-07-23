
#ifndef AUTH_H
#define AUTH_H
#include <string>
#include <fstream>
using namespace std;
typedef fstream file;
class AUTH
{
private:
    string first_name;
    string last_name;
    string password;
public:
    AUTH(string first_name, string last_name, string password);
    ~AUTH();


/**
 * @brief Registers a new user.
 */
    void Register();

    /**
 * @brief Logs out the user by deleting specific details from a file.
 * @param filename The name of the file to perform the deletion in.
 * @param detailToDelete The detail to delete from the file (e.g., username).
 */
    void Logout(string filename, string detailToDelete);

    /**
 * @brief Attempts to log in the user.
 * @return true if login is successful, false otherwise.
 */
    bool Login();

    /**
 * @brief The number of login trials made by users.
 */
    static int number_of_trials;

    /**
 * @brief The maximum number of login trials allowed.
 */
    static const int trial_limit;
};


#endif