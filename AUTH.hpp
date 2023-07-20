
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
    void Register();
    void Logout(string filename, string detailToDelete);
    bool Login();
    static int number_of_trials;
    static const int trial_limit;
};


#endif