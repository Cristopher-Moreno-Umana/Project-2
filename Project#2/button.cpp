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

void Button::draw(sf::RenderTarget& target)
{
	if (this->rectangle.getSize().x > 0 && rectangle.getSize().y > 0)
	{
		target.draw(rectangle);
	}
	else if (this->circle.getRadius() > 0)
	{
		target.draw(circle);
	}
	else if (!this->text.getString().isEmpty())
	{
		target.draw(text);
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

void Button::followMouse(Button& aButton, sf::RenderWindow& aWindow)
{
	float mouseX = static_cast<float>(Mouse::getPosition(aWindow).x);
	float mouseY = static_cast<float>(Mouse::getPosition(aWindow).y);

	if (aButton.getCircleShape().getRadius() > 0)
	{
		aButton.getCircleShape().setPosition(mouseX, mouseY);
	}
	else if (aButton.getRectangle().getSize().x > 0 && aButton.getRectangle().getSize().y > 0)
	{
		aButton.getRectangle().setPosition(mouseX, mouseY);
	}
	else if (!aButton.getText().getString().isEmpty())
	{
		aButton.getText().setPosition(mouseX, mouseY);
	}
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


