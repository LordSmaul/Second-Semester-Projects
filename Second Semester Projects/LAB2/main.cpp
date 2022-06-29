/*
	Title:  Lab2.cpp
	Author: LordSmaul
	Purpose:  Demonstrate knowledge of recursive functions
*/

#include <bits/stdc++.h>
using namespace std;

// Function prototypes for recursive functions
int sumOfNumbers(int);
bool isMember(int *, int, int);
void stringReverser(string, int);
bool isPalindrome(string);
int multiply(int, int);

const int ARRAY_SIZE = 10;

int main()
{
	int choice, num, num1, num2;
	int myArray[ARRAY_SIZE];
	srand(time(NULL)); // Randomizes numbers
	string userString, userStrModified;

	do
	{
		cout << "\n\nWhat do you want to do?\n";
		cout << "\t1.  Sum of Numbers\n";
		cout << "\t2.  IsMember Array Function\n";
		cout << "\t3.  String Reverser\n";
		cout << "\t4.  Palindrome Detector\n";
		cout << "\t5.  Recursive Multiplication\n";
		cout << "\t6.  End the Program\n";
		cout << "CHOOSE 1-6:  ";
		cin >> choice;

		while (!cin || choice < 1 || choice > 6)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nInvalid input!  CHOOSE 1-6:  ";
			cin >> choice;
		}

		switch (choice)
		{
		case 1:
			cout << "\n\nSUM OF NUMBERS\n";
			cout << "Enter an integer:  ";
			cin >> num;
			cout << "The result is: " << sumOfNumbers(num);
			break;

		case 2:
			for (int x = 0; x < ARRAY_SIZE; x++)
			{
				myArray[x] = (rand() % 100) + 1;
			}
			cout << "\n\nISMEMBER ARRAY FUNCTION\n";
			cout << "Enter an integer:  ";
			cin >> num;
			cout << "\nHere are the array values:  ";
			for (int x = 0; x < ARRAY_SIZE; x++)
			{
				cout << myArray[x] << " ";
			}

			if (isMember(myArray, num, ARRAY_SIZE))
			{
				cout << "\nYes! " << num << " is IN the array!" << endl;
			}
			else
			{
				cout << "\nNo! " << num << " is NOT in the array!" << endl;
			}
			break;

		case 3:
			cout << "\n\nSTRING REVERSER\n";
			cout << "Enter a string and I will reverse it:  ";
			cin.ignore();
			getline(cin, userString);
			stringReverser(userString, userString.size());
			cout << endl;
			break;

		case 4:
			cout << "\n\nPALINDROME DETECTOR\n";
			cout << "Enter a string and I will tell you if it is a palindrome:  ";
			cin.ignore();
			getline(cin, userString);

			// Change string to be all uppercase
			for (int x = 0; x < userString.length(); x++)
			{
				userString[x] = toupper(userString[x]);
			}

			// Remove spaces and commas from string
			userStrModified = userString;
			for (int x = 0; x < userStrModified.size(); x++)
			{
				if (userStrModified[x] == ' ')
				{
					userStrModified.erase(x, 1);
				}
				if (userStrModified[x] == ',')
				{
					userStrModified.erase(x, 1);
				}
			}

			if (isPalindrome(userStrModified))
			{
				cout << "Yes! " << userStrModified << " IS a palindrome!" << endl;
			}
			else
			{
				cout << "No! " << userStrModified << " is NOT a palindrome!" << endl;
			}
			break;

		case 5:
			cout << "\n\nRECURSIVE MULTIPLICATION\n";
			cout << "Enter in the first integer:  ";
			cin >> num1;
			cout << "\nEnter in the second integer:  ";
			cin >> num2;
			cout << "The value of " << num1 << " x " << num2 << " is " << multiply(num1, num2) << endl;
			break;
		}
	} while (choice != 6);

	cout << "\n\nGOODBYE!\n\n";
	return 0;
}

// Recursive Functions
// Recursive function that returns the sum of all variables from 1 to n
int sumOfNumbers(int n)
{
	if (n > 1)
	{
		return n + sumOfNumbers(n - 1);
	}
	else
	{
		return 1;
	}
}

// Recursive function that checks for a certain value in the array
bool isMember(int *array, int value, int size)
{
	if (size >= 0 && array[size] == value)
	{
		return true;
	}
	else if (size == 0 && array[0] != value) // If recursion reaches end of list without finding the element
	{
		return false;
	}
	else
	{
		return isMember(array, value, size - 1);
	}
}

// Recursive function that reverses a string input
void stringReverser(string s, int length)
{
	if (length == 0)
	{
		cout << s[length];
		return;
	}
	cout << s[length];
	stringReverser(s, length - 1);
}

// Recursion function that checks if a string input is a palindrome
bool isPalindrome(string s)
{
	// Substring reaches 0 or 1 letter
	if (s.size() == 0 || s.size() == 1)
	{
		return true;
	}
	else
	{
		// Checks each substring for matching first/last characters
		if (s[0] != s[s.size() - 1])
		{
			return false;
		}
		else
		{
			// Substrings string to check each character at first and last
			return isPalindrome(s.substr(1, s.size() - 2));
		}
	}
}

// Recursive function that "multiplies" two variables together
int multiply(int x, int y)
{
	if (y > 0)
	{
		return x + multiply(x, y - 1);
	}
	else
	{
		return 0;
	}
}