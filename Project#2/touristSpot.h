#ifndef touristSpot_h
#define touristSpot_h

#include "libraries.h"
#include "button.h"

class TouristSpot
{
private:
	string name;
	Button button;
public:
	TouristSpot();
	TouristSpot(string aName, Button aButton);
	~TouristSpot();

	void setName(string aName);
	void setButton(Button aButton);

	string getName();
	Button getbutton();
};
#endif
