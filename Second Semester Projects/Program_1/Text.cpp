#include "Text.h"

// Constructor for Text object
// Dynamically allocates a new c-string, copys the string argument of the constructor to it, and sets it equal to the textArray attribute
// Also sets textLength variable to length of textArray
Text::Text(string s)
{
    char *charString = new char[s.size() + 1];
    for (int i = 0; i < s.size() + 1; i++)
    {
        charString[i] = s[i];
    }
    textArray = charString;
    textLength = strlen(textArray);
}

// Destructor for Text object
Text::~Text()
{
    delete[] textArray;
    cout << "Text destructor: Released memory for TextArray." << endl;
}

// Prints textArray to the screen
void Text::displayText() const
{
    for (int i = 0; i < textLength; i++)
    {
        cout << textArray[i];
    }
    cout << endl;
}

// Accessor function that returns a pointer to the textArray attribute
// Eventually used for saving a Text attribute of a Videogame object to a file
char* Text::getText() const { return textArray; }

// Accessor function that returns the length of the textArray attribute
// Unused?
int Text::getLength() const { return textLength; }