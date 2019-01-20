#ifndef SfmlSahne_hpp
#define SfmlSahne_hpp

#include<SFML\Graphics.hpp>
#include<vector>

class SfmlSahne
{
public:
	SfmlSahne(int width = 800, int height = 600);
	
	void	cizimDongusuBaslat();
	void	sekilEkle(sf::Shape* yeniSekil);
private:
	void	sahneyiCiz();
	void	olaylariIsle();
	void	klavyeKontrol(sf::Event& event);
	void	fareKontrol(sf::Event& event);
	
private:
	sf::RenderWindow*		m_Pencere;

	std::vector<sf::Shape*>	m_SekilListesi;
};


#endif