#include<SFML\Graphics.hpp>
#include<vector>
#include<iostream>

#include "SfmlSahne.hpp"
#include "Animasyon.hpp"
int main()
{

	SfmlSahne* yeniSahne = new SfmlSahne();

	Animasyon* yeniAnimasyon = new Animasyon();
	yeniAnimasyon->animasyonYukle("images/Dead__000.png",10);
	yeniSahne->animasyonEkle(yeniAnimasyon);
	yeniSahne->cizimDongusuBaslat();

	return 0;
}