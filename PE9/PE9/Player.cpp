#include "Player.h"

#include <iostream>
#include <cstring>

using namespace std;
Player::Player() {
	// Default stats
	dex = 10;
	strength = 10;
	perception = 10;

	this->name = new char[10];
	// Ah, perfection.
	name[0] = 'U';
	name[1] = 'n';
	name[2] = 'k';
	name[3] = 'n';
	name[4] = 'o';
	name[5] = 'w';
	name[6] = 'n';
	name[7] = '\0';
}
Player::Player(char* name, int dex, int strength, int perception)
{
	// Set stats and name from params.
	this->name = name;
	this->dex = dex;
	this->strength = strength;
	this->perception = perception;
}

void Player::PrintPlayer()
{
	// Print out name and stats.
	cout << "-----------------------------------" << endl;
	cout << "Name: ";
	printf(name);
	cout << endl;
	cout << "Dex: " << dex << endl;
	cout << "Strength: " << strength << endl;
	cout << "Perception: " << perception << endl;
	cout << "-----------------------------------" << endl;
}