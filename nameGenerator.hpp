nameGenerator :: nameGenerator()
{
	//string personNames;
	//string prefixNames;
	//string 2LetterWordSections;
	//string 1LetterWordSections;
	//string vowels;
	//string suffixNames

	personNames = new string[25];

	personNames[0] = "Blerb";
	personNames[1] = "Bethany";
	personNames[2] = "Bernard";
	personNames[3] = "Robert";
	personNames[4] = "Jabba the Hutt";
	personNames[5] = "Stephen King";
	personNames[6] = "Bill Clinton";
	personNames[7] = "Blackbeard";
	personNames[8] = "Mr. Roger";
	personNames[9] = "Bob";
	personNames[10] = "Bill";
	personNames[11] = "Angelica";
	personNames[12] = "Bufferton";
	personNames[13] = "Biffany";
	personNames[14] = "Dillington";
	personNames[15] = "Jak";
	personNames[16] = "Wak";
	personNames[17] = "Stephen";
	personNames[18] = "Bilbert";
	personNames[19] = "Philbert";
	personNames[20] = "Bert";
	personNames[21] = "Dr. Bung";
	personNames[22] = "George Washington";
	personNames[23] = "Bob Dole";
	personNames[24] = "Rick";

	prefixNames = new string[11];
	prefixNames[0] = "LHS";
	prefixNames[1] = "LYY";
	prefixNames[2] = "XXX";
	prefixNames[3] = "Amazing";
	prefixNames[4] = "Bigass";
	prefixNames[5] = "Crazy";
	prefixNames[6] = "Happy";
	prefixNames[7] = "Scary";
	prefixNames[8] = "Osha Compliant";
	prefixNames[9] = "Lost";
	prefixNames[10] = "Stupid";

	//now for the part where is fucks stuff and tries to make up new words
	OneLetterWordSections = new string[20];
	OneLetterWordSections[0] = "b";
	OneLetterWordSections[1] = "c";
	OneLetterWordSections[2] = "d";
	OneLetterWordSections[3] = "f";
	OneLetterWordSections[4] = "g";
	OneLetterWordSections[5] = "h";
	OneLetterWordSections[6] = "j";
	OneLetterWordSections[7] = "k";
	OneLetterWordSections[8] = "l";
	OneLetterWordSections[9] = "m";
	OneLetterWordSections[10] = "n";
	OneLetterWordSections[11] = "p";
	OneLetterWordSections[12] = "q";
	OneLetterWordSections[13] = "r";
	OneLetterWordSections[14] = "s";
	OneLetterWordSections[15] = "t";
	OneLetterWordSections[16] = "v";
	OneLetterWordSections[17] = "w";
	OneLetterWordSections[18] = "x";
	OneLetterWordSections[19] = "z";

	TwoLetterWordSections = new string[7];
	TwoLetterWordSections[0] = "zh";
	TwoLetterWordSections[1] = "th";
	TwoLetterWordSections[2] = "tr";
	TwoLetterWordSections[3] = "chr";
	TwoLetterWordSections[4] = "fl";
	TwoLetterWordSections[5] = "bl";
	TwoLetterWordSections[5] = "pl";

	vowels = new string[6];
	vowels[0] = "a";
	vowels[1] = "e";
	vowels[2] = "i";
	vowels[3] = "o";
	vowels[4] = "u";
	vowels[5] = "y";

	doublevowels = new string[16];
	doublevowels[0] = "ae";
	doublevowels[1] = "ea";
	doublevowels[2] = "ai";
	doublevowels[3] = "au";
	doublevowels[4] = "eu";
	doublevowels[5] = "ei";
	doublevowels[6] = "eo";
	doublevowels[7] = "ia";
	doublevowels[8] = "ie";
	doublevowels[9] = "ii";
	doublevowels[10] = "io";
	doublevowels[11] = "oa";
	doublevowels[12] = "oo";
	doublevowels[13] = "ou";
	doublevowels[14] = "ua";
	doublevowels[15] = "ui";

	suffixNames = new string[4];
	suffixNames[0] = "Star";
	suffixNames[1] = "Sun";
	suffixNames[2] = "System";
	suffixNames[3] = "Place";


}

string nameGenerator :: generateStarName(uint32_t seed)
{
	seed++;
	if (betterRand(seed) % 1000 > 800)
	{
		string result = "";
		seed++;
		//generate a "named" star
		result += personNames[betterRand(seed)%24];
		result += "'s ";
		seed++;
		result += prefixNames[betterRand(seed)%10];
		result += " ";
		seed++;
		result += suffixNames[betterRand(seed)%3];

		return result;
	}
	else
	{
		string result;
		seed++;
		if (betterRand(seed)%1000 < 333)
		{	
			seed++;
			result+=OneLetterWordSections[betterRand(seed)%19];
			for(int i = 0; i < (betterRand(seed)%10)+1; i++)
			{
				seed++;
				result+=vowels[betterRand(seed)%5];
				seed++;
				if (betterRand(seed)%100 < 50)
				{
					result+=OneLetterWordSections[betterRand(seed)%19];
				}
				else
				{
					result+=TwoLetterWordSections[betterRand(seed)%5];
				}
				seed++;
			}
			result[0] = toupper(result[0]);
			return result;
		}
		else if (betterRand(seed)%1000 > 666)
		{
			seed++;
			result+=TwoLetterWordSections[betterRand(seed)%5];
			//while (betterRand(seed)%500 > 80)
			for(int i = 0; i < (betterRand(seed)%10)+1; i++)
			{
				seed++;
				result+=vowels[betterRand(seed)%5];
				seed++;
				if (betterRand(seed)%100 < 50)
				{
					result+=OneLetterWordSections[betterRand(seed)%19];
				}
				else
				{
					result+=TwoLetterWordSections[betterRand(seed)%5];
				}
				seed++;
			}
			result[0] = toupper(result[0]);
			return result;
		}
		else
		{
			seed++;
			result+=vowels[betterRand(seed)%5];
			//while (betterRand(seed)%500 > 80)
			for(int i = 0; i < (betterRand(seed)%10)+1; i++)
			{
				seed++;
				if (betterRand(seed)%100 < 50)
				{
					result+=OneLetterWordSections[betterRand(seed)%19];
				}
				else
				{
					result+=TwoLetterWordSections[betterRand(seed)%5];
				}
				seed++;
				result+=vowels[betterRand(seed)%5];
				seed++;
			}

			result[0] = toupper(result[0]);
			return result;
		}
		//make up a new word
	}
}

string nameGenerator :: generatePlanetName(uint32_t seed)
{
		string result;
		seed++;
		if (betterRand(seed)%1000 < 333)
		{	
			seed++;
			result+=OneLetterWordSections[betterRand(seed)%19];
			for(int i = 0; i < (betterRand(seed)%10)+1; i++)
			{
				seed++;
				result+=randomVowelString(seed);
				seed++;
				if (betterRand(seed)%100 < 50)
				{
					result+=OneLetterWordSections[betterRand(seed)%19];
				}
				else
				{
					result+=TwoLetterWordSections[betterRand(seed)%5];
				}
				seed++;
			}
			result[0] = toupper(result[0]);
			return result;
		}
		else if (betterRand(seed)%1000 > 666)
		{
			seed++;
			result+=TwoLetterWordSections[betterRand(seed)%5];
			//while (betterRand(seed)%500 > 80)
			for(int i = 0; i < (betterRand(seed)%10)+1; i++)
			{
				seed++;
				result+=randomVowelString(seed);
				seed++;
				if (betterRand(seed)%100 < 50)
				{
					result+=OneLetterWordSections[betterRand(seed)%19];
				}
				else
				{
					result+=TwoLetterWordSections[betterRand(seed)%5];
				}
				seed++;
			}
			result[0] = toupper(result[0]);
			return result;
		}
		else
		{
			seed++;
			result+=vowels[betterRand(seed)%5];
			//while (betterRand(seed)%500 > 80)
			for(int i = 0; i < (betterRand(seed)%10)+1; i++)
			{
				seed++;
				if (betterRand(seed)%100 < 50)
				{
					result+=OneLetterWordSections[betterRand(seed)%19];
				}
				else
				{
					result+=TwoLetterWordSections[betterRand(seed)%5];
				}
				seed++;
				result+=randomVowelString(seed);
				seed++;
			}

			result[0] = toupper(result[0]);
			return result;
		}
		//make up a new word
}

string nameGenerator :: randomVowelString(uint32_t seed)
{
	//seed+=999999941;
	if (betterRand(seed)%1000 > 750)
	{
		seed++;
		return vowels[betterRand(seed)%5];
	}
	else
	{
		seed++;
		return doublevowels[betterRand(seed)%15];
	}
}