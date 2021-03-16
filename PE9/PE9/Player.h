#pragma once
class Player
{
private:
	char* name;
	int dex;
	int strength;
	int perception;

public:
	Player();
	Player(char* name, int dex, int strength, int perception);
	void PrintPlayer();
};