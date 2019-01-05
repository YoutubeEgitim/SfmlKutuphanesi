#include<SFML\Graphics.hpp>
#include<iostream>

int x = 100;
int y = 100;
sf::CircleShape daire(30.0f,180);
bool cizimBasladimi = false;
void klavyeKontrol(sf::Event& event)
{
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
}

void fareKontrol(sf::Event& event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			x = event.mouseButton.x;
			y = event.mouseButton.y;

			daire.setRadius(1);
			cizimBasladimi = true;

		}
	}
	if (event.type == sf::Event::MouseButtonReleased)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{

			cizimBasladimi = false;

		}
	}
	if (event.type == sf::Event::MouseMoved)
	{
		float yeniX = event.mouseMove.x;
		float yeniY = event.mouseMove.y;

		float yariCap = abs(x - yeniX)/2;

		if (cizimBasladimi)
		{
			daire.setRadius(yariCap);
		}
		
	}
}

int main()
{
	sf::ContextSettings settings;

	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "ilk Pencerem", sf::Style::Default, settings);


	window.setFramerateLimit(60);

	


	daire.setFillColor(sf::Color(0, 255, 0));

	daire.setOutlineThickness(5.0f);

	daire.setOutlineColor(sf::Color(255, 0, 0));

	daire.setPosition(100, 100);


	auto pozisyon = daire.getPosition();

	while (window.isOpen())
	{

		sf::Event event;

		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();

			klavyeKontrol(event);
			fareKontrol(event);



		}

		daire.setPosition(x, y);

		window.clear(sf::Color::Blue);

		window.draw(daire);


		window.display();



	}
	return 0;
}