#include "SfmlSahne.hpp"

int cerceve = 0;
int sayac = 0;
int frameSuresi = 10;
int cerceveSayisi = 10;
SfmlSahne::SfmlSahne(int genislik, int yukseklik)
{
	sf::ContextSettings settings;

	settings.antialiasingLevel = 8;
	m_Pencere = new sf::RenderWindow(sf::VideoMode(genislik, yukseklik), "ilk Pencerem", sf::Style::Default, settings);


}

void SfmlSahne::sekilEkle(sf::Sprite * yeniSekil)
{
	m_SekilListesi.push_back(yeniSekil);
}

void SfmlSahne::cizimDongusuBaslat()
{
	m_Pencere->setFramerateLimit(60);


	while (m_Pencere->isOpen())
	{

		olaylariIsle();

		sahneyiCiz();
	}
}

void SfmlSahne::sahneyiCiz()
{
	m_Pencere->clear(sf::Color::Blue);



	if (sayac == frameSuresi)
	{
		sayac = 0;
		cerceve = (cerceve + 1) % cerceveSayisi;
	}
	else
		sayac++;
	m_Pencere->draw(*m_SekilListesi[cerceve]);


	m_Pencere->display();
}

void SfmlSahne::olaylariIsle()
{
	sf::Event event;

	while (m_Pencere->pollEvent(event))
	{

		if (event.type == sf::Event::Closed)
			m_Pencere->close();


		klavyeKontrol(event);

		fareKontrol(event);

	}
}

void SfmlSahne::klavyeKontrol(sf::Event & event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Left)

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


	}
}
