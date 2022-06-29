/*
	File Name: Driver.cpp
	Author: LordSmaul
	Purpose: Driver file for Course object
*/

#include "Course.h"

int main()
{
	// Creates a pointer to an array of Course pointers
    Course **myCourses;

	int numCourses, numSections;
	string name, location, input;
	int numHours;
	
	cout << "\nHow many courses are you taking this semester?\n";
	cin >> numCourses;
	cin.ignore();
	
	// Dynamically allocates a new array of pointers to Courses of size numCourses and assigns this array to myCourses
    myCourses = new Course*[numCourses];
	
	// Assigns values for each variable in Course object
	for (int i = 0; i < numCourses; i++)
	{
		cout << "\nCOURSE NAME:\t\t";
		getline(cin, name);
		cout << "\nCOURSE LOCATION:\t";
		getline(cin, location);
		cout << "\nCOURSE HOURS:\t\t";
		cin >> numHours;
		cout << "\nNUMBER OF SECTIONS?\t";
		cin >> numSections;
		cin.ignore();
		
		// Calls the createCourse function and makes sure to assign the returned value to myCourses[i]
    	myCourses[i] = createCourse(name, location, numSections, numHours);

		
		for (int x = 0; x < numSections; x++)
		{
			cout << "\nSECTION " << x + 1 << ":\t\t";
			// Reads in the string from the user and inserts the correct array element of the sections array
            getline(cin, input);
			myCourses[i]->sections[x] = input;
		}
		cout << "\n*******************************\n";
	}
	
	// Prints user created Courses
	cout << "\n\nThe following are the courses you entered:\n\n";
	for (int i = 0; i < numCourses; i++)
	{
		cout << "******************************* COURSE " << (i + 1) << " *******************************\n";
		printCourse(myCourses[i]);
	}
	
	// Destroys user created Courses
	for (int i = 0; i < numCourses; i++)
	{
		destroyCourse(myCourses[i]);
	}
	delete [] myCourses;
	
	cout << endl << endl;
	return 0;
}