/*
	File: markovList.h
	Author: LordSmaul
	Date: 4/26/2022
	Prupose: Building an adjacency-list based graph using a string key map of user-defined "edge" structures
			 that generates random strings of text based on input from a corpus
*/
#ifndef MARKOVLIST_H
#define MARKOVLIST_H

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class markovList
{
private:
	struct edge
	{
		string destNode;
		float weight;
		edge *next;
	};
	map<string, edge *> corpus;
	int corpusSize;

public:
	markovList(const char *); // markovList Constructor
	~markovList(); // markovList Destructor
	string generate(int); // Generates a random line of text using a map
};

// markovList constructor
// Constructs a map of string keys and user-defined "edges" from a corpus file of word pairs
// Iterates through each line of the .txt file and parses out the first word as the map key for each node list
// Takes the subsequent words and statistical weights and allocates edge structs, appending them to the end of each adjacency list
// The first word of each line is set as the index of the map, and the subsequent words make up the "edges" of the adjacency list
markovList::markovList(const char *filename)
{
	ifstream file(filename);
	stringstream parser, splitter;
	string line, index, word;
	float weight;
	edge *newEdge;
	srand(time(0));

	if (file.good())
	{
		file >> corpusSize;
		file.ignore(1, '\n');

		while (getline(file, line, '\n')) // Maps every word to a position in the matrix, keeps the line in an array of buffers for later
		{
			parser.clear();
			parser << line;
			getline(parser, index, ','); // Pulls the first word of the line, which is the node for which makes a list of neighbors
			while (getline(parser, word, ','))
			{
				newEdge = new edge;
				splitter.clear();
				splitter.str(word);
				splitter >> word >> weight;

				newEdge->destNode = word; // Sets word value of the edge
				newEdge->weight = weight; // Sets weight value of the edge
				newEdge->next = NULL;

				if (!corpus[index]) // If the head index is NULL
				{
					corpus[index] = newEdge; // Sets head index of the list to newEdge
				}
				else // List already contains values
				{
					edge *temp = corpus[index]; // Sets index of the head for iteration
					while (temp->next)
					{
						temp = temp->next; // Iterates through list until next pointer is NULL
					}
					temp->next = newEdge; // Sets new tail node
				}
			}
		}
	}
}

// markovList destructor
markovList::~markovList()
{
	// Iterates through each edge list of the map and deletes every node
	for (map<string, edge *>::iterator it = corpus.begin(); it != corpus.end(); ++it)
	{
		edge *temp = it->second;
		edge *prev = NULL;
		while (temp)
		{
			prev = temp;
			temp = temp->next;
			delete prev;
		}
	}
}

// Genertates a random senetence from a randomized starting value
string markovList::generate(int length)
{
	string sentence;
	map<string, edge *>::iterator it = corpus.begin(); // Initialize an iterator to find a random node in the next line
	advance(it, rand() % corpusSize);				   // Grabs a random node from the corpus as a starting point
	edge *nodeForIt = it->second;					   // Temporary node index used inside for loop
	
	for (int i = 0; i < length; i++)
	{
		float checkAg = (float)rand() / RAND_MAX; // Sets random variable to check weights of nodes against
		float check = 0;						  // Used for aggregating node weights to randomize word selection from the list
		edge *temp = nodeForIt;
		while (check < checkAg) // Iterates until end of list or weight aggregates exceed the random value
		{
			check += temp->weight;
			// Checked inside while loop so that following line wouldn't iterate to an empty node
			if (check >= checkAg)
			{
				break;
			}
			temp = temp->next;
		}
		sentence += temp->destNode + " ";	// Appends node's word to the sentence
		nodeForIt = corpus[temp->destNode]; // Sets index for next list, using temp node's word value
	}
	return sentence + "\b.";
}

#endif