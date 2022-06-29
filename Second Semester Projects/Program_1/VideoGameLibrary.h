#ifndef VIDEOGAMELIBRARY_H
#define VIDEOGAMELIBRARY_H

#include "Videogame.h"

// Videogame library object
// Contains a pointer array of Videogame objects, along with the max # of games it can hold and the current # of games it holds
class VideoGameLibrary
{
public:
    VideoGameLibrary(int maxNum); // VideoGameLibrary constructor
    ~VideoGameLibrary(); // VideoGameLibrary destructor
    void resizeVideoGameArray(); // Resizes VideoGamesArray array to hold twice the amount
    void addVideoGameToArray(); // Adds Videogame object to VideoGameLibrary array
    void removeVideoGameFromArray(); // Removes Videogame object to VideoGameLibrary array
    void displayVideoGames() const; // Prints Videogame objects to the screen
    void displayVideoGameTitles() const; // Prints Videogame Title attributes to the screen
    void saveToFile(string file) const; // Saves VideoGameLibrary to a file
    void loadVideoGamesFromFile(string file); // Reads in input from a specified file and adds it to VideoGameLibrary array
private:
    Videogame** videoGamesArray; // Pointer array of Videogame objects
    int maxGames; // Maximum number of games the library can hold
    int numGames; // Current number of games the library holds
};

#endif