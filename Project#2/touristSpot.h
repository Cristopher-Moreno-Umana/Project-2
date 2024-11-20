#ifndef touristSpot_h
#define touristSpot_h 

#include "libraries.h"
#include "button.h"

class TouristSpot
{
private:
	Text name;
	Button button;
	Color drawColor;
	Vector2f Coordinates;
	bool isSpotClicked;
public:
	TouristSpot();
	TouristSpot(Text aName, Color drawColor);
	~TouristSpot();

	void setName(Text aName);
	void setButton(Button aButton);
	void setCoordinates(Vector2f newCoordinates);
	void setIsSpotClicked(bool newIsSpotClicked);

	String getNameString();
	Button getbutton();
	Vector2f getCoordinates();
	bool getIsSpotClicked();

	void displaySpot(RenderTarget& aTarjet);

	void placeSpotButton(RenderWindow& aWindow);
};
#endif
