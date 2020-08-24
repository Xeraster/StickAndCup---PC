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
