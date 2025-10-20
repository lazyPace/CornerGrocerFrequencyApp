// Brandon Prater
// CS-210 Progamming Languages / Southern New Hampshire University
// 2025-10-18
// Professor Chan

// CornerGrocerFrequencyApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include "FrequencyTracker.h"

// Read and validate menu selection input from user
static int ReadMenuSelection()
{
    using namespace std; 
    int choice;
    while (true) {
		cout << "\n===== Corner Grocer Menu =====\n";
        cout << "1. Lookup frequency of a specific item\n";
        cout << "2. Print frequency of all items\n";
        cout << "3. Print histogram of all items\n";
        cout << "4. Exit\n";
        cout << "Select an option (1-4): ";

        // Read user input and validate
        if (cin >> choice && choice >= 1 && choice <= 4) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            return choice;
        }

        // Clear invalid input and prompt user again
        cout << "Invalid selection. Please enter a number between 1 and 4.\n";
        cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    }
}


int main()
{
    try
    {
        FrequencyTracker tracker; // Create instance of FrequencyTracker class

		const std::string inputFile = "CS210_Project_Three_Input_File.txt";
        tracker.LoadFromFile(inputFile); // Load data from the input file
        tracker.WriteBackup(); // Immediately write the backup file

        // Display interactive menu
        while (true) {
            int choice = ReadMenuSelection();

            if (choice == 1) {
                // 1. Lookup frequency of a specific item
                std::cout << "Enter the item name to look up: ";
                std::string item;
                std::getline(std::cin, item);

                int count = tracker.GetCount(item);

                std::cout << item << " " << count << "\n";
            }
            else if (choice == 2) {
                // 2. Print frequency of all items
                tracker.PrintAll();
            }
            else if (choice == 3) {
				// 3. Print histogram of all items
				tracker.PrintHistogram(std::cout, '*');
            }
            else if (choice == 4) {
                // 4. Exit
                std::cout << "Goodbye!\n";
                break;
            }
        }
    }
    catch (const std::exception& ex) {
        // Catch and display any file or runtime errors
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}

