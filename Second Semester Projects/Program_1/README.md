# Project 1 - Video Game Library
### practice with class construction/destruction, functions, abstraction, file input/output, and code header files

This was the first programming assignment for this class and had us deal heavily on the topic of classes and functions, which was only briefly addressed in the prerequisite course. The program creates a VideoGameLibrary object, which contains multiple Videogame objects; these Videogame objects contain multiple Text objects. These Text objects essentially function the same way as strings and may seem tedious to implement, but it was done in this way to help teach us about class abstraction and functions. Each object has its own header file, which contains a class constructor for the object. The constructor contains all attributes and function prototypes; all functions are public and all attributes are private for each function. Several text files were included with the program, including a small test file with 3 videogames and a larger test file containing the instructor’s entire Steam game library.

The main function first asks the user to initialize the size of the VideoGameLibrary attribute. It then prints a menu asking the user which function they want to complete; the function runs until the user quits the program, in which all allocated memory is destructed, and the program ends. After validating the user input, the user can either: load videogame data from a specified file, save current videogame data to a file, add a videogame, remove a videogame, or display all current videogame data.

___

**Here is a breakdown of each object and their corresponding functions:**

### Text Object

The Text object functions almost identically to a string, but with some added functionality. The Text constructor takes in a string as input and reads it into a character array attribute, saving both that and the length of the string into private attributes of the object; the destructor deletes the character array and prints a message. <br />The Text object has two accessor functions (`getText()` and `getLength()`) that retrieve their respective attributes; the `getLength()` function is not used within the program. <br />The `displayText()` function prints the Text object to the terminal.

___

### Videogame Object

The Videogame object contains all the related information for a single videogame. It contains three Text objects for the title, developer name, and publisher name for the videogame, as well as an integer for the release year. <br />The constructer implicitly assigns all variables in the object, and the destructor uses the Text destructor to delete all allocated memory for each object. <br />The `printVideoGameDetails()` function prints out all attributes of the Videogame in a styled format. This function uses the `displayText()` function of each Text object to print out the details. <br />The `printVideoGameDetailsToFile()` function outputs all attributes to a specified input file. <br />The Videogame object has one accessor function that gets the title of the videogame.

___

### VideoGameLibrary Object

The VideoGameLibrary object contains a collection of Videogame objects stored in an array. The array size is initiated through user input. The constructor holds a pointer array of Videogame objects, the max number of games the library can hold, and the current number of games the library holds. <br />The constructor initializes the length of the array from user input, and the destructor calls the Videogame destructor for each object and prints a message at the end. <br />The `resizeVideoGameArray()` function resizes the array whenever the number of games in the array reaches the limit. The array then doubles itself in length and copies over the information to a new array. <br />The `addVideoGameToArray()` function creates a Videogame object based off user input and adds it to the VideoGameLibrary. <br />The `displayVideoGames()` function displays all videogame attributes in a styled numbered list. <br />The `removeVideoGameFromArray()` function calls the `displayVideoGameTitles()` function and asks the user to choose a game to remove. After validating the user input, the function removes the game and shifts all elements in the array up by one and decrements the numGames attribute. <br />The `saveToFile()` function saves all the Videogame object attributes to a file. <br />The `loadVideoGamesFromFile()` function reads input from a specified file and loads that data into the VideoGameLibrary.
