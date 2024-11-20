#ifndef touristRoute_h
#define touristRoute_h

#include "nodeTouristSpot.h"

class TouristRoute
{
private:
	Button name;
public:
	NodeTouristSpot* head;

	TouristRoute();
	TouristRoute(Button aNameButton);
	~TouristRoute();

	void setName(Button aNameButton);

	sf::String getStringName();
	Button getName();

	void addNewTouristSpot(TouristSpot aTouristSpot);
	void deleteTouristSpot(string aTouristSpotName);
};

#endif 



