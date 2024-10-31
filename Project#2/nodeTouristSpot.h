#ifndef nodeTouristSpot_h
#define nodeTouristSpot_h

#include"touristSpot.h"

class NodeTouristSpot
{
public:
	TouristSpot touristSpot;
	NodeTouristSpot* next;
	NodeTouristSpot* previous;
	NodeTouristSpot(TouristSpot aTouristSpot);
};
#endif
