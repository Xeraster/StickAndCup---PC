void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y){
	//Setup the destination rectangle to be at the position we want
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	//Query the texture to get its width and height to use
	SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(ren, tex, NULL, &dst);
}

void drawLine(SDL_Renderer *ren, color whatColor, int x1, int y1, int x2, int y2)
{
	SDL_SetRenderDrawColor(ren, whatColor.getRed(), whatColor.getGreen(), whatColor.getBlue(), SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(ren, x1, y1, x2, y2);
	SDL_SetRenderDrawColor(ren, 0, 0, 0, SDL_ALPHA_OPAQUE);
}

void drawPixel(SDL_Renderer *ren, int x, int y, color whatColor)
{
	SDL_SetRenderDrawColor(ren, whatColor.getRed(), whatColor.getGreen(), whatColor.getBlue(), SDL_ALPHA_OPAQUE);
	SDL_RenderDrawPoint(ren, x, y);
	SDL_SetRenderDrawColor(ren, 0, 0, 0, SDL_ALPHA_OPAQUE);
}

int screenSizeX(SDL_Window *win)
{
	int w, h;
	//SDL_GetRendererOutputSize(ren, &w, &h);
	SDL_GetWindowSize(win, &w, &h);
	return w;
}

int screenSizeY(SDL_Window *win)
{
	int w, h;
	SDL_GetWindowSize(win, &w, &h);
	return h;
}

void drawText(SDL_Renderer *ren, int fontSize, color TextColor, string textString, int x, int y)
{
	//char stringArray[] = textString;

	TTF_Font* Sans = TTF_OpenFont("Sans.ttf", fontSize*3);

	SDL_Color textColor = {TextColor.getRed(), TextColor.getGreen(), TextColor.getBlue()};

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, textString.c_str(), textColor);

	SDL_Texture* Message = SDL_CreateTextureFromSurface(ren, surfaceMessage);

	SDL_Rect Message_rect; //create a rect
	Message_rect.x = x;  //controls the rect's x coordinate 
	Message_rect.y = y; // controls the rect's y coordinte
	Message_rect.w = (30 * textString.length()) * fontSize / 24; // for every 10 letters at 24pt, make it 300 pixels long
	Message_rect.h = 80 * fontSize / 24; // for every 24pt, make it 80 characters high

	SDL_RenderCopy(ren, Message, NULL, &Message_rect);

	SDL_DestroyTexture(Message);
	SDL_FreeSurface(surfaceMessage);
	TTF_CloseFont(Sans);

}

void drawRect(SDL_Renderer *ren, color whatColor, int x, int y, int sizeX, int sizeY)
{
	SDL_Rect thisRect;
	thisRect.x = x;
	thisRect.y = y;
	thisRect.w = sizeX;
	thisRect.h = sizeY;

	SDL_SetRenderDrawColor(ren, whatColor.getRed(), whatColor.getGreen(), whatColor.getBlue(), whatColor.getAlpha());

	SDL_RenderDrawRect(ren, &thisRect);

	SDL_SetRenderDrawColor(ren, 0, 0, 0, SDL_ALPHA_OPAQUE);
}

void drawCircle(SDL_Renderer *ren, color circleColor, int radius, int xPos, int yPos, bool filled)
{
    SDL_SetRenderDrawColor(ren, circleColor.getRed(), circleColor.getGreen(), circleColor.getBlue(), circleColor.getAlpha());
    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w; // horizontal offset
            int dy = radius - h; // vertical offset
            if (filled && (dx*dx + dy*dy) <= (radius * radius))
            {
                SDL_RenderDrawPoint(ren, xPos + dx, yPos + dy);
            }
    	}
    }

    SDL_SetRenderDrawColor(ren, 0, 0, 0, SDL_ALPHA_OPAQUE);
}

void drawEmptyCircle(SDL_Renderer *ren, color circleColor, int radius, int xPos, int yPos)
{
	SDL_SetRenderDrawColor(ren, circleColor.getRed(), circleColor.getGreen(), circleColor.getBlue(), circleColor.getAlpha());

	for (int w = -3; w < radius * 2 + 3; w++)
    {
        for (int h = -3; h < radius * 2 + 3; h++)
        {
            int dx = radius - w; // horizontal offset
            int dy = radius - h; // vertical offset
            if ((dx*dx + dy*dy) >= ((radius-1) * (radius-1)) && (dx*dx + dy*dy) <= ((radius+1) * (radius+1)))
            {
                SDL_RenderDrawPoint(ren, xPos + dx, yPos + dy);
            }
   		}	
	}

    SDL_SetRenderDrawColor(ren, 0, 0, 0, SDL_ALPHA_OPAQUE);

}

void starInfoTooltip(SDL_Renderer *ren, SDL_Window *win, starSystem system)
{
	color white(255,255,255,255);
	string starNameText = system.getName();
	int nameFontSize = 12;
	if (starNameText.length() > 17)
	{
		nameFontSize = 10;
	}
	if (starNameText.length() > 22)
	{
		nameFontSize = 8;
	}
	drawText(ren, nameFontSize, white, system.getName(), screenSizeX(win) - 300, screenSizeY(win) - 110);
	drawText(ren, 8, white, "Class " + system.getType() + " star", screenSizeX(win) - 300, screenSizeY(win) - 80);
	drawText(ren, 8, white, "Temperature: " + to_string(system.getTemp()) + "K", screenSizeX(win) - 300, screenSizeY(win) - 60);
	string massText = to_string(system.getMass());
	massText.resize(massText.length() - 4);
	drawText(ren, 8, white, "Mass: " + massText + "x 10^30 kg", screenSizeX(win) - 300, screenSizeY(win) - 40);
	drawText(ren, 8, white, "Solar radius: " + to_string(system.getSize()*695700/10) + "km", screenSizeX(win) - 300, screenSizeY(win) - 20);
}

void starInfoTooltip(SDL_Renderer *ren, SDL_Window *win, starSystem system, int x, int y)
{
	color white(255,255,255,255);
	string starNameText = system.getName();
	int nameFontSize = 12;
	if (starNameText.length() > 17)
	{
		nameFontSize = 10;
	}
	if (starNameText.length() > 22)
	{
		nameFontSize = 8;
	}
	drawText(ren, nameFontSize, white, system.getName(), x, y - 110);
	drawText(ren, 8, white, "Class " + system.getType() + " star", x, y - 80);
	drawText(ren, 8, white, "Temperature: " + to_string(system.getTemp()) + "K", x, y - 60);
	string massText = to_string(system.getMass());
	massText.resize(massText.length() - 4);
	drawText(ren, 8, white, "Mass: " + massText + "x 10^30 kg", x, y - 40);
	drawText(ren, 8, white, "Solar radius: " + to_string(system.getSize()*695700/10) + "km", x, y - 20);
}

void planetInfoTooltip(SDL_Renderer *ren, SDL_Window *win, planet whichPlanet, int x, int y)
{
	color white(255,255,255,255);

	drawText(ren, 12, white, whichPlanet.getName(), x, y - 110);
	drawText(ren, 8, white, whichPlanet.getTypeName() + " " + whichPlanet.getSizeName(), x, y - 80);
	//drawText(ren, 8, white, "Temperature: " + to_string(system.getTemp()) + "K", x, y - 60);
	string massText = to_string(whichPlanet.getMass());
	massText.resize(5);
	drawText(ren, 8, white, massText + "x10^23 kg", x, y - 40);
	//drawText(ren, 8, white, "Solar radius: " + to_string(system.getSize()*695700/10) + "km", x, y - 20);
}

uint32_t betterRand(uint32_t seed)
{
	seed += 0xe120fc15;
	uint64_t tmp;
	tmp = (uint64_t)seed * 0x4a39b70d;
	uint32_t m1 = (tmp >> 32) ^ tmp;
	tmp = (uint64_t)m1 * 0x12fad5c9;
	uint32_t m2 = (tmp >> 32) ^ tmp;
	return m2;
}

void initQuickAccessColors()
{
	colorArray[0] = color(255,0,0,255); 	//red
	colorArray[1] = color(255,150,0,255);	//orange
	colorArray[2] = color(255,255,0,255);	//yellow
	colorArray[3] = color(0,100,255,255);		//light blue
	colorArray[4] = color(255,75,0,255);	//orangish red
	colorArray[5] = color(255,255,255,255);	//white
}

color seedToStarColor(uint32_t seed)
{
	//generate a color with the random seed the exact same way the starSystem class does
	return colorArray[betterRand(seed) % 6];
}

int seedToStarSize(uint32_t seed)
{
	color starColor = seedToStarColor(seed);
	int size = 0;

	if (starColor == colorArray[0])	//if star is red
	{
		size = (betterRand(seed + 1028201)%10)+5;
	}else if (starColor == colorArray[1])
	{
		size = (betterRand(seed + 1028201)%6)+3;
	}else if (starColor == colorArray[2])
	{
		size = (betterRand(seed + 1028201)%5)+2;
	}
	else if (starColor == colorArray[3]) //blue giants
	{
		size = (betterRand(seed + 1028201)%10)+5;
	}else if (starColor == colorArray[5])
	{
		size = (betterRand(seed + 1028201)%8)+2;
	}else if (starColor == colorArray[4])
	{
		size = (betterRand(seed + 1028201)%5)+3;
	}

	return size;
}

planetMetaData getPlanetDataFromSeed(uint32_t seed, planetMetaData yeah)
{
	//planetMetaData yeah;
	int typeSize = 0;
	int planetType = static_cast<int>(betterRand(seed)%10);
	seed++;
	if (planetType >= 7)
	{
		typeSize = (betterRand(seed)%2)+1;
		seed++;
		planetType = 7;

	}
	else
	{
		if (betterRand(seed+547265)%1000 > 950)
		{
			typeSize = 3;
		}
		else
		{
			typeSize = betterRand(seed)%3;
		}
	}

	seed++;
	if (typeSize == 0)
	{
		yeah.radius = (betterRand(seed)%537)+100;
		seed++;
	}
	else if (typeSize == 1)
	{
		yeah.radius = (betterRand(seed)%3185)+637;
		seed++;
	}
	else if (typeSize == 2)
	{
		yeah.radius = (betterRand(seed)%21622)+3822;
		seed++;
	}
	else if (typeSize == 3)
	{
		yeah.radius = (betterRand(seed)%252000)+63000;
		seed++;
	}

	if (planetType == 0)
	{
		color theColor((betterRand(seed)%119)+17,136,81);
		yeah.whatColorIsPlanet = theColor;

	}else if (planetType == 1)
	{
		color theColor(212,(betterRand(seed)%65)+115,81);
		yeah.whatColorIsPlanet = theColor;

	}else if (planetType == 2)
	{
		color theColor(193,(betterRand(seed)%34)+212,246);
		yeah.whatColorIsPlanet = theColor;	
	}
	else if (planetType == 3)
	{
		color theColor(150+betterRand(seed)%50,150+betterRand(seed)%50,150+betterRand(seed)%50);
		yeah.whatColorIsPlanet = theColor;
		
	}else if (planetType == 4)
	{
		color theColor(255,(betterRand(seed)%111)+33,33);
		yeah.whatColorIsPlanet = theColor;	
		
	}else if (planetType == 5)
	{
		color theColor(10,(betterRand(seed)%146),146);
		yeah.whatColorIsPlanet = theColor;	

	}else if (planetType == 6)
	{
		color theColor(78,60,betterRand(seed)%60);
		yeah.whatColorIsPlanet = theColor;

	}else if (planetType == 7)
	{
		color theColor((betterRand(seed+1)%150)+100,(betterRand(seed+2)%150)+100,(betterRand(seed)%150)+100);
		yeah.whatColorIsPlanet = theColor;	
	}

	seed++;
	seed++;
	seed++;
	yeah.distance = betterRand(seed)%2000;

	return yeah;
}