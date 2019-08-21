#ifndef Animasyon_hpp
#define Animasyon_hpp
#include<SFML\Graphics.hpp>
#include<vector>
#include<string>
class Animasyon
{
public:
	Animasyon();

	void animasyonYukle(std::string ilkDosyaIsmi, int cerceveSayisi);
	void ciz(sf::RenderWindow* pencere);
	void guncelle();
	void cerceveSuresiAta(int cerceveSuresi);

private:
	std::vector<sf::Sprite*>	m_Cerceveler;
	std::vector<sf::Texture*>	m_Kaplamalar;

	int	m_CerceveSayisi;
	int m_AktifCerceveNumarasi;
	int m_CerceveSuresi;
	int m_CerceveDegismeSayaci;
};


#endif