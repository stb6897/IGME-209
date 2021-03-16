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

#pragma region Recommended Functions

void update(Clock* deltaClock, Time* time, b2World* world) {
	// Get the elapsed time and then reset.
	*time = (deltaClock->getElapsedTime());
	deltaClock->restart();

	// Perform time step
	world->Step(time->asSeconds(), 6, 2);
}

// Uses get random position to move the target.
void moveTarget(float* xPos, float* yPos) {
	*xPos = getRandomPosition(5.0f);
	*yPos = getRandomPosition(5.0f);
}

void display(b2Vec2 snakePos, b2Vec2 targetPos, int targetHits) {

	// Prints out target position. (Bonus: tells how many targets are left)
	cout << '(' << targetHits << "/2)";
	cout << "Target: (";
	printf("%.2f", targetPos.x);
	cout << ',';
	printf("%.2f", targetPos.y);
	cout << ") --> Snake: ";

	// Prints out snake position.
	cout << '(';
	printf("%.2f", snakePos.x);
	cout << ',';
	printf("%.2f", snakePos.y);
	cout << ')';
}

void applyForces(int key, b2Body* snake, float movementSpeed) {

	// Create forces
	b2Vec2 leftForce(-movementSpeed, 0);
	b2Vec2 rightForce(movementSpeed, 0);
	b2Vec2 upForce(0, movementSpeed * 1.5f);

	switch (key) {
	case 119:
		// Maps to W
		snake->ApplyForceToCenter(upForce, true);
		break;
	case 97:
		// Maps to A
		snake->ApplyForceToCenter(leftForce, true);
		break;
	case 100:
		// Maps to D
		snake->ApplyForceToCenter(rightForce, true);
		break;
	}
	// Sorry S key I think gravity has this one.
}

#pragma endregion

#pragma region Helper Functions

b2Body* createWall(b2World* world, float x, float y, float w, float h) {
	// Creates wall body definition
	b2BodyDef wallBodyDef;
	wallBodyDef.position.Set(x, y);
	b2Body* wall = world->CreateBody(&wallBodyDef);

	// Creats the shape we will attach to the body
	b2PolygonShape* wallBox = new b2PolygonShape();
	wallBox->SetAsBox(w / 2.0f, h / 2.0f);
	wall->CreateFixture(wallBox, 0.0f);
	return wall;
}

bool inTargetRange(b2Vec2 snakePos, b2Vec2 targetPos, float range) {
	// This is just a wrapper for checking the distance.
	return b2Distance(snakePos, targetPos) < range;
}

float getRandomPosition(float range) {
	// Get a number from 0 to 1
	float rng = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	// Because it doesn't really matter how its random I just have essentially
	// do a coinflip for if it will be positive or negative.
	if (rand() % 2 == 0) {
		return range * rng;
	}
	else {
		return range * rng * -1;
	}
}

#pragma endregion