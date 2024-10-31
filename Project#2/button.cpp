#include "button.h"

Button::Button()
{
	this->circle = sf::CircleShape();
	this->rectangle = sf::RectangleShape();
	this->text = sf::Text();
	this->text.setString(" ");
}

Button::Button(sf::RectangleShape aRectangle, 
	sf::Vector2i newCoordinates, sf::Mouse newMouseData)
{
	this->rectangle = aRectangle;
	this->coordinates = newCoordinates;
	this->mouseData = newMouseData;
	this->rectangle.setPosition(static_cast<float>(coordinates.x), static_cast<float>(coordinates.y));
}

Button::Button(sf::CircleShape aCircle,
	sf::Vector2i newCoordinates, sf::Mouse newMouseData)
{
	this->circle = aCircle;
	this->coordinates = newCoordinates;
	this->mouseData = newMouseData;
	this->circle.setPosition(static_cast<float>(coordinates.x), static_cast<float>(coordinates.y));
}

Button::Button(sf::Text aText, sf::Vector2i newCoordinates,
	sf::Mouse newMouseData)
{
	this->text = aText;
	this->coordinates = newCoordinates;
	this->mouseData = newMouseData;
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

void Button::setMouseData(sf::Mouse newMouseData)
{
	this->mouseData = newMouseData;
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

sf::Vector2i Button::getCoodinates()
{
	return this->coordinates;
}

sf::Mouse Button::getMouseData()
{
	return this->mouseData;
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

double Button::getTextArea()
{
	double totalArea;
	sf::FloatRect textBound = this->text.getGlobalBounds();
	
	totalArea = textBound.width * textBound.height;
	return totalArea;
}

bool Button::isCursorOn(Button aButton,sf::RenderWindow& aWindow)
{
	if (aButton.getRectangle().getGlobalBounds().
		contains(static_cast<float>(aButton.getMouseData().getPosition(aWindow).x),
			static_cast<float>(aButton.getMouseData().getPosition(aWindow).y)))
	{	
		return true;
	}
	if (aButton.getRectangle().getGlobalBounds().
		contains(static_cast<float>(aButton.getMouseData().getPosition(aWindow).x),
			static_cast<float>(aButton.getMouseData().getPosition(aWindow).y)))
	{
		return true;
	}
	if (aButton.getText().getGlobalBounds().
		contains(static_cast<float>(aButton.getMouseData().getPosition(aWindow).x),
			static_cast<float>(aButton.getMouseData().getPosition(aWindow).y)))
	{

		//button.getText().setCharacterSize()
		return true;
	}
	return false;
}




