#ifndef Button_h
#define Button_h

#include "libraries.h"

class Button
{

private:
	sf::RectangleShape rectangle;
	sf::CircleShape circle;
	sf::Text text;
	sf::Vector2i coordinates;
	
public:

	Button();
	Button(sf::RectangleShape aRectangle,sf::Vector2i newCoordinates);
	Button(sf::CircleShape aCircle, sf::Vector2i newCoordinates);
	Button(sf::Text aText, sf::Vector2i newCoordinates);
	
	~Button();

	void setRectangle(sf::RectangleShape aRectangle);
	void setCicle(sf::CircleShape aCircle);
	void setText(sf::Text aText);
	void setCoordinates(sf::Vector2i newCoordinates);

	sf::RectangleShape getRectangle();
	sf::CircleShape getCircleShape();
	sf::Text getText();
	sf::Vector2i getCoordinates();

	void draw(sf::RenderTarget& target);
	bool isCursorOn(Button aButton, sf::RenderWindow& aWindow);
	void followMouse(Button& aButton, sf::RenderWindow& aWindow);
	bool isButtonClicked(Button& aButton, sf::RenderWindow& aWindow);
};

#endif
