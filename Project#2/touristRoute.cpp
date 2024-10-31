#include "touristRoute.h"

TouristRoute::TouristRoute()
{
	this->head = nullptr;
}

void TouristRoute::addNewTouristSpot(TouristSpot aTouristSpot)
{
	NodeTouristSpot* newNodeTouristSpot = new NodeTouristSpot(aTouristSpot);

	newNodeTouristSpot->next = head;
	
	if (head != nullptr)
	{
		head->previous = newNodeTouristSpot;
	}

	newNodeTouristSpot->previous = nullptr;
	
	head = newNodeTouristSpot;
}

void TouristRoute::deleteTouristSpot(string aTouristSpotName)
{
	if (head == nullptr)
	{
		cout << "\n\nNo se pueden eliminar elementos de una lista vacia.\n\n";
		return;
	}
	NodeTouristSpot* current = head;
	NodeTouristSpot* previous = nullptr;

	while (current != nullptr && current->touristSpot.getName() != aTouristSpotName)
	{
		previous = current;
		current = current->next;
	}

	if (current == nullptr)
	{
		cout << "\n\nPunto turistico no encontrado.\n";
		cout << "Verifica que su nombre fuera escrito correctamente.\n\n";
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

	cout << "\n\nPunto turistico eliminado con exito";
}
