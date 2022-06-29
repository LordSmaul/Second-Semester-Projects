#include "Creature.h"
#include "MinArrayHeap.h"

void enterMagicalCreature(MinArrayHeap *);
void enterMagicalCreatureFromFile(MinArrayHeap *);
void deleteCreature(MinArrayHeap *);
void printCreatures(MinArrayHeap *);
void saveCreaturesToFile(MinArrayHeap *);

int main()
{
	int choice;
	char response;
	Creature removedCreature;

	MinArrayHeap creatureTree(100);

	do
	{
		cout << "\n\nWhat would you like to do?\n";
		cout << "\t1.  Enter Magical Creature\n";
		cout << "\t2.  List/Print Creatures.\n";
		cout << "\t3.  Remove Next Creature.\n";
		cout << "\t4. End Program.\n";
		cout << "\tEnter 1, 2, 3, or 4.\n";
		cout << "CHOICE:  ";
		cin >> choice;

		while (choice < 1 || choice > 4)
		{
			cout << "\nYour choice was invalid.  Choose a number 1 through 4.\n";
			cout << "CHOICE: ";
			cin >> choice;
		}

		cout << endl;

		switch (choice)
		{
		case 1: // Enter creatures
			int enterChoice;
			cout << "\n\nDo you want to enter the creature(s)\n";
			cout << "\t1.  Manually?\n";
			cout << "\t2.  From a file?\n";
			cout << "ENTER 1 or 2:  ";
			cin >> enterChoice;
			while (enterChoice < 1 || enterChoice > 2)
			{
				cout << "\nInvalid choice.  Please enter 1 or 2.\n";
				cout << "ENTER 1 or 2:  ";
				cin >> enterChoice;
			}
			if (enterChoice == 1)
				enterMagicalCreature(&creatureTree);
			else
				enterMagicalCreatureFromFile(&creatureTree);
			break;

		case 2:
			printCreatures(&creatureTree);
			break;

		case 3:
			if (creatureTree.getNumberOfNodes() == 0)
			{
				cout << "Sorry, there are no nodes in the heap" << endl;
			}
			else
			{
				creatureTree.remove(removedCreature);
				cout << "\nYou have removed " << removedCreature.getName() << endl;
			}
			break;

		case 4:
			cout << "\nWould you like to save your creature list to a file? (y or n)  ";
			cin >> response;
			if (tolower(response) == 'y')
				saveCreaturesToFile(&creatureTree);
			cout << "\n\nGOODBYE!\n";
			break;
		default:
			break;
		}

	} while (choice != 4);

	return 0;
}

void enterMagicalCreature(MinArrayHeap *creatureTree)
{
	string name, desc;
	float cost;
	bool dangerous;
	char response;
	int creaturePosition;

	do
	{
		cout << "\nNAME: ";
		cin.ignore();
		getline(cin, name);

		cout << "\nDESCRIPTION:  ";
		getline(cin, desc);

		cout << "\nIS IT A DANGEROUS CREATURE? (y or n):  ";
		cin >> response;
		if (tolower(response) == 'y')
			dangerous = true;
		else
			dangerous = false;

		cout << "\nCOST PER MONTH TO CARE FOR CREATURE:  ";
		cin >> cost;

		// Create a creature
		Creature newCreature(name, desc, dangerous, cost);

		// Insert creature in the tree
		creatureTree->insert(&newCreature);

		cout << "\n\nWant to add more creatures? (y or n)  ";
		cin >> response;

	} while (tolower(response) == 'y');
}

void enterMagicalCreatureFromFile(MinArrayHeap *creatureTree)
{
	ifstream inputFile;
	char filename[100];
	cout << "\n\nWhat is the name of the file you want to read from?\n";
	cout << "FILENAME:  ";
	cin.ignore();
	cin.getline(filename, 100);

	inputFile.open(filename);
	if (inputFile.fail())
	{
		cout << filename << " does not exist or is corrupt.  Sorry.  Can't load creatures.\n";
	}
	else
	{
		string temp, name, desc;
		float cost;
		bool dangerous;
		char response;
		int numCreatures = 0;
		// Load creatures from file

		// Read first creature name to see if one exists
		getline(inputFile, temp);

		while (!inputFile.eof()) // If we are not at the end of the file, proceed
		{
			name = temp;
			getline(inputFile, desc);

			inputFile >> dangerous;
			inputFile >> cost;
			inputFile.ignore();

			// Create a creature
			Creature newCreature(name, desc, dangerous, cost);

			// Insert creature in the tree
			creatureTree->insert(&newCreature);

			numCreatures++;
			// Start reading next line with new creature.
			getline(inputFile, temp);
		}

		inputFile.close();
		inputFile.clear();

		cout << "\n"
			 << numCreatures << " creatures from " << filename << " have been read from the file.\n";
	}
}

void printCreatures(MinArrayHeap *creatureTree)
{
	creatureTree->display();
}

void saveCreaturesToFile(MinArrayHeap *creatureTree)
{
	string filename;
	Creature tempCreature;

	if (creatureTree->getNumberOfNodes() == 0)
	{
		cout << "------------------------------------------------------------------------" << endl;
		cout << "THERE ARE NO CREATURES AT YOUR ZOO!\n";
		cout << endl;
	}
	else
	{
		creatureTree->saveToFile();
	}
}