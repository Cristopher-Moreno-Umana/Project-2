#ifndef colorPalette_h
#define colorPalette_h
#include "button.h"
class ColorPalette
{
private:
	Button coloredButtons[7];
	Color colors[7];
public:
	Color drawColor;
	ColorPalette();
	~ColorPalette();
	void fillColorPalette();
	void drawPalette(RenderWindow& aWindow);
	Color selectedColor(RenderWindow& aWindow);
};
#endif
