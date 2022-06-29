/*
	File Name: lab6.cpp
	Author: LordSmaul
	Date: 3/07/2022
	Purpose: Managing two queues for a theme park ride
*/

#include <iostream>
#include <iomanip>
#include "Queue.h"
using namespace std;

int menu();

int main()
{
	Queue normalQueue;
	Queue instantQueue;
	int choice, passChoice;
	string name;

	do
	{
		choice = menu();
		switch (choice)
		{
		case 1:
			cout << "\t\tWhat is your name?\t";
			getline(cin, name);

			cout << "\t\t" << name << ", do you have a(n):\n";
			cout << "\t\t1)Normal Pass?\n";
			cout << "\t\t2)InstantPass?\n";
			cout << "\t\tCHOOSE 1 or 2:\t";
			cin >> passChoice;
			while (passChoice < 1 || passChoice > 2)
			{
				cout << "\t\tOOPS!  That ain't right.  CHOOSE 1 or 2:\t";
				cin >> passChoice;
			}
			cin.ignore();

			if (passChoice == 1)
				normalQueue.enqueue(name);
			else
				instantQueue.enqueue(name);

			break;

		case 2:
			if (!instantQueue.isEmpty())
			{
				instantQueue.dequeue(name);
				cout << "\t\t" << name << ", InstantPass holder, YOU ARE RIDING!\n";
			}
			else if (!normalQueue.isEmpty())
			{
				normalQueue.dequeue(name);
				cout << "\t\t" << name << ", normal pass holder, YOU ARE RIDING!\n";
			}
			else
				cout << "\t\tTHERE IS NO ONE IN LINE!\n";
			break;

		case 3:
			cout << "**IT IS QUITTING TIME!**\n\n";
		}
	} while (choice != 3);

	return 0;
}

int menu()
{
	int choice;

	cout << "\n\t1)\tADD RIDER TO WAIT LINE.\n";
	cout << "\t2)\tREMOVE RIDER FROM LINE.\n";
	cout << "\t3)\tDONE FOR THE DAY.\n";
	cout << "\tCHOOSE 1-3:\t";
	cin >> choice;
	while (choice < 1 || choice > 3)
	{
		cout << "\tOOPS!  That ain't right.  CHOOSE 1-3:\t";
		cin >> choice;
	}
	cin.ignore();

	return choice;
}