/*
    FIle Name: Program1.cpp
    Author: LordSmaul
    Last Date Edited: 2/22/2022
    Purpose: Programming Assignment 1
*/

#include "VideoGameLibrary.h"

// Function prototypes
void displayMenu();

int main()
{
    int input;
    string inputString;

    cout << "How many video games can your library hold?" << endl;
    cin >> input;

    while (!cin || input <= 0) // Checks input validity
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error! Please input a number greater than 0" << endl;
        cin >> input;
    }

    VideoGameLibrary *videoGameLibrary = new VideoGameLibrary(input);

    do
    {
        displayMenu(); // Displays menu options
        cin >> input;

        while (!cin || input < 1 || input > 6) // Checks input validity
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error! Please enter an number between 1 and 6:" << endl;
            cin >> input;
        }

        cin.ignore();

        switch (input)
        {
            case 1:
                cout << "\n\nWhat is the name of the file? (example.txt): ";
                getline(cin, inputString);
                videoGameLibrary->loadVideoGamesFromFile(inputString);
                break;
            case 2:
                cout << "\n\nWhat do you want to name the file? (example.txt): ";
                getline(cin, inputString);
                videoGameLibrary->saveToFile(inputString);
                break;
            case 3:
                videoGameLibrary->addVideoGameToArray();
                break;
            case 4:
                videoGameLibrary->removeVideoGameFromArray();
                break;
            case 5:
                videoGameLibrary->displayVideoGames();
                break;
            case 6:
                videoGameLibrary->~VideoGameLibrary();
                break;
            default:
                break;
        }
    }
    while (input != 6);

    cout << "GOODBYE!";
    return 0;
}

// Funtion that displays menu options; implemented for easier readability
void displayMenu()
{
    cout << "\nWhat would you like to do?" << endl;
    cout << "1. Load video games from file." << endl;
    cout << "2. Save video games to a file." << endl;
    cout << "3. Add a video game." << endl;
    cout << "4. Remove a video game." << endl;
    cout << "5. Display all video games." << endl;
    cout << "6. Remove ALL video games from this library and end program." << endl;
    cout << "CHOOSE 1-6: ";
}