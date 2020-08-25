#ifndef NAMEGENERATOR_H
#define NAMEGENERATOR_H

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
//random number generator
uint32_t betterRand(uint32_t seed);

class nameGenerator
{
public:
	nameGenerator();

	string generateStarName(uint32_t seed);

	string generatePlanetName(uint32_t seed);

	string randomVowelString(uint32_t seed);

protected:
	string *personNames;
	string *prefixNames;
	string *TwoLetterWordSections;
	string *OneLetterWordSections;
	string *vowels;
	string *doublevowels;			//right now this is only used for planet names. I may change that depending on how the names generated with this turn out
	string *suffixNames;

};

#include "randomFunctions.h"
#include "nameGenerator.hpp"

#endif