#include "libraries.h"
#include "button.h"
#include "projectFunctions.h"

int main()
{
    RenderWindow window(VideoMode(867, 864), "Mapa");
    
    Texture mapTexture;

    if (!mapTexture.loadFromFile("../ProjectFiles/maps/map.jpeg."))
    {
        return -1;
    }

    Sprite projectMap(mapTexture);
  
    while (window.isOpen())
    {
        Event event;
       
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        
        window.draw(projectMap);
        
        window.display();
    }
    
    return 0;
}




