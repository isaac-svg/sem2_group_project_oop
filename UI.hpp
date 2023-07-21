#ifndef UI_H
#define UI_H
#include <stddef.h>
#include <fstream>
#include <iostream>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/reader.h>
using namespace std;
class UI
{
private:
  UI(){}
  static UI *instance;
public:
    UI(const UI &obj ) =  delete; //delete default copy constructor
    static UI* getUIInstace();
    static void loadProducts();
    void loadAuthPage();


};

#endif /* UI_H */
