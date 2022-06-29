#ifndef COURSE_H
#define COURSE_H

#include <bits/stdc++.h>
using namespace std;

//Structure Prototype
struct Course
{
    string name;
    string location;
    string *sections;
    int sectionNum;
    int creditHours;
};

//Function Prototypes -- More info in .cpp file
Course* createCourse(string, string, int, int);
void destroyCourse(Course* myCourse);
void printCourse(Course* myCourse);

#endif