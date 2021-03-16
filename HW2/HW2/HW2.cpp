#include <iostream>
#include <conio.h>
#include <cstdlib>
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "snake.h"

using namespace sf;
using namespace std;

int main()
{
#pragma region Game Setup
	// Create World & Bounds
	b2Vec2 gravity(0, -2.8f);
	b2World world(gravity);

	// Creating the walls around the player.
	// I made this a function because its more or less the same code for each wall.
	// It has a range of 50 in the negative and positive x.
	// It has a range of 50 in the negative and positive y.
	b2Body* leftWall = createWall(&world, -55, 0, 10, 100);
	b2Body* rightWall = createWall(&world, 55, 0, 10, 100);
	b2Body* topWall = createWall(&world, 0, 55, 100, 10);
	b2Body* bottomWall = createWall(&world, 0, -55, 100, 10);

	// Setup Random
	srand(static_cast <unsigned> (time(0)));

	// Creating the snake.
	b2BodyDef snakeBodyDef;
	// Making it a dynamic body so it gravity is in play.
	snakeBodyDef.type = b2_dynamicBody;
	snakeBodyDef.position.Set(0, -40);

	b2Body* snake = world.CreateBody(&snakeBodyDef);

	// Creating a box of width 2 and height 2.
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);

	// Creating and attaching the fixture
	b2FixtureDef snakeFixtureDef;
	snakeFixtureDef.shape = &dynamicBox;
	snakeFixtureDef.density = 1.0f;
	snakeFixtureDef.friction = 0.3f;

	snake->CreateFixture(&snakeFixtureDef);

	// Game logic
	const float movementSpeed = 1000;
	int targetHits = 0;
	b2Vec2 position;
	b2Vec2 targetPosition;
	moveTarget(&targetPosition.x, &targetPosition.y);
#pragma endregion
#pragma region Game Start, Game Loop, and Game End
	// Welcome Message
	cout << "Welcome to gravity snake!" << endl;
	cout << "Use WAS to move. Try to reach target position!" << endl;
	cout << "Press ENTER to start! You can press ESC to exit." << endl;
	cin.ignore();

	// Setup running bool and delta time.
	bool running = true;
	Clock deltaClock;
	Time deltaTime;

	// FEATURE.
	// I am going to count how many times the keys got pressed.
	// And then compare it to the time.
	// The lower the score the better!
	float keyPresses = 0;
	Clock totalTime;

	// Main game loop.
	while (running && targetHits < 2) {
		// Update our physics.
		update(&deltaClock, &deltaTime, &world);

		// Display Position
		position = snake->GetPosition();
		display(position, targetPosition, targetHits);

		// Check target distance
		if (inTargetRange(position, targetPosition, 2.0f)) {
			targetHits++;
			moveTarget(&targetPosition.x, &targetPosition.y);
			cout << "(TARGET HIT)";
		}
		cout << "(" << targetHits << "/2) Hits";
		cout << endl;

		// If the key is ESC we will stop the loop.
		// If not we just pass of the key to applyForces.
		if (_kbhit() == 1) {
			int key = _getch();
			if (key == 27) {
				running = false;
			}
			else
			{
				keyPresses++;
				applyForces(key, snake, movementSpeed);
			}
		}
	}

	// Ending Message & Score
	float seconds = totalTime.getElapsedTime().asSeconds();
	float pressesPerSecond = keyPresses / seconds;
	cout << "GAME OVER!! You average presses per second score is: " << pressesPerSecond << endl;
	cout << "Press ENTER to exit the application.";
	cin.ignore();

	// Deleting the walls & snake.
	world.DestroyBody(leftWall);
	leftWall = nullptr;

	world.DestroyBody(rightWall);
	rightWall = nullptr;

	world.DestroyBody(topWall);
	topWall = nullptr;

	world.DestroyBody(bottomWall);
	bottomWall = nullptr;

	world.DestroyBody(snake);
	snake = nullptr;
#pragma endregion
	return 0;
}