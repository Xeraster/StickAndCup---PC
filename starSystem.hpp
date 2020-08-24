starSystem :: starSystem()
{

}

starSystem :: starSystem(uint32_t seed, nameGenerator *randomNameObject)
{
	color *colorArray = new color[6];
	colorArray[0] = color(255,0,0,255); 	//red
	colorArray[1] = color(255,150,0,255);	//orange
	colorArray[2] = color(255,255,0,255);	//yellow
	colorArray[3] = color(0,100,255,255);		//light blue
	colorArray[4] = color(255,75,0,255);	//orangish red
	colorArray[5] = color(255,255,255,255);	//white

	starColor = colorArray[betterRand(seed) % 6];
	//size = betterRand(seed + 1028201) % 13;
	if (starColor == colorArray[0])	//if star is red
	{
		size = (betterRand(seed + 1028201)%10)+5;
		temp = (betterRand(seed + 1062601)%2000)+1500;
		mass = static_cast<double>((betterRand(seed + 1327231)%200))/100;
		starType = "M";
	}else if (starColor == colorArray[1])
	{
		size = (betterRand(seed + 1028201)%6)+3;
		temp = (betterRand(seed + 1062601)%1500)+3500;
		mass = static_cast<double>((betterRand(seed + 1327231)%200))/100;
		starType = "K";
	}else if (starColor == colorArray[2])
	{
		size = (betterRand(seed + 1028201)%5)+2;
		temp = (betterRand(seed + 1062601)%1000)+5000;
		mass = static_cast<double>((betterRand(seed + 1327231)%200))/100;
		starType = "G";
	}
	else if (starColor == colorArray[3]) //blue giants
	{
		size = (betterRand(seed + 1028201)%10)+5;
		temp = (betterRand(seed + 1062601)%14000)+11000;
		mass = static_cast<double>((betterRand(seed + 1327231)%3000))/100;
		if (temp < 11000)
		{
			starType = "A";
		}
		if (temp < 25000)
		{
			starType = "B";
		}
		if (temp >= 25000)
		{
			starType = "O";
		}
	}else if (starColor == colorArray[5])
	{
		size = (betterRand(seed + 1028201)%8)+2;
		temp = (betterRand(seed + 1062601)%1500)+6000;
		mass = static_cast<double>((betterRand(seed + 1327231)%400))/100;
		starType = "F";
	}else if (starColor == colorArray[4])
	{
		size = (betterRand(seed + 1028201)%5)+3;
		temp = (betterRand(seed + 1062601)%1500)+3500;
		mass = static_cast<double>((betterRand(seed + 1327231)%200))/100;
		starType = "K";
	}

	starName = randomNameObject->generateStarName(seed);


	delete[] colorArray;
}

starSystem :: starSystem(color whatColor, int size)
{

}