/*
	Title:  		Lab4.cpp
	Author: 		LordSmaul
	Purpose:		Main function for "List.h"
*/

#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	// Define a LinkedList object.
	List halloweenList;
	
	// Append (add to the end) values to the list
	cout << "\nI am appending several strings to the list.\n\n";
	halloweenList.appendNode("boogeyman");
	halloweenList.appendNode("ghost");
	halloweenList.appendNode("scarecrow");
	halloweenList.appendNode("witch");
	halloweenList.appendNode("zombie");
	
	halloweenList.displayList();
	
	// Insert
	cout << "\nI am inserting \"vampire\" in the list.\n\n";
	halloweenList.insertNode("vampire");
	
	halloweenList.displayList();
	
	// Delete
	cout << "\nI am deleting \"ghost\" from the list.\n\n";
	halloweenList.deleteNode("ghost");
	
	halloweenList.displayList();

	return 0;
}