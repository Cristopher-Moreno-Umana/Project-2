#include "projectFunctions.h"

void menu()
{
    RenderWindow menuWindow(VideoMode(800, 400), "Menu");
    
    Font projectFont; 
    loadFont(projectFont);
    
    int vectorSize = 3;
    Text menuText[3];
    fillTextArray(menuText,projectFont);

    if (!menuWindow.isOpen())
    {
        exit(EXIT_FAILURE);
    }

    while (menuWindow.isOpen())
    {
        Event menuEvent;

        while (menuWindow.pollEvent(menuEvent))
        {
            if (menuEvent.type == Event::Closed)
            {
                menuWindow.close();
            }

            handleMenuKeyPress(menuEvent,menuText, menuWindow);        
        }
       
        menuWindow.clear(Color::Black);

        showTextArray(menuText, menuWindow, vectorSize);
        menuWindow.display();
    }

}

void loadMap(Texture& aMapTexture)
{
    if (!aMapTexture.loadFromFile("../ProjectFiles/maps/map.jpeg"))
    {
        exit(EXIT_FAILURE);
    }
}

void loadFont(Font& aFont)
{
    if (!aFont.loadFromFile("../ProjectFiles/fonts/arial/arial.ttf"))
    {
        exit(EXIT_FAILURE);
    }
}

void handleWindowMap()
{
    Texture mapTexture;
    
    loadMap(mapTexture);

    Sprite projectMap(mapTexture);

    RenderWindow mapWindow(VideoMode(867, 864), "Mapa");

    Font mainWindowFont;
    loadFont(mainWindowFont);
    
    Text menuButtonText("Menu", mainWindowFont, 35);
    Button menuButton;

    if (!mapWindow.isOpen()) 
    {
        exit(EXIT_FAILURE);
    }

    while (mapWindow.isOpen())
    {
        Event event;

        while (mapWindow.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                mapWindow.close();
            }
            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::M)
                {
                    menu();
                }
            }
        }        
       
        mapWindow.clear();

        menuButton = Button(menuButtonText, Vector2f(0, 0));
        menuButton.changeTextColor(menuButton, mapWindow, menuButtonText,Color::Blue);
        
        if (menuButton.isButtonClicked(menuButton, mapWindow))
        {
            menu();
        }

        mapWindow.draw(projectMap);
        menuButton.draw(mapWindow);
        mapWindow.display();       
    }
}

void fillTextArray(Text aMenuText[], Font& aFont)
{
    aMenuText[0] = Text::Text("Presione la tecla segun la opcion:", aFont, 20);
    aMenuText[1] = Text::Text("1: Insertar nueva ruta turistica", aFont, 20);
    aMenuText[2] = Text::Text("2: Cambiar colores de dibujo", aFont, 20);

    aMenuText[0].setPosition(0, 0);
    aMenuText[1].setPosition(0, 30);
    aMenuText[2].setPosition(0, 60);

    aMenuText[0].setFillColor(Color::Red);
    aMenuText[1].setFillColor(Color::Green);
    aMenuText[2].setFillColor(Color::Green);
}

void showTextArray(Text aText[], RenderWindow& aWindow, int aSize)
{    
    for (int i = 0; i < aSize; i++)
    {
        aWindow.draw(aText[i]);
    }
}

void handleMenuKeyPress(Event& anEvent, Text aMenuText[], RenderWindow& aWindow)
{
    ColorPalette colorPalette;
    Clock timerClock;
    if (anEvent.type == Event::KeyPressed)
    {
        if (anEvent.key.code == Keyboard::Num1 || anEvent.key.code == Keyboard::Numpad1)
        {
            aWindow.close();
            inputTouristRouteData(colorPalette);
                        
        }
       
        if (anEvent.key.code == Keyboard::Num2 || anEvent.key.code == Keyboard::Numpad2)
        {
            aWindow.close();
            handleColorPalette(colorPalette);

            cout << "\n\nColor seleccionado con exito.\n\n";

        }
    }
}

void inputTouristRouteData(ColorPalette aColorPalette)
{
    Text options[2];

    Font textFont;
    loadFont(textFont);

    options[0] = Text("Ingrese el nombre de la Ruta:", textFont, 20);
    options[0].setPosition(0, 0);

    options[1] = Text("Ingrese el numero de puntos turisticos:", textFont, 20);
    options[1].setPosition(0, 30);
    
    RenderWindow inputDataWindow(VideoMode(800, 400), "Insertar Ruta");

    if (!inputDataWindow.isOpen())
    {
        exit(EXIT_FAILURE);
    }

    while (inputDataWindow.isOpen())
    {
        Event event;

        while (inputDataWindow.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                inputDataWindow.close();
            }
        }

        inputDataWindow.clear(Color::Black);

        inputDataWindow.display();
    }
}

void handleColorPalette(ColorPalette& aColorPalette)
{
    Text option;

    Font optionFont;
    loadFont(optionFont);

    option = Text("Haga click sobre un boton para seleccionar el color: ", optionFont, 20);
    
    option.setPosition(0, 0);

    aColorPalette.fillColorPalette();

    RenderWindow colorPaletteWindow(VideoMode(475, 100), "Paleta de colores");

    if (!colorPaletteWindow.isOpen())
    {
        exit(EXIT_FAILURE);
    }

    while (colorPaletteWindow.isOpen())
    {
        Event event;

        while (colorPaletteWindow.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                colorPaletteWindow.close();
            }
            aColorPalette.selectedColor(colorPaletteWindow);
        }

        colorPaletteWindow.clear(Color::Black);
        colorPaletteWindow.draw(option);
       
        aColorPalette.drawPalette(colorPaletteWindow);

        colorPaletteWindow.display();
    }      
}



