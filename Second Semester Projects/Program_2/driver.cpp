#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "County.h"
#include "List.h"

using namespace std;

int main()
{
	ifstream file;
	stringstream temp;
	string line, county, state;
	int index, pop;
	// file.open("counties_ten.csv", ios::in);
	file.open("counties_list.csv", ios::in);

	List<County *> counties; // List of County pointers

	County *newCounty; // County object

	if (file.good())
	{
		while (getline(file, line, ','))
		{
			temp.clear();
			temp.str(line);
			temp >> index;

			getline(file, line, ',');
			county = line;

			getline(file, line, ',');
			state = line;

			getline(file, line, '\n');
			temp.clear();
			temp.str(line);
			temp >> pop;

			newCounty = new County(index, county, state, pop);
			counties.append(newCounty); // Adds newCounty to List
		}
	}

	file.close();

	counties.mergesort(); // Merge Sorts the List
	counties.print();	  // Prints sorted counties in descending order

	return 0;
}