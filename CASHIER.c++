#include "CASHIER.hpp"

/**
 * @brief Function to write cashier statistics to the "statistics.txt" file.
 * @param totalItemsbought The total number of items bought.
 * @param grossRev The gross revenue earned by the cashier.
 */
void CASHIER::writeStat(int totalItemsbought, int grossRev)
{
    fileHandler FileName;
    FileName.open("statistics.txt", ios::app);
    time_t now = time(0);
    string date = ctime(&now);
    date.pop_back(); // remove the default new line character

    // Write to the "statistics.txt" file the date, totalItemsBought, and the total price.
    FileName << "|   " << totalItemsbought << "     |" << "     " << grossRev << "  |" << date << "| \n";
    FileName.close();
}
