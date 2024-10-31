#ifndef touristRoute_h
#define touristRoute_h

#include "nodeTouristSpot.h"

class TouristRoute
{
public:
	NodeTouristSpot* head;

	TouristRoute();
	
	void addNewTouristSpot(TouristSpot aTouristSpot);
	void deleteTouristSpot(string aTouristSpotName);
};

#endif 



