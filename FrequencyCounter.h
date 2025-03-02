#pragma once

#ifndef FREQUENCY_COUNTER_H//ensures FrequencyCounter is defined
#define FREQUENCY_COUNTER_H

#include <map>
#include <string>

class GroceryFrequencyCounter {//declares the class GroceryFrequencyCounter
private:
	std::map < std::string, int > itemFrequency;

public:
	//adds an item to the GroceryFrequencyCounter.
	void addItem(const std::string& item);

	//returns the number of times an item occurs in the list
	int getItemFrequency(const std::string& item);

	//prints the frequencies of all of the items in the list
	void printAllItemFrequencies() const;

	//prints a histogram for the frequencies of all item in the list
	void printHistogram() const;

	//saves all of the item frequencies to a save file
	void saveToFile(const std::string& filename) const;
};

#endif //ends the #ifndef