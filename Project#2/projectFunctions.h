#ifndef projectFuctions_h
#define projectFuctions_h

#include "button.h"
#include "touristSpot.h"
#include "nodeTouristSpot.h"
#include "touristRoute.h"
#include "textField.h"
#include "colorPalette.h"

void menu();
void loadMap(Texture& aMapTexture);

void handleWindowMap();
void loadFont(Font& aFont);
void fillTextArray(Text aMenuText[], Font& aFont);
void showTextArray(Text aText[], RenderWindow& aWindow, int aSize);
void handleMenuKeyPress(Event& anEvent, Text aMenuText[], RenderWindow& aWIndow);
void inputTouristRouteData(ColorPalette aColorPalette);
void handleColorPalette(ColorPalette& aColorPalette);
#endif