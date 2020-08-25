#ifndef PLANET_H
#define PLANET_H

#include <iostream>
#include "starSystem.h"
#include "nameGenerator.h"
#include <string>
using namespace std;
//random number generator
uint32_t betterRand(uint32_t seed);

class planet
{
public:
	planet();

	planet(uint32_t seed, nameGenerator *randomNameObject);

	color getColor() { return planetColor; }

	int getRadius() { return radius; }

	int getDistance() { return distanceFromSun; }

	string getName() { return name; }

	string getTypeName() { return typeName; }

	string getSizeName() { return planetSizeName; }

	double getMass() { return mass; }
protected:
	starSystem *parentStar;
	string name;
	string planetSizeName;
	string typeName;
	int planetType;
	int radius;
	double density;
	unsigned long long mass;
	int distanceFromSun;
	bool hasAtmosphere;
	color planetColor;
	color atmosphereColor;

};

#include "randomFunctions.h"
#include "planet.hpp"

#endif