#include "projectFunctions.h"

void menu()
{
    RenderWindow menuWindow(VideoMode(800, 400), "Menu");
    
    Font projectFont; 
    loadFont(projectFont);
    
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
        }

        menuWindow.clear(Color::Black);

        showTextArray(menuText, menuWindow);
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

void manageWindowMap()
{
    Texture mapTexture;
    
    loadMap(mapTexture);

    Sprite projectMap(mapTexture);

    RenderWindow mapWindow(VideoMode(867, 864), "Mapa");

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

        mapWindow.draw(projectMap);

        mapWindow.display();

    }
}

void loadFont(Font& aFont)
{
    if (!aFont.loadFromFile("../ProjectFiles/fonts/arial/arial.ttf"))
    {
        exit(EXIT_FAILURE);
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

void showTextArray(Text aMenuText[], RenderWindow& aWindow)
{
    
    for (int i = 0; i < 3; i++)
    {
     
        aWindow.draw(aMenuText[i]);
    }
}

void handleKeyPress(Event& anEvent)
{

}
