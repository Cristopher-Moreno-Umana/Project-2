#ifndef projectFuctions_h
#define projectFuctions_h

#include "button.h"
#include "touristSpot.h"
#include "nodeTouristSpot.h"
#include "touristRoute.h"


void menu();
void loadMap(Texture& aMapTexture);

void manageWindowMap();
void loadFont(Font& aFont);
void fillTextArray(Text aMenuText[], Font& aFont);
void showTextArray(Text aMenuText[], RenderWindow& aWindow);
void handleKeyPress(Event& anEvent);
#endif