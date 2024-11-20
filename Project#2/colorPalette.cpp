#include "colorPalette.h"

ColorPalette::ColorPalette()
{
    this->drawColor = Color::Blue;
	fillColorPalette();
}

ColorPalette::~ColorPalette()
{

}

void ColorPalette::fillColorPalette()
{
    Vector2f coordinates(45, 30);
    RectangleShape rectangleButton(Vector2f(50, 50));
    
    this->colors[0] = Color::Blue;
    this->colors[1] = Color::Cyan;
    this->colors[2] = Color::Green;
    this->colors[3] = Color::Magenta;
    this->colors[4] = Color::Red;
    this->colors[5] = Color::White;
    this->colors[6] = Color::Yellow;

    for (int i = 0; i < 7; i++)
    {
        rectangleButton.setFillColor(this->colors[i]);
        this->coloredButtons[i] = Button(rectangleButton, coordinates);
        coordinates.x += 55;
    }
}

void ColorPalette::drawPalette(RenderWindow& aWindow)
{
    for (int i = 0; i < 7; i++)
    {
        this->coloredButtons[i].draw(aWindow);
    }
}

Color ColorPalette::selectedColor(RenderWindow& aWindow)
{
    for (int i = 0; i < 7; i++)
    {
        if (this->coloredButtons[i].isButtonClicked(coloredButtons[i], aWindow))
        {
            drawColor = coloredButtons[i].getRectangle().getFillColor();
            cout << "\n\nColor seleccionado con exito.\n\n";
            aWindow.close();
        }
    }
    return drawColor;
}
