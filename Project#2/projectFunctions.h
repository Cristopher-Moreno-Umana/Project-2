#ifndef projectFuctions_h
#define projectFuctions_h

#include "button.h"
#include "touristSpot.h"
#include "nodeTouristSpot.h"
#include "touristRoute.h"
#include "colorPalette.h"
#include "nodeTouristRoute.h"
#include"routeList.h"

extern sf::Font globalFont;
void loadFont();

void menu(bool* newIsTimeToPlaceSpots, bool* newIstimeToChangeColor);

void loadMap(Texture& aMapTexture);

void handleWindowMap();

void fillTextArray(Text aMenuText[]);

void showTextArray(Text aText[], RenderWindow& aWindow, int aSize);

void fillTouristSpot(ColorPalette aColorPalette, TouristSpot& newSpot);

void fillTouristRoute(TouristSpot& newSpots, TouristRoute& newRoute);

Button inputTouristRouteData(ColorPalette aColorPalette);

void handleColorPalette(ColorPalette& aColorPalette);

#endif