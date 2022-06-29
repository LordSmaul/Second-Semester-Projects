/*
	Title:      HashEntry.h
	Author:	    REDACTED
	Date:       October 6, 2020
	Purpose:    Hash Table Implementation
				Values					-	costume objects
				Hash Function			-	modulus operator
				Collision resolution	-	linear probing			
*/

#ifndef HASHENTRY_H
#define HASHENTRY_H

#include <iostream>
#include "Costume.h"
using namespace std;

class HashEntry
{
	private:
		int key;
		Costume* value;
		
	public:
		HashEntry(int k, Costume* v)
		{
			this->key = k;
			this->value = v;
		}
		
		int getKey()
		{
			return key;
		}
		Costume* getValue()
		{
			return value;
		}
		void setValue(Costume* v)
		{
			value = v;
		}
};

#endif