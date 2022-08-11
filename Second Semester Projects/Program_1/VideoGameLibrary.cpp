#include "VideoGameLibrary.h"

// Constructor for VideoGameLibrary object
VideoGameLibrary::VideoGameLibrary(int maxNum)
{
    videoGamesArray = new Videogame*[maxNum];
    maxGames = maxNum;
    numGames = 0;
}

// Destructor for VideoGamesArray
// Calls destructor function for each Videogame object, then deletes the pointer array
VideoGameLibrary::~VideoGameLibrary()
{
    cout << "\n";
    for (int i = 0; i < numGames; i++)
    {
        videoGamesArray[i]->~Videogame();
    }
    
    delete [] videoGamesArray;

    cout << "VideoGameLibrary destructor: Released memory for each game in the video game array itself.\n" << endl;
}

// Resizes VideoGamesArray array by doubling it when maxGames == numGames
// Helper function called by addVideoGameToArray() and loadVideoGamesFromFile() functions
void VideoGameLibrary::resizeVideoGameArray()
{
    // Dynamically allocates new Videogame array with twice the space
    Videogame **resizedVideoGameArray = new Videogame*[maxGames * 2];

    for (int i = 0; i < numGames; i++)
    {
        // Copies elements of the old array into resized array
        resizedVideoGameArray[i] = videoGamesArray[i];
    }

    delete [] videoGamesArray; // Deletes obsolete pointer array

    cout << "\nResizing VideoGameArray from " << maxGames << " to " << maxGames * 2 << "\n" << endl;

    videoGamesArray = resizedVideoGameArray; // Sets Videogame array object to the newly sized array
    maxGames *= 2;                           // Permanently doubles maxGames attribute of videoGamesArray                        
}

// Adds Videogame object to the array from user input
void VideoGameLibrary::addVideoGameToArray()
{
    string t, d, p;
    int year;
    
    // Allocates Text object for title
    cout << "Video Game TITLE: ";
    getline(cin, t);
    Text *title = new Text(t);

    // Allocates Text object for developer
    cout << "Video Game DEVELOPER: ";
    getline(cin, d);
    Text *developer = new Text(d);

    // Allocates Text object for publisher
    cout << "Video Game PUBLISHER: ";
    getline(cin, p);
    Text *publisher = new Text(p);

    // Sets release year
    cout << "Video Game YEAR: ";
    cin >> year;
    cin.ignore();

    // Dynamically allocates new Videogame object to add to array
    Videogame *videogame = new Videogame(title, developer, publisher, year);

    // Resizes videoGamesArray if necessary
    if (numGames == maxGames)
    {
        resizeVideoGameArray();
    }

    videoGamesArray[numGames] = videogame; // Sets new Videogame to the next available position in the function
    numGames++;
}

// Removes user specified video game from the array and shifts video games within array into correct indeces
void VideoGameLibrary::removeVideoGameFromArray()
{
    int input;

    if (numGames == 0) // Checks that at least one Videogame object exists
    {
        cout << "There should always be at least one video game in the library." << endl;
    }
    else
    {
        cout << "Choose from the following video games to remove:\n" << endl;
        displayVideoGameTitles(); // Helper function call that prints out all titles of the Videogame objects
        cout << "Choose a video game to remove between 1 & " << numGames << ": ";
        cin >> input;

        while (!cin || input < 1 || input > numGames) // Checks input validity
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nError! Input an integer between 1 & " << numGames << ": ";
            cin >> input;
        }

        cout << "\nThe video game \"" << videoGamesArray[input - 1]->getVideoGameTitle() << "\" has been successfully deleted." << endl;

        videoGamesArray[input - 1]->~Videogame(); // Deletes specified Videogame object from the array

        // Shifts elements in videoGamesArray to account for removed Videogame object
        for (int i = input - 1; i < numGames; i++)
        {
            videoGamesArray[i] = videoGamesArray[i + 1];
        }

        numGames--;
    }
}

// Prints Videogame attributes to the screen
// Uses Videogame function printVideoGameDetails()
void VideoGameLibrary::displayVideoGames() const
{
    for (int i = 0; i < numGames; i++)
    {
        cout << "\t\t----------Video Game " << i + 1 << "----------" << endl;
        videoGamesArray[i]->printVideoGameDetails();
        cout << endl;
    }
}

// Prints video game titles to screen
// Helper funtion used in removeVideoGameFromArray() function
void VideoGameLibrary::displayVideoGameTitles() const
{
    for (int i = 0; i < numGames; i++)
    {
        cout << "Video Game " << i + 1 << ": " << videoGamesArray[i]->getVideoGameTitle() << endl;
    }
}

// Saves library to a .txt file
// Uses Videogame function printVideoGameDetailsToFile() to print each attribute to file
void VideoGameLibrary::saveToFile(string file) const
{
    ofstream of;

    of.open(file);
    for (int i = 0; i < numGames; i++)
    {
        videoGamesArray[i]->printVideoGameDetailsToFile(of);
    }
    of.close();

    cout << "All video games in your library have been saved to " << file << endl;
}

// Builds videoGamesArray object from a .txt file input
void VideoGameLibrary::loadVideoGamesFromFile(string file)
{
    ifstream ifs;
    string line;

    ifs.open(file);

    if (!ifs.is_open())
    {
        cout << "Sorry, the specified file could not be opened." << endl;
    }
    else
    {
        while (getline(ifs, line)) // Reads through every .txt file line
        {
            Text* title = new Text(line); // Allocates Text object for title
            getline(ifs, line);
            Text* developer = new Text(line); // Allocates Text object for developer
            getline(ifs, line);
            Text* publisher = new Text(line); // Allocates Text object for publisher
            getline(ifs, line);
            int year = stoi(line); // Sets release year

            // Dynamically allocates new Videogame object to add to array
            Videogame *videogame = new Videogame(title, developer, publisher, year);

            // Resizes videoGamesArray if necessary
            if (numGames == maxGames)
            {
                resizeVideoGameArray();
            }

            videoGamesArray[numGames] = videogame; // Sets new Videogame to the next available position in the function
            cout << videoGamesArray[numGames]->getVideoGameTitle() << " was added successfully" << endl;
            numGames++;
        }
        ifs.close();
        cout << "\n" << numGames << " video games were read from the file and added to your Videogame library." << endl;
    }
}
