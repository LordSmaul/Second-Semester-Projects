#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Text object used for the title, developer, and pubisher of the video game
// textArray c-string holds actual value, textLength holds length of textArray value
class Text
{
public:
    Text(string s); // Text constructor
    ~Text(); // Text destructor
    void displayText() const; // Displays text to screen
    char *getText() const; // Gets textArray
    int getLength() const; // Gets textLength (Unused?)
private:
    char *textArray; // c-string that holds word
    int textLength; // Length of textArray c-string
};

#endif