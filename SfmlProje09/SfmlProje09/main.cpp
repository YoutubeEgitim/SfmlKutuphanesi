#include<SFML\Graphics.hpp>
#include<vector>
#include<iostream>
#include "SfmlSahne.hpp"

int main()
{
	SfmlSahne sahne;

	sf::RectangleShape* rect = new sf::RectangleShape();
	rect->setPosition(100, 200);
	rect->setSize(sf::Vector2f(130, 130));
	sahne.sekilEkle(rect);

	sahne.cizimDongusuBaslat();


	return 0;
}