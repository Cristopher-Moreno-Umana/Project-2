#ifndef routeList_h
#define routeList_h

#include "nodeTouristRoute.h"

class RouteList
{
public:
	NodeTouristRoute* head;
	
	RouteList();

	void addNewRoute(TouristRoute aTouristRoute);
	void deleteTouristRoute(sf::String aTouristRouteName);
};
#endif
