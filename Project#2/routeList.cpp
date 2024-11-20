#include "routeList.h"

RouteList::RouteList()
{
	this->head = nullptr;
}

void RouteList::addNewRoute(TouristRoute aTouristRoute)
{
	NodeTouristRoute* newRoute = new NodeTouristRoute(aTouristRoute);

	newRoute->next = head;

	head = newRoute;

	cout << "\n\nRuta agregada con exito.\n\n";
}

void RouteList::deleteTouristRoute(sf::String aTouristRouteName)
{
	NodeTouristRoute* current = head;
	NodeTouristRoute* previous = nullptr;

	if (head == nullptr)
	{
		cout << "\n\nNo se pueden eliminar datos de una lista vacia.\n\n";
		return;
	}

	if (head->next == nullptr)
	{
		if (head->route.getStringName() == aTouristRouteName)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			cout << "\n\nRuta no encontrada\n\n";
		}
		return;
	}

	while (current != nullptr && current->route.getStringName() != aTouristRouteName)
	{
		previous = current;
		current = current->next;
	}

	if (current == nullptr)
	{
		cout << "\n\nRuta no encontrada\n\n";
		return;
	}

	if (previous == nullptr)
	{
		head = head->next;
	}

	else
	{
		previous->next = current->next;
	}

	delete current;

	cout << "\n\nRuta eliminada con exito.\n\n";
}
