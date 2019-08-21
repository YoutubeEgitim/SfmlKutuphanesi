#ifndef SfmlSahne_hpp
#define SfmlSahne_hpp

#include<SFML\Graphics.hpp>
#include<vector>

class Model;

class SfmlSahne
{
public:
	SfmlSahne(int genislik = 800, int yukseklik = 600);
	void sekilEkle(sf::Shape* yeniSekil);
	void modelEkle(Model* model);
	void cizimDongusuBaslat();
private:

	void	sahneyiCiz();
	void	olaylariIsle();
	void	klavyeKontrol(sf::Event& event);
	void	fareKontrol(sf::Event& event);


	sf::RenderWindow*			m_Pencere;

	std::vector<sf::Shape*>		m_SekilListesi;
	std::vector<sf::Sprite*>	m_SpriteListesi;

	std::vector<Model*>		m_ModelListesi;
};


#endif

