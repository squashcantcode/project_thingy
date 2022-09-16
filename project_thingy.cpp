#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
using namespace sf;
using namespace std;

int main()
{
    // Create a video mode object
    VideoMode vm(1920, 1080);

	// Create and open a window for the game
    RenderWindow window(vm, "Game", Style::Fullscreen);

    Vector2f v = {1,1};
    RectangleShape rect(Vector2f{20,10});

    vector<Vector2f> vertices;
    vector<Vector2f> points;

    Vector2f clicked;

    Event event;

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }

        if (event.type == sf::Event::MouseButtonPressed)
        {       
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                std::cout << "the left button was pressed" << std::endl;
                std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                std::cout << "mouse y: " << event.mouseButton.y << std::endl;

                clicked.x = event.mouseButton.x;
                clicked.y = event.mouseButton.y;
            }
        }
    }

    while (window.isOpen())
	{
		/*
		****************************************
		Handle the players input
		****************************************
		*/
        
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

        rect.setPosition(clicked.x, clicked.y);
        rect.setFillColor(Color::Red);

        // Clear everything from the last frame
            window.clear();
        // Draw our game scene here
		    window.draw(rect);
        // Show everything we just drew
		    window.display();
    }
    return 0;
}