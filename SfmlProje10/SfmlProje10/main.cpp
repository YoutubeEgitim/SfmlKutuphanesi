#include<SFML\Graphics.hpp>
#include<vector>
#include<iostream>

#include "SfmlSahne.hpp"

int main()
{
	std::vector<sf::Sprite*> sprites;
	std::vector<sf::Texture*> textures;

	SfmlSahne* yeniSahne = new SfmlSahne();
	for (int i = 0; i < 10; i++)
	{
		std::string dosyaIsmi = "images/Dead__00" + std::to_string(i) + std::string(".png");

		sf::Texture* newtexture = new sf::Texture;
		if (!newtexture->loadFromFile(dosyaIsmi))
		{
			// error...
		}
		textures.push_back(newtexture);

		sf::Sprite* newSprite = new sf::Sprite;
		newSprite->setTexture(*newtexture);

		sprites.push_back(newSprite);

		yeniSahne->sekilEkle(newSprite);
	}




	yeniSahne->cizimDongusuBaslat();

	return 0;
}