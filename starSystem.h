#ifndef STARSYSTEM_H
#define STARSYSTEM_H

#include <iostream>
#include "nameGenerator.h"
#include <string>
using namespace std;
//random number generator
uint32_t betterRand(uint32_t seed);

class starSystem
{
public:
	starSystem();

	starSystem(uint32_t seed, nameGenerator randomNameObject);

	starSystem(color whatColor, int size);

	color getColor() { return starColor; }

	int getSize() { return size; }

	string getType() { return starType; }

	int getTemp() { return temp; }

	double getMass() { return mass; }

	string getName() { return starName; }
protected:
	int size;
	int temp;
	double mass;
	string starType;
	color starColor;
	string starName;

};

#include "randomFunctions.h"
#include "starSystem.hpp"

#endif