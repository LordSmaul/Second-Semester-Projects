#include "Timer.h"
#include <iostream>
#include <fstream>
using namespace std;

struct wordCount
{
	string word;
	int count;
};

void insertionSort(wordCount *wordArray, int numWords);
void bubbleSortReverse(wordCount *wordArray, int numWords);
void quicksort(wordCount *wordArray, int low, int high);
int partition(wordCount *wordArray, int left, int right);

int main()
{
	wordCount* wordArray = new wordCount[150000];
	int numWords = 0;
	string temp;
	int num;
	
	ofstream outfile;
	ifstream infile;

	time_t start, end;
	char filename[50];

	cout << "\nWhich file are you opening?\n";
	cin >> filename;
	infile.open(filename);
	
	if(!infile)
	{
		cout << "\nSorry, I couldn't find that file.\n";
		return 1;
	}

	while (getline(infile, temp) && numWords != 150000)
	{
		wordArray[numWords].word = temp;
		infile >> num;
		infile.ignore();
		wordArray[numWords].count = num;
		numWords++;
	}
	cout << "\nyou've read in " << numWords << " words.\n";

	// Sort the songs using insertion sort and print them out to the text file sortFileInsertion.txt
	start = getTime(); // Starts timer.   
	insertionSort(wordArray, numWords);
	end = getTime(); // Ends timer.
	outfile.open("sortFileInsertion.txt");
	cout << "\nInsertion sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x = 0; x < numWords; x++)
	{
		outfile << wordArray[x].word << " : " << wordArray[x].count << endl;
	}
	outfile.close();

	// Sort the songs in reverse order using bubble sort & print them out to the text file sortFileReverseBubble.txt
	start = getTime(); // Starts timer. 
	bubbleSortReverse(wordArray, numWords);
	end = getTime(); // Ends timer.
	outfile.open("sortFileReverseBubble.txt");
	cout << "\nReverse bubble sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x = 0; x < numWords; x++)
	{
		outfile << wordArray[x].word << " : " << wordArray[x].count << endl;
	}
	outfile.close();

	// Sort the songs with quick sort & print them out to sortFileQuick.txt
	start = getTime(); //Starts timer. 
	quicksort(wordArray, 0, numWords-1);
	end = getTime(); // Ends timer.
	cout << "\nQuicksort: " << totalTime(start, end) << " seconds\n\n";
	outfile.open("sortFileQuick.txt");
	for(int x = 0; x < numWords; x++)
	{
		outfile << wordArray[x].word << " : " << wordArray[x].count << endl;
	}
	outfile.close();
	
	delete [] wordArray;
	return 0;
}


void insertionSort(wordCount *wordArray, int numWords)
{
	wordCount key;
	int j;
	
	for(int i = 1; i < numWords; i++)
	{
		key = wordArray[i]; // Select item to be sorted
		j = i-1;
		while (j >= 0 && wordArray[j].count > key.count) 
		{
			wordArray[j + 1] = wordArray[j]; // Move elements out of the way
			j = j - 1;
		}	
		wordArray[j + 1] = key; // Insert item in final sorted position
	}		
}

void bubbleSortReverse(wordCount *wordArray, int numWords)
{
	wordCount temp;
	
	for(int last = numWords - 1; last > 0; last--)
	{
		for(int i = 0; i < last; i++)
		{
			// Compare adjacent elements
			if(wordArray[i].count < wordArray[i+1].count)
			{
				// Swap the array elements
				temp = wordArray[i];
				wordArray[i] = wordArray[i+1];
				wordArray[i+1] = temp;
			}
		}
	}
}

void quicksort(wordCount *wordArray, int low, int high) 
{
	int pivot_location = 0;

	/* Base case: If there are 1 or zero elements to sort,
	partition is already sorted */
	if (low >= high) 
	{
		return;
	}

	// Partition the data within the array
	pivot_location = partition(wordArray, low, high); // Returns location of last element in low partition
	quicksort(wordArray, low, pivot_location); // Recursively sort low partition
	quicksort(wordArray, pivot_location + 1, high); // Recursively sort high partition
}

// Mid partition algorithm
int partition(wordCount *wordArray, int left, int right) 
{
	int pivot;
	wordCount temp;
	bool done = false;
	int middle = left + (right - left) / 2;
   
	// Pivot starts at middle
	pivot = wordArray[middle].count;
	int l = left;
	int r = right;
	while(!done)
	{
		
		while(wordArray[l].count < pivot) 
			++l;
		while(pivot < wordArray[r].count)
			--r;
		
		if(l >= r)
		{
			done = true;
		}
		else
		{
			temp = wordArray[l];
			wordArray[l] = wordArray[r];
			wordArray[r] = temp;
			
			++l;
			--r;
		}
	}
	return r;
}