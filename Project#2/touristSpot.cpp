#include "touristSpot.h"

TouristSpot::TouristSpot()
{
	this->name = Text();
	this->button = Button();
	this->drawColor = Color::Blue;
	this->Coordinates = Vector2f(0, 0);
	this->isSpotClicked = false;
}

TouristSpot::TouristSpot(Text aName, Color drawColor)
{
	CircleShape circleButton(10);
	circleButton.setFillColor(drawColor);

	this->button = Button(circleButton, this->Coordinates);
	this->name = aName;

	this->name.setFillColor(drawColor);

	this->name.setPosition(this->Coordinates.x + 30, this->Coordinates.y);
}

TouristSpot::~TouristSpot()
{

}

void TouristSpot::setName(Text aName)
{
	this->name = aName;
}

void TouristSpot::setButton(Button aButton)
{
	this->button = aButton;
}

void TouristSpot::setCoordinates(Vector2f newCoordinates)
{
	this->Coordinates = newCoordinates;
	this->button.setCoordinates(Coordinates);
	this->name.setPosition(this->Coordinates.x + 30, this->Coordinates.y);
}

void TouristSpot::setIsSpotClicked(bool newIsSpotClicked)
{
	this->isSpotClicked = newIsSpotClicked;
}

String TouristSpot::getNameString()
{
	return this->name.getString();
}

Button TouristSpot::getbutton()
{
	return this->button;
}

Vector2f TouristSpot::getCoordinates()
{
	return this->Coordinates;
}

bool TouristSpot::getIsSpotClicked()
{
	return this->isSpotClicked;
}

void TouristSpot::displaySpot(RenderTarget& aTarget)
{
	if (this->button.getCircleShape().getRadius() > 0)
	{
		aTarget.draw(button.getCircleShape());
	}
	if (!this->name.getString().isEmpty())
	{
		aTarget.draw(this->name);
	}
}


void TouristSpot::placeSpotButton(RenderWindow& aWindow)
{
	static bool clicked = false;

	if (!this->isSpotClicked)
	{
		this->Coordinates = this->button.followMouse(aWindow);
		this->name.setPosition(this->Coordinates.x + 30, this->Coordinates.y);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			this->isSpotClicked = true;
		}
	}
}


