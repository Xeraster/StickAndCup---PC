#ifndef COLOR_H
#define COLOR_H

class color
{
public:
	color();

	color(int r, int g, int b);

	color(int r, int g, int b, int a);

	int getRed() const;
	int getGreen() const;
	int getBlue() const;
	int getAlpha() const;

	color operator=(const color& rhs);

	bool operator==(const color& rhs);

protected:
	int red;
	int green;
	int blue;
	int alpha;

};

#include "color.hpp"

#endif