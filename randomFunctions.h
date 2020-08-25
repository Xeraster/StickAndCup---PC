#ifndef RANDOMFUNCTIONS_H
#define RANDOMFUNCTIONS_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "color.h"
#include "planet.h"
#include "starSystem.h"
using namespace std;

typedef struct
{
	int radius;
	int distance;
	color whatColorIsPlanet;
} planetMetaData;

color *colorArray = new color[6];

//random number generator
uint32_t betterRand(uint32_t seed);

//renders a texture to a position on the screen
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y);

//orders you a pizza. not really it draws a pixel
void drawPixel(SDL_Renderer *ren, int x, int y, color whatColor);

//draws a line
void drawLine(SDL_Renderer *ren, color whatColor, int x1, int y1, int x2, int y2);

//returns x size of screen
int screenSizeX(SDL_Window *win);

//returns y size of screen
int screenSizeY(SDL_Window *win);

void drawText(SDL_Renderer *ren, int fontSize, color TextColor, string textString, int x, int y);

void drawRect(SDL_Renderer *ren, color whatColor, int x, int y, int sizeX, int sizeY);

void drawCircle(SDL_Renderer *ren, color circleColor, int radius, int xPos, int yPos, bool filled);

void drawEmptyCircle(SDL_Renderer *ren, color circleColor, int radius, int xPos, int yPos);

void starInfoTooltip(SDL_Renderer *ren, SDL_Window *win, starSystem system);

void planetInfoTooltip(SDL_Renderer *ren, SDL_Window *win, planet whichPlanet, int x, int y);

void initQuickAccessColors();

//im making these 2 functions for use in zoom 1 mode for better performance
color seedToStarColor(uint32_t seed);

int seedToStarSize(uint32_t seed);

planetMetaData getPlanetDataFromSeed(uint32_t seed, planetMetaData yeah);

#include "randomFunctions.cpp"

#endif