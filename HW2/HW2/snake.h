#include <iostream>
#include <conio.h>
#include <cstdlib>
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
using namespace sf;

#pragma once
void update(Clock* deltaClock, Time* time, b2World* world);
void display(b2Vec2 snakePos, b2Vec2 targetPos, int targetHits);
void applyForces(int key, b2Body* snake, float movementSpeed);
void moveTarget(float* xPos, float* yPos);
b2Body* createWall(b2World* world, float x, float y, float w, float h);
bool inTargetRange(b2Vec2 snakePos, b2Vec2 targetPos, float range);
float getRandomPosition(float range);