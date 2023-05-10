# Project 4 - Markov Text Processing

### practice with text processing, maps, graphs using adjacency list/matrix and iterators

**All relevant in-depth documentation for each function is explained in the markovList.h file.**

The purpose of this program was to build a graph using a string key map of user-defined structures called *edges* that is used to generate a random string of text based on a "corpus" folder. This is the process behind Markov Text Processing. We were given a Python file that generates a "corpus" (a text document containing every single word present in the document and the statistical frequency of all the possible words that come after that word in the text). The sample text provided with the project was Howard Pyle's *Book of Pirates*, but any text document can be used. We were tasked to use either an adjacency list or matrix to generate a graph based on the corpus and then generate a string of text based off the corpus. Header files were provided for both options.

The main driver calls the markovList constructor and then calls the generate() function with a parameter for the length. This function will generate a random string of text using input from the string map.
The class markovList contains the structure *edge*, which contains the word, it’s statistical weight, and a pointer to the next node. It also includes a string map of edges that is used to build the adjacency list and an integer for the size. 

The constructor for the markovList reads in the input from the corpus.txt file and generates a string key map based off that input. <br />The destructor uses an iterator that traverses the entire string map and deletes all allocated memory. <br />the generate() function uses an iterator to find a starting position for the string and then generates a string of random text based off whatever data is in the corpus. It sets a random variable to check against the weight of each node and iterates through the specific line of the corpus, adding the statistical weights of each node together until that value is greater than the check. It then adds the word at that destination to the string and continues.
