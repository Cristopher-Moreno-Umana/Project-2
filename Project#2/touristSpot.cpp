#include "touristSpot.h"

TouristSpot::TouristSpot()
{
	this->name = " ";
	this->button = Button();
}

TouristSpot::TouristSpot(string aName, Button aButton)
{
	this->name = aName;
	this->button = aButton;
}

TouristSpot::~TouristSpot()
{

}

void TouristSpot::setName(string aName)
{
	this->name = aName;
}

void TouristSpot::setButton(Button aButton)
{
	this->button = aButton;
}

string TouristSpot::getName()
{
	return this->name;
}

Button TouristSpot::getbutton()
{
	return this->button;
}
