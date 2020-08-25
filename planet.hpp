planet :: planet()
{

}

planet :: planet(uint32_t seed, nameGenerator *randomNameObject)
{

	/*
	planet types:
	0 Terrestrial
	1 Desert
	2 Ice
	3 Iron
	4 Lava
	5 Ocean
	6 Sillicate
	7 Gas
	*/

	/*
	planet sizes
	0. planetoid	less than 0.1 earth's size 				(100km-637km)
	1. dwarf		(0.1)-(0.6) x earth's size 				(637-3822)
	2. planet 		(0.6) - 4 x earth's size (of 6371km) 	(3822-25484)
	3. giant 		10-50 x earths size (common) or (50-5000) earths size (rare) (63000-315000) or (315000-31855000)
	*/
	int typeSize = 0;
	planetType = static_cast<int>(betterRand(seed)%10);
	seed++;
	if (planetType >= 7)
	{
		typeSize = (betterRand(seed)%2)+1;
		seed++;
		hasAtmosphere = true;
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
		radius = (betterRand(seed)%537)+100;
		planetSizeName = "planetoid";
		seed++;
	}
	else if (typeSize == 1)
	{
		radius = (betterRand(seed)%3185)+637;
		planetSizeName = "dwarf";
		seed++;
	}
	else if (typeSize == 2)
	{
		radius = (betterRand(seed)%21622)+3822;
		planetSizeName = "planet";
		seed++;
	}
	else if (typeSize == 3)
	{
		radius = (betterRand(seed)%252000)+63000;
		planetSizeName = "giant";
		seed++;
	}

	if (planetType == 0)
	{
		color theColor((betterRand(seed)%119)+17,136,81);
		planetColor = theColor;
		typeName = "Terrestrial";

	}else if (planetType == 1)
	{
		color theColor(212,(betterRand(seed)%65)+115,81);
		planetColor = theColor;
		typeName = "Desert";

	}else if (planetType == 2)
	{
		color theColor(193,(betterRand(seed)%34)+212,246);
		planetColor = theColor;	
		typeName = "Ice";
	}
	else if (planetType == 3)
	{
		color theColor(150+betterRand(seed)%50,150+betterRand(seed)%50,150+betterRand(seed)%50);
		planetColor = theColor;
		typeName = "Iron";
		
	}else if (planetType == 4)
	{
		color theColor(255,(betterRand(seed)%111)+33,33);
		planetColor = theColor;	
		typeName = "Molten";
		
	}else if (planetType == 5)
	{
		color theColor(10,(betterRand(seed)%146),146);
		planetColor = theColor;	
		typeName = "Ocean";

	}else if (planetType == 6)
	{
		color theColor(78,60,betterRand(seed)%60);
		planetColor = theColor;
		typeName = "Rock";

	}else if (planetType == 7)
	{
		color theColor((betterRand(seed+1)%150)+100,(betterRand(seed+2)%150)+100,(betterRand(seed)%150)+100);
		planetColor = theColor;
		typeName = "Gas";	
	}

	seed++;
	if (planetType == 7)
	{
		density = (betterRand(seed)%1000);	//kg/m^3
	}
	else
	{
		density = (betterRand(seed)%10000);	//kg/m^3
	}
	mass = abs((((radius * radius * radius)*3.14159*(4/3))*density));
	seed++;
	name = randomNameObject->generatePlanetName(seed);

	seed++;
	distanceFromSun = betterRand(seed)%2000;
}