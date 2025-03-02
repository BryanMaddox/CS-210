/*Bryan Maddox
 *CS 210 Project Three Corner Grocer
 *02/23/25
 *The purpose of this program is to take an input file containing a list of items 
 *and counting how many times each item occurs. The user will be prompted with a menu to choose from
 *and the options will allow the user to 1. search for a specific item, 2. get a read out of all items on the
 *list and the frequency at which they occur, 3. get a histogram showing the frequency of all items in the
 *list, 4. the user will be able to exit the program. After the program finishes the counted list will be saved
 *to the file 'frequency.dat'.
 */

#include "FrequencyCounter.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

int main() {
    GroceryFrequencyCounter frequencyCounter;

    //provides the file path of the txt file to be read
    std::ifstream infile("C:\\Users\\maddo\\source\\repos\\CS 210 Project 3 Corner Grocer\\CS210_Project_Three_Input_File.txt"); 
    std::string item;

    //checks to see if the file can be opened
    if (!infile.is_open()) {//if the file does not open
        std::cerr << "Error: There was an error opening the input file\n";//an error is output to the user
        return 1;  //a return of 1 indicates an error in opening the file
    }

    //reads the items from the file and adds them to the frequencyCounter
    while (infile >> item) {
        frequencyCounter.addItem(item);
    }
    infile.close();//closes the input file

    //loop that handles user interactions with the menu and also outputs the menu options the user sees
    int userChoice = 0;//sets userChoice to initially be 0
    while (userChoice != 4) { //the loop continues as long as the user doesn't enter 4
        std::cout << "1. Get the grocery item frequency" << std::endl;
        std::cout << "2. Print all items and their frequencies" << std::endl;
        std::cout << "3. Print a histogram for all items listed" << std::endl;
        std::cout << "4. Exit the Program" << std::endl;

        //makes sure the user's input is an integer
        while (!(std::cin >> userChoice)) {
            std::cin.clear(); //clears error flags so the user can have further inputs
            
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); /*makes sure any remaining 
            characters in the buffer are discarded to prevent input overflow*/

            std::cout << "Invalid input. Please enter a number between 1 and 4: ";
            break;
        }

        //makes sure the user's input is between 1 and 4
        while (userChoice < 1 || userChoice > 4) {
            std::cout << "Invalid option. Please choose a number between 1 and 4: ";
            break;
        }

        switch (userChoice) {
        case 1:
            //prompts the user to enter an item to search
            std::cout << "Enter the item you wish to search for: ";
            //saves the user's selection
            std::cin >> item;
            //outputs the number of times the user selected item occurs in the list
            std::cout << item << ": " << frequencyCounter.getItemFrequency(item) << std::endl;
            break;
        case 2:
            frequencyCounter.printAllItemFrequencies();//calls the method printAllItemFrequencies
            break;
        case 3:
            frequencyCounter.printHistogram();//calls the method printHistogram
            break;
        case 4:
            std::cout << "Ending the program now." << std::endl;//provides the user with an option to exit
            break;
        default:
            std::cout << "Invalid input" << std::endl;
            break;
        }
    }

    //saves the counted list to the file frequency.dat
    frequencyCounter.saveToFile("frequency.dat");

    return 0;
}