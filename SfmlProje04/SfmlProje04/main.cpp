#include<SFML\Graphics.hpp>
#include<iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "ilk Pencerem");

	window.setFramerateLimit(60);

	sf::CircleShape daire(30.0f);


	daire.setFillColor(sf::Color(0, 255, 0));

	daire.setOutlineThickness(5.0f);

	daire.setOutlineColor(sf::Color(255, 0, 0));

	daire.setPosition(100, 100);

	int x = 100;
	int y = 100;
	auto pozisyon = daire.getPosition();

	while (window.isOpen())
	{

		sf::Event event;

		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Left)
					x++;
				if (event.key.code == sf::Keyboard::Right)
					x--;
			}
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Left)
				{
					x = 0;
				}
			}

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					x = event.mouseButton.x;
					y = event.mouseButton.y;


				}
			}
			if (event.type == sf::Event::MouseMoved)
			{
				x = event.mouseMove.x;
				y = event.mouseMove.y;
			}

		}

		daire.setPosition(x, y);

		window.clear(sf::Color::Blue);

		window.draw(daire);


		window.display();



	}
	return 0;
}