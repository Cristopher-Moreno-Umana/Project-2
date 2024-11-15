#include "textField.h"

TextField::TextField()
{
	this->cursor = RectangleShape();
	this->inputText = " ";
	this->showText = Text();
	this->isCursorVisible = false;
	this->isInputFinished = false;
}

TextField::TextField(sf::String newInputText, Vector2f newCoordinates, Font& aFont)
{
	this->inputText = newInputText;
	this->isCursorVisible = true;
	this->isInputFinished = false;

	this->showText.setString(this->inputText);
	this->showText.setFont(aFont);
	this->showText.setCharacterSize(30);
	this->showText.setFillColor(sf::Color::White);
	this->showText.setPosition(newCoordinates);

	this->cursor.setSize(sf::Vector2f(2.f, 30.f));
	this->cursor.setFillColor(sf::Color::Black);

}

TextField::~TextField()
{
}

void TextField::handleCursorBlink(RenderWindow& aWindow)
{
	if (blinkClock.getElapsedTime().asSeconds() >= blinkInterval)
	{
		isCursorVisible = !isCursorVisible;
		blinkClock.restart();
	}

	if (isCursorVisible)
	{
		cursor.setPosition(showText.getPosition().x + showText.getLocalBounds().width, showText.getPosition().y);
		aWindow.draw(cursor);
	}
}

void TextField::handleKeyboardInput(Event anEvent, size_t aStringSize)
{
	int const KEY_ENTER_CODE = 13, KEY_BACKSPACE_CODE = 8, ALLOWED_KEYS = 128;

	if (anEvent.type == Event::TextEntered)
	{
		if (anEvent.text.unicode < ALLOWED_KEYS)
		{
			if (anEvent.text.unicode == KEY_BACKSPACE_CODE && !inputText.isEmpty())
			{
				inputText.erase(inputText.getSize() - 1, 1);
			}
			else if (anEvent.text.unicode != KEY_BACKSPACE_CODE && anEvent.text.unicode != KEY_ENTER_CODE &&
				inputText.getSize() < aStringSize)
			{
				
				inputText += static_cast<char>(anEvent.text.unicode);
			}
			if (anEvent.text.unicode == KEY_ENTER_CODE)
			{
				this->isInputFinished = true;
			}
		}
	}
	showText.setString(inputText);
}

void TextField::drawText(RenderTarget& aTarget)
{
	if (!inputText.isEmpty())
	{
		aTarget.draw(this->showText);
	}
}

std::string TextField::getText()
{
	return inputText.toAnsiString();
}

bool TextField::isInputCompleted()
{
	return this->isInputFinished;
}