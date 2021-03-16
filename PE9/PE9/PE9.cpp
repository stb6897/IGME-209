#include <iostream>
#include "Player.h"

int main()
{
	// Stack no params
	Player gibby = Player();

	// Stack with params
	char bibbyName[] = "bibby";
	Player bibby = Player(bibbyName, 3, 8, 4);

	// Heap no params
	Player* hibby = new Player();

	// Heap with params
	char jibbyName[] = "jibby";
	Player* jibby = new Player(jibbyName, 10, 3, 6);

	gibby.PrintPlayer();

	bibby.PrintPlayer();

	hibby->PrintPlayer();

	jibby->PrintPlayer();

	// Delete classes on the heap.
	delete hibby;
	delete jibby;
}