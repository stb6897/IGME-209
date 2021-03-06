// PE7_Pointers_Start.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class MovableObject
{
public:
	int xPos;
	int yPos;
	void PrintPos()
	{
		cout << "X:" << xPos << " Y:" << yPos << endl;
	}
};

class Player : public MovableObject
{
public:
	char* name;
	Player()
	{
		cout << "player ctor" << endl;
		name = new char[15];
	}

	~Player()
	{
		cout << "player dtor" << endl;
		delete[] name;
	}
};

class Monster : public MovableObject
{
public:
	int damage;
};

int main()
{
	//Monster* boss = new Monster();
	//Player* pOne = new Player();
	MovableObject* boss = new Monster();
	MovableObject* pOne = new Player();
	Monster* fakeMonster = (Monster*)pOne;


	// the difference between the MovableObject and Player is that Player has a name pointer.
	std::cout << "Boss Pointer:\n";
	std::cout << boss << "\n";
	std::cout << "Player Pointer:\n";
	std::cout << pOne << "\n";
	std::cout << "Fake Monster Pointer:\n";
	std::cout << fakeMonster << "\n";

	boss->xPos = 10;
	boss->yPos = 20;
	pOne->xPos = 5;
	fakeMonster->yPos = 10;

	std::cout << "Boss Pos: \n";
	boss->PrintPos();
	std::cout << "Player Pos: \n";
	pOne->PrintPos();
	std::cout << "Fake Monster Pos: \n";
	fakeMonster->PrintPos();


	delete boss;
	delete pOne;
	fakeMonster = nullptr;

	// fakeMonster and pOne point to the same thing so we can't delete it twice.
	// instead I got rid of the fakeMonster pointer.
	//delete fakeMonster;

	return 0;
}

