#include "Animasyon.hpp"

Animasyon::Animasyon()
{
	m_CerceveSayisi = 0;
	m_AktifCerceveNumarasi = 0;
	m_CerceveSuresi = 3;
	m_CerceveDegismeSayaci = 0;
}

void Animasyon::animasyonYukle(std::string ilkDosyaIsmi, int cerceveSayisi)
{
	m_CerceveSayisi = cerceveSayisi;
	for (int i = 0; i < cerceveSayisi; i++)
	{
		sf::Sprite * yeniSprite = new sf::Sprite;

		sf::Texture* yeniKaplama = new sf::Texture;

		std::string dosyaIsmiParcasi = ilkDosyaIsmi.substr(0, ilkDosyaIsmi.length() - 5);

		std::string uzanti = ilkDosyaIsmi.substr(ilkDosyaIsmi.length() - 4,4 );

		std::string dosyaIsmi = dosyaIsmiParcasi + std::to_string(i) + uzanti;

		yeniKaplama->loadFromFile(dosyaIsmi);

		yeniSprite->setTexture(*yeniKaplama);

		m_Cerceveler.push_back(yeniSprite);
		m_Kaplamalar.push_back(yeniKaplama);
	}

}

void Animasyon::ciz(sf::RenderWindow * pencere)
{
	pencere->draw(*m_Cerceveler[m_AktifCerceveNumarasi]);
}

void Animasyon::guncelle()
{

	if (m_CerceveDegismeSayaci == m_CerceveSuresi)
	{
		m_AktifCerceveNumarasi = (m_AktifCerceveNumarasi + 1) % m_CerceveSayisi;
		m_CerceveDegismeSayaci = 0;
	}
	else
	{
		m_CerceveDegismeSayaci++;
	}
}

void Animasyon::cerceveSuresiAta(int cerceveSuresi)
{
	m_CerceveSuresi = cerceveSuresi;
}
