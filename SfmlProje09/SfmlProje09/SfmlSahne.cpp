#include "SfmlSahne.hpp"
SfmlSahne::SfmlSahne(int width, int height)
{
	sf::ContextSettings settings;

	settings.antialiasingLevel = 8;
	m_Pencere = new sf::RenderWindow(sf::VideoMode(800, 600), "ilk Pencerem", sf::Style::Default, settings);

}

void SfmlSahne::cizimDongusuBaslat()
{
	while (m_Pencere->isOpen())
	{
		sf::Event event;

		while (m_Pencere->pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				m_Pencere->close();

			klavyeKontrol(event);
			fareKontrol(event);



		}
		sahneyiCiz();


	}
}

void SfmlSahne::sahneyiCiz()
{
	m_Pencere->clear(sf::Color::Blue);

	for (auto siradaki : m_SekilListesi)
	{
		m_Pencere->draw(*siradaki);
	}


	m_Pencere->display();
}

void SfmlSahne::olaylariIsle()
{
}

void SfmlSahne::klavyeKontrol(sf::Event & event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Left)
		{

		}
		if (event.key.code == sf::Keyboard::Right)
		{

		}
	}
	if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::Left)
		{
			
		}
	}
}

void SfmlSahne::fareKontrol(sf::Event & event)
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
		float yeniX = event.mouseMove.x;
		float yeniY = event.mouseMove.y;



	}
}

void SfmlSahne::sekilEkle(sf::Shape * yeniSekil)
{
	m_SekilListesi.push_back(yeniSekil);
}
