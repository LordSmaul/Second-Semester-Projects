#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "Text.h"

// Videogame object
// Contains three Text objects that hold the title, developer, and publisher, as well as an integer for the release year
class Videogame
{
public:
    Videogame(Text *title, Text *developer, Text *publisher, int year); // Videogame destructor
    ~Videogame(); // Videogame Destructor
    void printVideoGameDetails() const; // Prints Videogame attributes to the screen
    void printVideoGameDetailsToFile(ofstream &of) const; // Prints Videogame attributes to a file
    char *getVideoGameTitle() const; // Returns Videogame Title attribute
private:
    Text *title; // Title of video game
    Text *developer; // Developer of video game
    Text *publisher; // Publisher of video game
    int year; // Release year
};

#endif