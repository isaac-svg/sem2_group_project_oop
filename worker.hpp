#include <string>
using namespace std;
#ifndef WORKER_H
#define WORKER_H
class WORKER 
{
    public:

    WORKER(string _id, string _name, double _salary);
    void removeWorker(string _name, string _id);
   ~WORKER();
    private:
    string _id;
    string _name;
    double _salary;
    string _position;
    static int _number_of_workers;  

};

#endif