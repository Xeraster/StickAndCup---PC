#ifndef SIMPLESTARSYSTEM_H
#define SIMPLESTARSYSTEM_H

//this is a seed-compatible version of starSystem except it only has color properties
//this is to make the most zoomed out view less laggy
#include <iostream>
#include <string>
using namespace std;
//random number generator
uint32_t betterRand(uint32_t seed);

class simpleStarSystem
{
public:
	simpleStarSystem();

	simpleStarSystem(uint32_t seed);

	simpleStarSystem(color whatColor, int size);

	color getColor() { return starColor; }
protected:
	color starColor;

};

#include "simpleStarSystem.hpp"

#endif