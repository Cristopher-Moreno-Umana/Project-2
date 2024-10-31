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
	sf::Mouse mouseData;
	
public:

	Button();
	Button(sf::RectangleShape aRectangle, 
		sf::Vector2i newCoordinates, sf::Mouse newMouseData);
	Button(sf::CircleShape aCircle, sf::Vector2i newCoordinates, sf::Mouse newMouseData);
	Button(sf::Text aText, sf::Vector2i newCoordinates, sf::Mouse newMouseData);
	
	~Button();

	void setRectangle(sf::RectangleShape aRectangle);
	void setCicle(sf::CircleShape aCircle);
	void setText(sf::Text aText);
	void setCoordinates(sf::Vector2i newCoordinates);
	void setMouseData(sf::Mouse newMouseData);

	sf::RectangleShape getRectangle();
	sf::CircleShape getCircleShape();
	sf::Text getText();
	sf::Vector2i getCoodinates();
	sf::Mouse getMouseData();

	void draw(sf::RenderTarget& target);
	double getTextArea();
	bool isCursorOn(Button aButton, sf::RenderWindow& aWindow);
	
};

#endif
