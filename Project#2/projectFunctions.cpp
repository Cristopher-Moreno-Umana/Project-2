#include "projectFunctions.h"

Font globalFont;

void loadFont()
{
    if (!globalFont.loadFromFile("../ProjectFiles/fonts/arial/arial.ttf"))
    {
        exit(EXIT_FAILURE);
    }
}

void menu(bool* newIsTimeToPlaceSpots, bool* newIstimeToChangeColor)
{
    RenderWindow menuWindow(VideoMode(800, 400), "Menu");
    
    int vectorSize = 4;
    Text menuText[4];
    fillTextArray(menuText);

    ColorPalette colorPalette;

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

            if (menuEvent.type == Event::KeyPressed)
            {
                if (menuEvent.key.code == Keyboard::Num1 || menuEvent.key.code == Keyboard::Numpad1)
                {
                    menuWindow.close();
                    
                    *newIsTimeToPlaceSpots = true;
                }

                if (menuEvent.key.code == Keyboard::Num2 || menuEvent.key.code == Keyboard::Numpad2)
                {
                    menuWindow.close();

                    *newIstimeToChangeColor = true;
                }
            }
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

void handleWindowMap()
{
    Texture mapTexture;

    loadMap(mapTexture);

    Sprite projectMap(mapTexture);

    RenderWindow mapWindow(VideoMode(867, 864), "Mapa");

    Text menuButtonText("Menu", globalFont, 30);
    Button menuButton;

    ColorPalette colorPalette;

    bool isTimeToPlaceSpots = false;
    bool isTimeToChangeColor = false;

    TouristRoute route;
    TouristSpot spot;

    RouteList routeList;

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
                    menu(&isTimeToPlaceSpots, &isTimeToChangeColor);
                }
            }
        }

        mapWindow.clear();

        menuButton = Button(menuButtonText, Vector2f(400, 0));
        menuButton.changeTextColor(menuButton, mapWindow, menuButtonText, Color::Green);

        if (menuButton.isButtonClicked(menuButton, mapWindow))
        {
            menu(&isTimeToPlaceSpots, &isTimeToChangeColor);
        }

        mapWindow.draw(projectMap);
        menuButton.draw(mapWindow);

        if (isTimeToPlaceSpots)
        {
            fillTouristSpot(colorPalette, spot);
            isTimeToPlaceSpots = false;
        }

        if (isTimeToChangeColor)
        {
            handleColorPalette(colorPalette);
            isTimeToChangeColor = false;
        }

        if (!spot.getNameString().isEmpty() && !spot.getIsSpotClicked())
        {
            route = TouristRoute(inputTouristRouteData(colorPalette));
            fillTouristRoute(spot, route);
        }

        spot.placeSpotButton(mapWindow);
        spot.displaySpot(mapWindow);
       

        if (!route.getStringName().isEmpty())
        {
            route.getName().draw(mapWindow);
        }

        mapWindow.display();
    }
}

void fillTextArray(Text aMenuText[])
{
    aMenuText[0] = Text::Text("Presione la TECLA segun la opcion:", globalFont, 20);
    aMenuText[1] = Text::Text("1: Insertar nueva ruta turistica", globalFont, 20);
    aMenuText[2] = Text::Text("2: Cambiar colores de dibujo", globalFont, 20);
    aMenuText[3] = Text::Text("Si selecciona 1: dirijase a la consola e ingrese la informacion solicitada.", globalFont, 20);


    aMenuText[0].setPosition(0, 0);
    aMenuText[1].setPosition(0, 30);
    aMenuText[2].setPosition(0, 60);
    aMenuText[3].setPosition(Vector2f(0, 90));

    aMenuText[0].setFillColor(Color::Red);
    aMenuText[1].setFillColor(Color::Green);
    aMenuText[2].setFillColor(Color::Green);
    aMenuText[3].setFillColor(Color::Green);
}

void showTextArray(Text aText[], RenderWindow& aWindow, int aSize)
{
    for (int i = 0; i < aSize; i++)
    {
        aWindow.draw(aText[i]);
    }
}

void fillTouristSpot(ColorPalette aColorPalette, TouristSpot& newSpot)
{
    string touristSpotName;

    cout << "\nIngrese el nombre del punto turistico: ";
    cin >> touristSpotName;

    Text spotName(touristSpotName, globalFont, 15);

    newSpot = TouristSpot(spotName, aColorPalette.drawColor);

    cout << "\n\nPunto creado con exito.\n";
    cout << "\n\nMinimice esta venta, dirijase al mapa y coloque con el click derecho el o los puntos.\n";
    cout << "\nUna vez colocados vuelva a esta ventana.\n\n";
}

void fillTouristRoute(TouristSpot& newSpot, TouristRoute& newRoute)
{
    newRoute.addNewTouristSpot(newSpot);
}

Button inputTouristRouteData(ColorPalette aColorPalette)
{
    string touristRouteName;

    cout << "\n\nIngrese el nombre de la ruta turistica: ";
    cin >> touristRouteName;

    Text touristRouteText(touristRouteName, globalFont, 30);
    touristRouteText.setFillColor(aColorPalette.drawColor);

    Button touristRouteButton(touristRouteText, Vector2f(0, 0));

    return touristRouteButton;
}

void handleColorPalette(ColorPalette& aColorPalette)
{
    Text option;

    option = Text("Haga click sobre un boton para seleccionar el color: ", globalFont, 20);

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