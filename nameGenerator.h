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

protected:
	string *personNames;
	string *prefixNames;
	string *TwoLetterWordSections;
	string *OneLetterWordSections;
	string *vowels;
	string *suffixNames;

};

#include "randomFunctions.h"
#include "nameGenerator.hpp"

#endif