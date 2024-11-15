#ifndef textField_h
#define textField_h
#include "libraries.h"
class TextField
{
private:
	sf::String inputText;
	Text showText;
	RectangleShape cursor;
	Clock blinkClock;
	bool isCursorVisible;
	const float blinkInterval = 0.5f;
	bool isInputFinished;
public:
	TextField();
	TextField(sf::String newInputText, Vector2f newCoordinates, Font& aFont);
	~TextField();

	void handleCursorBlink(RenderWindow& aWindow);
	void handleKeyboardInput(Event anEvent, size_t aStringSize);
	void drawText(RenderTarget& aTarget);
	std::string getText();
	bool isInputCompleted();
};
#endif 


