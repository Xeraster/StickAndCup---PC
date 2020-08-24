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
protected:
	starSystem *parentStar;
	string name;
	int radius;
	double gravity;
	bool hasAtmosphere;
	color planetColor;
	color atmosphereColor;

};

#include "randomFunctions.h"
#include "planet.hpp"

#endif