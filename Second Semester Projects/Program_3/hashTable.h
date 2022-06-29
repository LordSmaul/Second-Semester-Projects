#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
using std::string;

class hashTable
{
private:
	class entry;
	int tableSize;
	entry **hashArray;
	int hash(string);
	hashTable::entry* getEntry(string);

public:
	hashTable(int);
	~hashTable();
	string generateSalt();
	string getSalt(string);
	void addEntry(string, string, string);
	bool validateLogin(string, string);
	bool removeUser(string, string);
};

class hashTable::entry
{
private:
	string username;
	string salt;
	string passHash;

public:
	entry *next;

	entry(string username, string salt, string passHash) // entry contructor
	{
		this->username = username;
		this->salt = salt;
		this->passHash = passHash;
		next = NULL;
	}

	string getUsername() const // username accessor
	{
		return username;
	}

	string getSalt() const // salt accessor
	{
		return salt;
	}

	string getHashPassword() const // hashed password accessor
	{
		return passHash;
	}
};

#endif