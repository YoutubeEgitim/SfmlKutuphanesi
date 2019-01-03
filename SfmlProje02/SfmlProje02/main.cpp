#include<SFML\Window.hpp>

int main()
{
	sf::Window window(sf::VideoMode(800, 600), "ilk pencere");

	window.setSize(sf::Vector2u(200, 200));
	window.setTitle("Merhabalar");
	window.setPosition(sf::Vector2i(0, 0));

	while (window.isOpen())
	{
		sf::Event olayNesnesi;

		while (window.pollEvent(olayNesnesi))
		{
			if (olayNesnesi.type == sf::Event::Closed)
				window.close();
		}

	}
}