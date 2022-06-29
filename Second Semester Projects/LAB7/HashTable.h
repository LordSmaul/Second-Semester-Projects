/*
	Title:  	HashTable.h
	Author:		LordSmaul
	Date: 		3/28/2021
	Purpose:  	Implementing a hash table for a costume database, using linear probing to handle collisions
			
*/
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <iomanip>
#include "HashEntry.h"
#include "Costume.h"
using namespace std;

class HashTable
{
	private:
		int tableSize;
		HashEntry** hashArray;
		
	public:
		HashTable(int size) // HashTable Constructor
		{
			tableSize = size; // sets tableSize for array
			hashArray = new HashEntry*[tableSize]; // Allocates new hash table
			for(int i = 0; i < tableSize; i++)
			{
				hashArray[i] = NULL;
			}
		}

		~HashTable() // HashTable Destructor
		{
			for(int i = 0; i < tableSize; i++)
			{
				delete hashArray[i];
			}
			delete [] hashArray;
		}
		
		void putValue(int key, Costume* value) // Inserts value into HashTable
		{
			HashEntry* newEntry = new HashEntry(key, value);

			int bucketIndex = key % tableSize; // Sets bucket index

			while(hashArray[bucketIndex] != NULL && hashArray[bucketIndex]->getKey() != key)
			{
				cout << "collision at bucket " << bucketIndex << endl;
				bucketIndex = (bucketIndex + 1) % tableSize; // Changes position of the bucket
			}
			hashArray[bucketIndex] = newEntry;
			cout << "BUCKET " << bucketIndex << endl;
		}

		void printHashTable()
		{
			cout << "----------\n";
			
			for(int i = 0; i < tableSize; i++)
			{
				if(hashArray[i] != NULL)
				{
					cout << i << ": " << *(hashArray[i]->getValue()) << endl;
				}
				else
					cout << i << ", " << "NULL" << endl;
			}
			cout << "----------\n\n";
		}
};

#endif