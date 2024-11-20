#ifndef Button_h
#define Button_h

#include "libraries.h"

class Button
{

private:
	RectangleShape rectangle;
	CircleShape circle;
	Text text;
	Vector2f coordinates;
public:

	Button();
	Button(sf::RectangleShape aRectangle,sf::Vector2f newCoordinates);
	Button(sf::CircleShape aCircle, sf::Vector2f newCoordinates);
	Button(sf::Text aText, sf::Vector2f newCoordinates);
	
	~Button();

	void setRectangle(sf::RectangleShape aRectangle);
	void setCicle(sf::CircleShape aCircle);
	void setText(sf::Text aText);
	void setCoordinates(Vector2f newCoordinates);

	RectangleShape getRectangle();
	CircleShape getCircleShape();
	Text getText();
	Vector2f getCoordinates();

	void draw(sf::RenderTarget& target);
	bool isCursorOn(Button& aButton, sf::RenderWindow& aWindow);
	Vector2f followMouse(sf::RenderWindow& aWindow);
	bool isButtonClicked(Button& aButton, sf::RenderWindow& aWindow);
	void changeTextColor(Button& aButton, sf::RenderWindow& aWindow, Text aButtonText, Color newColor);
};

#endif
