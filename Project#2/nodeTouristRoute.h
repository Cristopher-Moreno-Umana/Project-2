#ifndef nodeTouristRoute_h
#define nodeTouristRoute_h

#include "touristRoute.h"

class NodeTouristRoute
{
public:
	TouristRoute route;
	NodeTouristRoute* next;
	NodeTouristRoute(TouristRoute aRoute);
};
#endif
