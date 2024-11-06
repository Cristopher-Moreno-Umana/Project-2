#include "button.h"

Button::Button()
{
	this->circle = sf::CircleShape();
	this->rectangle = sf::RectangleShape();
	this->text = sf::Text();
	this->text.setString(" ");
}

Button::Button(sf::RectangleShape aRectangle, 
	sf::Vector2i newCoordinates)
{
	this->rectangle = aRectangle;
	this->coordinates = newCoordinates;
	this->rectangle.setPosition(static_cast<float>(coordinates.x), static_cast<float>(coordinates.y));
}

Button::Button(sf::CircleShape aCircle,
	sf::Vector2i newCoordinates)
{
	this->circle = aCircle;
	this->coordinates = newCoordinates;
	this->circle.setPosition(static_cast<float>(coordinates.x), static_cast<float>(coordinates.y));
}

Button::Button(sf::Text aText, sf::Vector2i newCoordinates)
{
	this->text = aText;
	this->coordinates = newCoordinates;
	this->text.setPosition(static_cast<float>(coordinates.x), static_cast<float>(coordinates.y));
}

Button::~Button(){}

void Button::setRectangle(sf::RectangleShape aRectangle)
{
	this->rectangle = aRectangle;
	this->text.setPosition(static_cast<float>(coordinates.x), static_cast<float>(coordinates.y));
}

void Button::setCicle(sf::CircleShape aCircle)
{
	this->circle = aCircle;
	this->text.setPosition(static_cast<float>(coordinates.x), static_cast<float>(coordinates.y));
}

void Button::setText(sf::Text aText)
{
	this->text = aText;
	this->text.setPosition(static_cast<float>(coordinates.x), static_cast<float>(coordinates.y));
}

void Button::setCoordinates(sf::Vector2i newCoordinates)
{
	this->coordinates = newCoordinates;
}

sf::RectangleShape Button::getRectangle()
{
	return this->rectangle;
}

sf::CircleShape Button::getCircleShape()
{
	return this->circle;
}

sf::Text Button::getText()
{
	return this->text;
}

sf::Vector2i Button::getCoordinates()
{
	return this->coordinates;
}


void Button::draw(sf::RenderTarget& target)
{
	if (rectangle.getSize().x > 0 && rectangle.getSize().y > 0) 
	{
		target.draw(rectangle);
	}
	if (circle.getRadius() > 0)
	{
		target.draw(circle);
	}
	target.draw(text);
}

bool Button::isCursorOn(Button aButton,sf::RenderWindow& aWindow)
{
	Vector2i mousePosition = Mouse::getPosition();
	
	float positionX = static_cast<float>(mousePosition.x);
	float positionY = static_cast<float>(mousePosition.y);
	
	bool isOnRectangleButton =
		(aButton.getRectangle().getGlobalBounds().contains(positionX, positionY));
	bool isOnCircleButton =
		aButton.getCircleShape().getGlobalBounds().contains(positionX, positionY);
	bool isOnTextButton = 
		aButton.getText().getGlobalBounds().contains(positionX, positionY);

	return isOnRectangleButton || isOnCircleButton  || isOnTextButton;
}

void Button::followMouse(Button& aButton, sf::RenderWindow& aWindow)
{
	aButton.coordinates.x = Mouse::getPosition(aWindow).x;
	aButton.coordinates.y = Mouse::getPosition(aWindow).y;
}

bool Button::isButtonClicked(Button& aButton, sf::RenderWindow& aWindow)
{
	return isCursorOn(aButton, aWindow) && Mouse::isButtonPressed(Mouse::Left);
}


