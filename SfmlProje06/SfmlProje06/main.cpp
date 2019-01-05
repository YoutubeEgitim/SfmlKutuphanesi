#include<SFML\Graphics.hpp>
#include<vector>

int x = 100;
int y = 100;

sf::CircleShape *aktifSekil = nullptr;
bool cizimBasladimi = false;



std::vector<sf::CircleShape*> sekiller;

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
			aktifSekil = new sf::CircleShape(1, 90);
			aktifSekil->setFillColor(sf::Color(0, 255, 0));

			aktifSekil->setOutlineThickness(5.0f);

			aktifSekil->setOutlineColor(sf::Color(255, 0, 0));

			aktifSekil->setPosition(100, 100);

			cizimBasladimi = true;

		}
	}
	if (event.type == sf::Event::MouseButtonReleased)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			sekiller.push_back(aktifSekil);

			cizimBasladimi = false;

		}
	}
	if (event.type == sf::Event::MouseMoved)
	{
		float yeniX = event.mouseMove.x;
		float yeniY = event.mouseMove.y;

		float yariCap = abs(x - yeniX) / 2;

		if (cizimBasladimi)
		{
			aktifSekil->setRadius(yariCap);
		}

	}
}

int main()
{
	sf::ContextSettings settings;

	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "ilk Pencerem", sf::Style::Default, settings);


	window.setFramerateLimit(60);
	
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

		window.clear(sf::Color::Blue);


		for (auto siradaki : sekiller)
		{
			window.draw(*siradaki);
		}

		if (aktifSekil)
		{
			aktifSekil->setPosition(x, y);
			window.draw(*aktifSekil);
		}
		window.display();



	}
	return 0;
}