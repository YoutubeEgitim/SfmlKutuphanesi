#include<SFML\Graphics.hpp>
#include<vector>
#include<iostream>
enum class YON
{
	SOL,
	SAG,
	YUKARI,
	ASAGI
};
int x = 100;
int y = 100;
float cap = 50;
sf::CircleShape *aktifSekil = nullptr;
YON sekilYonu = YON::ASAGI;
bool hareketBaslasinmi = false;

sf::Texture kaplama;


void klavyeKontrol(sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Left)
			sekilYonu = YON::SOL;
		if (event.key.code == sf::Keyboard::Right)
			sekilYonu = YON::SAG;
		if (event.key.code == sf::Keyboard::Up)
			sekilYonu = YON::YUKARI;
		if (event.key.code == sf::Keyboard::Down)
			sekilYonu = YON::ASAGI;
		if (event.key.code == sf::Keyboard::Space)
		{
			hareketBaslasinmi = !hareketBaslasinmi;

		}
	}
	if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::Left)
		{
			
		}
	}
}

void fareKontrol(sf::Event& event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{


		}
	}
	if (event.type == sf::Event::MouseButtonReleased)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{


		}
	}
	if (event.type == sf::Event::MouseMoved)
	{

	}
}

int main()
{
	sf::ContextSettings settings;

	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "ilk Pencerem", sf::Style::Default, settings);

	if (kaplama.loadFromFile("resim.png") == false)
	{
		std::cout << "resim acilamadi" << std::endl;
	}

	aktifSekil = new sf::CircleShape(1, 90);

	aktifSekil->setTexture(&kaplama);

	aktifSekil->setTextureRect(sf::IntRect(0, 0, 256, 256));

	aktifSekil->setOutlineThickness(5.0f);

	aktifSekil->setOutlineColor(sf::Color(255, 0, 0));

	aktifSekil->setPosition(100, 100);

	aktifSekil->setRadius(cap);
	

	


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

		if (aktifSekil)
		{
			aktifSekil->setPosition(x, y);

			window.draw(*aktifSekil);

			if (hareketBaslasinmi)
			{

				if (x + cap >= window.getSize().x)
				{
					sekilYonu = YON::SOL;
				}

				if (x <= 0)
				{
					sekilYonu = YON::SAG;
				}
				if (y + cap >= window.getSize().y)
				{
					sekilYonu = YON::YUKARI;
				}

				if (y <= 0)
				{
					sekilYonu = YON::ASAGI;
				}
				switch (sekilYonu)
				{
				case YON::SAG:
					x += 10;
					break;
				case YON::SOL:
					x -= 10;
					break;
				case YON::YUKARI:
					y -= 10;
					break;
				case YON::ASAGI:
					y += 10;
					break;
				default:
					break;
				}
			}


		}
		window.display();



	}
	return 0;
}