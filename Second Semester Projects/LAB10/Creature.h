#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <fstream>
using namespace std;

class Creature
{
private:
	string name;		// Name of creature
	string description; // Description of creature
	bool dangerous;		// Is the creature dangerous?
	float creatureCost; // Cost to take care of the creature per month

public:
	Creature();
	Creature(string, string, bool, float);
	string getName() const;
	string getDescription() const;
	bool getDangerous() const;
	float getCost() const;
	void setName(string);
	void setDescription(string);
	void setDangerous(bool);
	void setCost(float);
	void printCreature();
	void printCreatureToFile(string);
};

#endif
