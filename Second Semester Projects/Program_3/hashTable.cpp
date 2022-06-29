/*
	File name: hashTable.cpp
	Author: LordSmaul
	Date: 4/02/2022
	Purpose: Implements a hashTable of entries that handles collisions through chaining
*/

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "hashTable.h"

using std::cout;
using std::string;

// hashTable Constructor
// Allocates new hashArray with size indicated in the parameter, and sets all buckets to NULL
hashTable::hashTable(int size)
{
	tableSize = size;
	hashArray = new entry *[tableSize]; // Allocates new hashArray of entry pointer with size tableSize

	for (int i = 0; i < tableSize; i++) // Sets all buckets to NULL
	{
		hashArray[i] = NULL;
	}

	srand(time(0)); // Used to randomize users' salts
}

// hashTable Destructor
// Deletes all elements in the hashTable
hashTable::~hashTable()
{
	for (int i = 0; i < tableSize; i++)
	{
		if (hashArray[i] != NULL)
		{
			entry *prev = NULL;
			entry *entry = hashArray[i];
			while (entry) // deletes each chained entry in the bucket
			{
				prev = entry;
				entry = entry->next;
				delete prev;
			}
		}
	}

	delete[] hashArray;
}

// Returns a bucket index for the user based on ASCII value of their username
// Designed specifically for collisions to happen
int hashTable::hash(string key)
{
	int sum = 0;
	for (int i = 0; i < key.size(); i++)
		sum += key[i];

	return sum % tableSize;
}

// Gets the entry for a specified user
// Used in validateLogin(), removeUser(), and getSalt() functions
hashTable::entry *hashTable::getEntry(string key)
{
	int bucketIndex = hash(key);
	entry *entry = NULL;

	// If bucket is empty, iterate through buckets until one that isn't empty is found
	// Since the getEntry() function is used to validate the username/password, if the key doesn't exist,
	// the program just returns a user that already exists in the system, and the validation/remove functions fail,
	// as the usernames and passwords don't match
	// I did this because just returning NULL didn't seem to work, unless I did it wrong
	if (hashArray[bucketIndex] == NULL)
	{
		int check = bucketIndex;
		while (hashArray[check] == NULL) // Iterates through buckets until a non-NULL bucket is found
		{
			if (check == 9)
			{
				check = 0;
			}
			else
			{
				check++;
			}
		}
		return hashArray[check]; // Returns a non-NULL user that intentionally doesn't match the key
	}
	// Bucket is not empty
	// Searches through the bucket until the last element (if the key isn't found) or until a user is found
	else
	{
		entry = hashArray[bucketIndex];
		while (entry->next && entry->getUsername() != key)
		{
			entry = entry->next;
		}
		return entry; // Can return either a valid user if the username matches the key, or an invalid entry
	}
}

// Generates a random string value to append to the end of the password for to enhance encryption
string hashTable::generateSalt()
{
	string s = "";

	for (int i = 0; i < tableSize; i++)
		s = s + char('!' + (rand() % 93));
	return s;
}

// Returns salt value for each user
string hashTable::getSalt(string key)
{
	entry *user = getEntry(key);
	return user->getSalt();
}

// Adds a user to the hashTable
// Won't add a username if it alread exists in the hashTable
void hashTable::addEntry(string username, string salt, string passHash)
{
	entry *newEntry = new entry(username, salt, passHash);
	int bucketIndex = hash(username);

	if (hashArray[bucketIndex] == NULL) // If bucket is empty
	{
		hashArray[bucketIndex] = newEntry;
	}
	else // Collision occurs in a bucket
	{
		entry *entry = hashArray[bucketIndex];
		while (entry->next && entry->getUsername() != username)
		{
			entry = entry->next;
		}

		if (username == entry->getUsername()) // If username is already in the system
		{
			cout << "Sorry! This user already exists in our system\n";
		}
		else // Adds new user
		{
			entry->next = newEntry;
		}
	}
}

// Validates user login info
// Calls getEntry() fucntion and checks if username and password match function arguments
bool hashTable::validateLogin(string username, string hashPassword)
{
	entry *user = getEntry(username);
	if (username == user->getUsername() && hashPassword == user->getHashPassword())
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Removes a user from the hashTable
// Returns true if user is successfully removed and false if they aren't or they weren't in the table
bool hashTable::removeUser(string username, string hashPassword)
{
	entry *userToRemove = getEntry(username);
	// If user is found
	if (userToRemove->getUsername() == username && userToRemove->getHashPassword() == hashPassword)
	{
		int bucketIndex = hash(username);
		entry *prev = NULL;	 // Keeps track of previous entry
		entry *entry = NULL; // Keeps track of current entry

		// If specified user is the first in the bucket
		if (userToRemove->getUsername() == hashArray[bucketIndex]->getUsername())
		{
			prev = hashArray[bucketIndex];
			hashArray[bucketIndex] = hashArray[bucketIndex]->next;
			delete prev;
		}
		// User is in the bucket, but not the first one
		else
		{
			entry = hashArray[bucketIndex];
			while (entry && entry->getUsername() != userToRemove->getUsername())
			{
				prev = entry;
				entry = entry->next;
			}

			prev->next = entry->next;
			delete entry;
		}

		// If user has been removed successfully
		if (getEntry(username) == NULL || getEntry(username)->getUsername() != username)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}