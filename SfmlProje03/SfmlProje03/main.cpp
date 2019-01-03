#include<SFML\Graphics.hpp>


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
		}

		daire.setPosition(x, y);

		window.clear(sf::Color::Blue);

		window.draw(daire);


		window.display();
		x++;


	}
	return 0;
}