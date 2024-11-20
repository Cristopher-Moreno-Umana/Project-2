#include "button.h"

Button::Button()
{
	this->circle = sf::CircleShape();
	this->rectangle = sf::RectangleShape();
	this->text = sf::Text();
	this->coordinates = Vector2f(0, 0);
}

Button::Button(sf::RectangleShape aRectangle, sf::Vector2f newCoordinates)
{
	this->rectangle = aRectangle;
	this->coordinates = newCoordinates;
	this->rectangle.setPosition(newCoordinates);
}

Button::Button(sf::CircleShape aCircle, sf::Vector2f newCoordinates)
{
	this->circle = aCircle;
	this->coordinates = newCoordinates;
	this->circle.setPosition(newCoordinates);
}

Button::Button(sf::Text aText, sf::Vector2f newCoordinates)
{
	this->text = aText;
	this->coordinates = newCoordinates;
	this->text.setPosition(newCoordinates);
}

Button::~Button(){}

void Button::setRectangle(sf::RectangleShape aRectangle)
{
	this->rectangle = aRectangle;
	this->rectangle.setPosition(this->coordinates);
}

void Button::setCicle(sf::CircleShape aCircle)
{
	this->circle = aCircle;
	this->circle.setPosition(this->coordinates);
}

void Button::setText(sf::Text aText)
{
	this->text = aText;
	this->text.setPosition(this->coordinates);
}

void Button::setCoordinates(Vector2f newCoordinates)
{
	this->coordinates = newCoordinates;
	this->text.setPosition(this->coordinates);
	this->circle.setPosition(this->coordinates);
	this->rectangle.setPosition(this->coordinates);
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

Vector2f Button::getCoordinates()
{
	return this->coordinates;
}

void Button::draw(sf::RenderTarget& target)
{
	if (this->rectangle.getSize().x > 0 && rectangle.getSize().y > 0)
	{
		target.draw(this->rectangle);
	}
	else if (this->circle.getRadius() > 0)
	{
		target.draw(this->circle);
	}
	else if (!this->text.getString().isEmpty())
	{
		target.draw(this->text);
	}
}

bool Button::isCursorOn(Button& aButton,sf::RenderWindow& aWindow)
{
	Vector2i mousePosition = Mouse::getPosition(aWindow);
	
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

Vector2f Button::followMouse(sf::RenderWindow& aWindow)
{
	Vector2f currentCoordinates;
	float mouseX = static_cast<float>(Mouse::getPosition(aWindow).x);
	float mouseY = static_cast<float>(Mouse::getPosition(aWindow).y);

	if (this->getCircleShape().getRadius() > 0)
	{
		this->getCircleShape().setPosition(mouseX, mouseY);
	}
	else if (this->getRectangle().getSize().x > 0 && this->getRectangle().getSize().y > 0)
	{
		this->getRectangle().setPosition(mouseX, mouseY);
	}
	else if (!this->getText().getString().isEmpty())
	{
		this->getText().setPosition(mouseX, mouseY);
	}

	currentCoordinates = Vector2f(mouseX, mouseY);

	this->setCoordinates(currentCoordinates);

	return currentCoordinates;
}

bool Button::isButtonClicked(Button& aButton, sf::RenderWindow& aWindow)
{
	return isCursorOn(aButton, aWindow) && Mouse::isButtonPressed(Mouse::Left);
}

void Button::changeTextColor(Button& aButton, sf::RenderWindow& aWindow, Text aButtonText, Color newColor)
{
	if (aButton.isCursorOn(aButton, aWindow))
	{
		aButtonText.setFillColor(newColor);
		aButton.setText(aButtonText);
	}
	else
	{
		aButtonText.setFillColor(Color::White);
		aButton.setText(aButtonText);
	}

}


