#include "CASHIER.hpp"



void CASHIER::writeStat(int totalItemsbought, int grossRev)
{
        fileHandler FileName;
        FileName.open("statistics.txt", ios::app);
        time_t now = time(0);
         string date =  ctime(&now);
        date.pop_back(); // remove the default new line character
        // write to the statics file th date, totalItemsBought and the total price
        FileName << "|   " << totalItemsbought << "     |" << "     " << grossRev << "  |" << date <<"| \n";
        FileName.close();


}