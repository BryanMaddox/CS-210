#include "FrequencyCounter.h"
#include <iostream>
#include <fstream>

void GroceryFrequencyCounter::addItem(const std::string& item) {
    itemFrequency[(item)]++;//increases the frequency count by 1 every time the item is encountered
}

int GroceryFrequencyCounter::getItemFrequency(const std::string& item) {
    return itemFrequency[(item)];//returns the item frequency that was counted
}

//the purpose of this method is to output item and its frequency for each item in the list
void GroceryFrequencyCounter::printAllItemFrequencies() const {
    //provides a constant reference to a pair including the item and frequency
    for (const auto& pair : itemFrequency) {
        //pair.first is the item and pair.second is the frequency
        std::cout << pair.first << " " << pair.second << std::endl;
    }
}
//the purpose of this method is to output a histogram for each item in the list
void GroceryFrequencyCounter::printHistogram() const {
    //provides a constant reference to a pair including the item and frequency
    for (const auto& pair : itemFrequency) {//
        //pair.first is the item and pair.second is the frequency represented by '*' to create the histogram
        std::cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}
//outputs the list to the save file paired as the item and its frequency
void GroceryFrequencyCounter::saveToFile(const std::string& filename) const {
    std::ofstream outfile(filename);
    for (const auto& pair : itemFrequency) {
        outfile << pair.first << " " << pair.second << std::endl;
    }
    outfile.close();
}