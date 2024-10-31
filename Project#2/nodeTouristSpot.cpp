#include "nodeTouristSpot.h"

NodeTouristSpot::NodeTouristSpot(TouristSpot aTouristSpot)
{
	this->touristSpot = aTouristSpot;
	this->next = nullptr;
	this->previous = nullptr;
}
