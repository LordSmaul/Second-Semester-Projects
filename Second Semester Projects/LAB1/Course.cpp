#include "Course.h"

// Creates a Course object from user input and assigns value to sections array
Course* createCourse(string name, string loc, int sectNum, int hours)
{
    Course *myCourse = new Course;
    myCourse->name = name;
    myCourse->location = loc;
    myCourse->creditHours = hours;
    myCourse->sectionNum = sectNum;
    myCourse->sections = new string[sectNum];

    return myCourse;
}

//Deallocates memory of each Course object
void destroyCourse(Course* myCourse)
{
    for (int i = 0; i < myCourse->sectionNum; i++)
    {
        delete [] (myCourse->sections + i);
    }
    delete myCourse->sections;
    delete myCourse;
}

//Prints out each Course object
void printCourse(Course* myCourse)
{
    cout << "COURSE NAME:\t" << myCourse->name << endl;
    cout << "COURSE LOCATION:\t" << myCourse->location << endl;
    cout << "COURSE HOURS:\t" << myCourse->creditHours << endl;
    cout << "COURSE SECTIONS:" << endl;
    for (int i = 0; i < myCourse->sectionNum; i++)
    {
        cout << "\t\t" << *(myCourse->sections + i) << endl;
    }
}