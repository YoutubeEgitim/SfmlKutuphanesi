#include "Model.hpp"
#include "Animasyon.hpp"
#include<fstream>
Model::Model(std::string animasyonDosyasi)
{

	std::fstream dosya;

	dosya.open(animasyonDosyasi);

	if (dosya.is_open())
	{

		std::string animasyonIsmi;
		std::string dosyaIsmi;
		std::string gecici;
		int cerceveSayisi;

		dosya >> gecici >> m_AktifAnimasyon;


		while (dosya >> animasyonIsmi >> dosyaIsmi >> cerceveSayisi)
		{
			Animasyon* siradaki = new Animasyon();
			siradaki->animasyonYukle(dosyaIsmi, cerceveSayisi);
			
			m_Animasyonlar[animasyonIsmi] = siradaki;
			
		}
	}
}
void Model::ciz(sf::RenderWindow* pencere)
{
	m_Animasyonlar[m_AktifAnimasyon]->ciz(pencere);
	m_Animasyonlar[m_AktifAnimasyon]->guncelle();
}
