#ifndef RANDOMFUNCTIONS_H
#define RANDOMFUNCTIONS_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "color.h"
#include "starSystem.h"

using namespace std;

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

#include "randomFunctions.cpp"

#endif