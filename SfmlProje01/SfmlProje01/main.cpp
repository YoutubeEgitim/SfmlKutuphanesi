#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::CircleShape shape(100.f);
	window.setFramerateLimit(60);
	shape.setFillColor(sf::Color::Green);
	int x = 0;
	int y = 0;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		shape.setPosition(sf::Vector2f(x, y));
		window.clear();
		window.draw(shape);
		window.display();
		
		x++;
	}

	return 0;
}