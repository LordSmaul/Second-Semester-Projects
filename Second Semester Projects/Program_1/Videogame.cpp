#include "Videogame.h"

// Constructor for Videogame object
// Dynamically allocates 3 Text objects, along with an int value for year, and implicitly assigns them to Videogame object
Videogame::Videogame(Text *title, Text *developer, Text *publisher, int year)
{
    this->title = title;
    this->developer = developer;
    this->publisher = publisher;
    this->year = year;
}

// Destructor for Videogame object
// Calls destructor functions for each Text object
Videogame::~Videogame()
{  
    title->~Text();
    developer->~Text();
    publisher->~Text();

    cout << "Videogame destructor: Released memory for Videogame object." << endl;
}

// Prints Videogame attributes to the screen
// Each Text object uses its displayText method to retrieve itself
void Videogame::printVideoGameDetails() const
{
    cout << "\t\tGame Title: ";
    title->displayText();
    cout << "\t\tDeveloper: ";
    developer->displayText();
    cout << "\t\tPublisher: ";
    publisher->displayText();
    cout << "\t\tYear Released: " << year << endl;
}

// Saves Videogame attributes to a file
// Each Text object uses its getText method to add itself to the file
void Videogame::printVideoGameDetailsToFile(ofstream &of) const
{
    of << title->getText() << endl;
    of << developer->getText() << endl;
    of << publisher->getText() << endl;
    of << year << endl;
}

// Returns the title attribute of Videogame object
// Used in functions that exclusively print out the title
char* Videogame::getVideoGameTitle() const { return title->getText(); }