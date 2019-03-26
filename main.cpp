
#include <iostream> //I/O
#include <fstream>	//File Input handling
#include <string> 	//String convenience

#include "LinkedList.h"	//Our LinkedList class


//Load a LinkedList from a (.txt) file
LinkedList<int> loadLinkedList(std::string fName) {
	std::ifstream file(fName);
	LinkedList<int> list;
	int num;
	std::cout << "\nAttempting to read in from file " << fName << "...";
	if (file.is_open()) { while(file >> num) list.insert(num); file.close(); }
	else std::cout << "\nError: File could not be opened.";
	return list;
}

//Main function
int main(int argc, char* argv[])
{
	std::string fileName = (argv[1]) ? argv[1] : "data.txt";
	LinkedList<int> list = loadLinkedList(fileName);
	int choice = 0;
	do {
    std::cout << "\n................................................................"
									<< "\nPlease choose one of the following commands:"
									<< "\n1- Insert"
									<< "\n2- Delete"
									<< "\n3- Find"
									<< "\n4- Print"
									<< "\n5- Exit"
									<< "\n> ";
    std::cin >> choice;
		int num = 0; //Contains I/O responses
    switch(choice) {
      case 1: //Handle Insert
        std::cout << "\nEnter a number to be inserted: \n> ";
				std::cin >> num;
				list.insert(num);
        break;
      case 2: //Handle Delete
        std::cout << "\nEnter a number to be deleted: \n> ";
				std::cin >> num;
				list.erase(num);
        break;
      case 3: //Handle Find
        std::cout << "\nEnter a number to search for: \n> ";
				std::cin >> num;
				std::cout << "\n" << num << " was " << ((list.find(num)) ? "" : "not ") << "found in the list.";
        break;
      case 4: //Handle Print
        std::cout << "\nList:  ";
				list.print();
        break;
      case 5: break; //Handle Exit
      default:
        std::cout << "\nThat option was not found. Please try again.";
        break;
    }

  } while (choice != 5);
  std::cout << "\n\nExiting...\n\n";
}
