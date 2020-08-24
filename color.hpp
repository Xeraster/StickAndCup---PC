color :: color()
{

}

color :: color(int r, int g, int b)
{
	red = r;
	green = g;
	blue = b;
	alpha = 255;
}

color :: color(int r, int g, int b, int a)
{
	red = r;
	green = g;
	blue = b;
	alpha = a;
}

int color :: getRed() const
{
	return red;
}

int color :: getGreen() const
{
	return green;
}

int color :: getBlue() const
{
	return blue;
}

int color :: getAlpha() const
{
	return alpha;
}

color color::operator=(const color& rhs)
{
	red = rhs.getRed();
	green = rhs.getGreen();
	blue = rhs.getBlue();
	alpha = rhs.getAlpha();
	return *this;
}

bool color::operator==(const color& rhs)
{
	if (rhs.getBlue() == blue && rhs.getGreen() == green && rhs.getRed() == red && rhs.getAlpha() == alpha)
	{
		return true;
	}
	return false;
}