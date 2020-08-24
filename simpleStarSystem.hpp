simpleStarSystem :: simpleStarSystem()
{

}

simpleStarSystem :: simpleStarSystem(uint32_t seed)
{
	color *colorArray = new color[6];
	colorArray[0] = color(255,0,0,255); 	//red
	colorArray[1] = color(255,150,0,255);	//orange
	colorArray[2] = color(255,255,0,255);	//yellow
	colorArray[3] = color(0,100,255,255);		//light blue
	colorArray[4] = color(255,75,0,255);	//orangish red
	colorArray[5] = color(255,255,255,255);	//white

	starColor = colorArray[betterRand(seed) % 6];


	delete[] colorArray;
}

simpleStarSystem :: simpleStarSystem(color whatColor, int size)
{

}