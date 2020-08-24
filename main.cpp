#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

#include "randomFunctions.h"
#include "color.h"
#include "LTimer.h"
#include "nameGenerator.h"
#include "planet.h"
#include "simpleStarSystem.h"
#include "starSystem.h"

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

LTimer fpsTimer;
LTimer capTimer;

string timeText;


const int SCREEN_FPS = 60;
const double SCREEN_TICKS_PER_SECOND = 1000;
const int SCREEN_TICKS_PER_FRAME = SCREEN_TICKS_PER_SECOND / SCREEN_FPS;

bool exitGame = false;

color white(255,255,255);
color green(0,255,0);
color transGray(150,150,150,150);

int largeZoomX = 0;
int largeZoomY = 0;

bool zoomedOut = true;

starSystem selectedSystem;
bool aStarIsSelected = false;

bool canClickMouse = true;

int countedFrames = 0;

nameGenerator *nameRandomizerObject = new nameGenerator;

void update(SDL_Renderer *ren, SDL_Window *win);

int main()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	TTF_Init();
	SDL_Window *win = SDL_CreateWindow("Stick and Cup: Definitive Edition", 100, 100, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	//SDL_SetWindowResizable(win, SDL_TRUE);
	if (win == nullptr)
	{
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr)
	{
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	std::string imagePath = "hello.bmp";
	SDL_Surface *bmp = SDL_LoadBMP(imagePath.c_str());
	if (bmp == nullptr)
	{
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
	SDL_FreeSurface(bmp);
	if (tex == nullptr)
	{
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}
	//A sleepy rendering loop, wait for 3 seconds and render and present the screen each time

	fpsTimer.start();
	while (exitGame == false)
	{
		capTimer.start();
		update(ren, win);

		//Calculate and correct fps
        double avgFPS = countedFrames / ( fpsTimer.getTicks() / SCREEN_TICKS_PER_SECOND );
        if( avgFPS > 2000000 )
        {
        	avgFPS = 0;
        }
        timeText = "FPS: " + to_string(avgFPS);


		//handle all the events at the end of update even it there are many
		SDL_Event testEvent;
		while (SDL_PollEvent(&testEvent) == 1)
		{
			if (testEvent.window.event == SDL_WINDOWEVENT_CLOSE)
			{
				exitGame = true;
			}

		}

		if (fpsTimer.getTicks() > SCREEN_TICKS_PER_SECOND * 3)
		{
			fpsTimer.stop();
			fpsTimer.start();
			countedFrames = 0;
		}

	}


	return 0;
} 


void update(SDL_Renderer *ren, SDL_Window *win)
{
		//for drawing the selection box around the mouse
		int mouseBoxX = 80 * (screenSizeX(win)/800);
		int mouseBoxY = 60 * (screenSizeY(win)/600);

		string lastKeyPressed = "shut up";
		int mouseX, mouseY;
		Uint32 lastMouse = SDL_GetMouseState(&mouseX, &mouseY);

		if (lastMouse == SDL_BUTTON(SDL_BUTTON_LEFT) && canClickMouse && zoomedOut)
		{
			lastKeyPressed = "left mouse is being pressed";
			canClickMouse = false;
			zoomedOut = false;
			largeZoomX = (mouseX - (mouseBoxX/2))+largeZoomX;
			largeZoomY = (mouseY - (mouseBoxY/2))+largeZoomY;
		}

		if (lastMouse == SDL_BUTTON(SDL_BUTTON_RIGHT) && canClickMouse && !zoomedOut)
		{
			lastKeyPressed = "right mouse is being pressed";
			canClickMouse = false;
			zoomedOut = true;
			largeZoomX = largeZoomX-(screenSizeX(win)/2)+(mouseBoxX/2)-(mouseX - (screenSizeX(win)/2));
			largeZoomY = largeZoomY-(screenSizeY(win)/2)+(mouseBoxY/2)-(mouseY - (screenSizeY(win)/2));
		}

		if (!canClickMouse && lastMouse != SDL_BUTTON(SDL_BUTTON_LEFT))
		{
			canClickMouse = true;
		}

		const Uint8 *lastKey = SDL_GetKeyboardState(NULL);
		if (lastKey[SDL_SCANCODE_UP])
		{
			largeZoomY--;
			//lastKeyPressed = "the up arrow";
		}
		if (lastKey[SDL_SCANCODE_DOWN])
		{
			largeZoomY++;
			//lastKeyPressed = "the up arrow";
		}
		if (lastKey[SDL_SCANCODE_RIGHT])
		{
			largeZoomX++;
			//lastKeyPressed = "the up arrow";
		}
		if (lastKey[SDL_SCANCODE_LEFT])
		{
			largeZoomX--;
			//lastKeyPressed = "the up arrow";
		}

		cout << "windowsize = " << screenSizeX(win) << "x" << screenSizeY(win) << endl;
		uint32_t bluh = 42069;

		//First clear the renderer
		SDL_RenderClear(ren);

		if (zoomedOut)
		{
			//draw a "selection box" around the mouse pointer
			drawRect(ren, transGray, mouseX - (mouseBoxX/2), mouseY - (mouseBoxY/2), mouseBoxX, mouseBoxY);
			for (int xPos = 0; xPos < screenSizeX(win); xPos++)
 			{
 				for (int yPos = 0; yPos < screenSizeY(win); yPos++)
 				{
 					//draw a simple star object instead of the more complex one for better framerate
 					int tehValue = (bluh * (yPos+largeZoomY) - (xPos+largeZoomX));
 					//starSystem newSystem(tehValue);
 					simpleStarSystem newSimpleSystem(tehValue);
 					if (betterRand(tehValue) %1000 > 996)
 					{
 						drawPixel(ren, (xPos), (yPos), newSimpleSystem.getColor());

 					}
 				}
 			}
 		}
 		else
 		{
 			aStarIsSelected = false;
 			for (int xPos = 0; xPos < (screenSizeX(win)/10); xPos++)
 			{
 				for (int yPos = 0; yPos < (screenSizeY(win)/10); yPos++)
 				{
 					int tehValue = (bluh * ((yPos)+largeZoomY) - ((xPos)+largeZoomX));
 					//draw a complicated star with all the cool info. Much too slow for fully zoomed out view
 					starSystem newSystem(tehValue, nameRandomizerObject);
 					if (betterRand(tehValue) %1000 > 996)
 					{
 						drawCircle(ren, newSystem.getColor(), newSystem.getSize(), (xPos*10), (yPos*10), true);
 						//find out if mouse is close enough to "select" this planet
 						if (abs(mouseX - (xPos*10)) < 15 && abs(mouseY - (yPos*10)) < 15)
 						{
 							aStarIsSelected = true;
 							drawEmptyCircle(ren, green, newSystem.getSize() + 10, (xPos*10), (yPos*10));
 							selectedSystem = newSystem;
 						}

 					}
 				}
 			}
 			if (aStarIsSelected)
 			{
 				starInfoTooltip(ren, win, selectedSystem);
 			}
 		}


		//now draw a pointless green circle
		//drawEmptyCircle(ren, green, 18, 100, 400);
		//drawLine(ren, green, 2, 2, 500, 300);

		//draw a pointless circle
		//drawCircle(ren, green, 5, 44, 400);


		drawText(ren, 8, white, timeText, 2, 2);
		drawText(ren, 8, white, "mouse=" + to_string(mouseX) + "x" + to_string(mouseY), 2, 50);
		drawText(ren, 8, white, "galaxy position: " + to_string(largeZoomX) + "x" + to_string(largeZoomY), 2, 100);
		//Update the screen
		SDL_RenderPresent(ren);
		//Take a quick break after all that hard work
	int frameticks = capTimer.getTicks();
	if (frameticks < SCREEN_TICKS_PER_FRAME)
	{
		capTimer.stop();
		SDL_Delay(SCREEN_TICKS_PER_FRAME - frameticks);
	}
	countedFrames++;

	//SDL_Delay(1000);
}
