#include "touristRoute.h"

TouristRoute::TouristRoute()
{
	this->head = nullptr;
	this->name = Button();
}

TouristRoute::TouristRoute(Button aNameButton)
{
	this->head = nullptr;
	this->name = aNameButton;
}

TouristRoute::~TouristRoute()
{
}

void TouristRoute::setName(Button aNameButton)
{
	this->name = aNameButton;
}

sf::String TouristRoute::getStringName()
{
	return this->name.getText().getString();
}

Button TouristRoute::getName()
{
	return this->name;
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
	cout << "\n\nPunto agregado a la ruta con exito.\n\n";
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

	while (current != nullptr && current->touristSpot.getNameString() != aTouristSpotName)
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
