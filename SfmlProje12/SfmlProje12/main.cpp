#include<SFML\Graphics.hpp>
#include<vector>
#include<iostream>

#include "SfmlSahne.hpp"
#include "Model.hpp"
int main()
{
	SfmlSahne* yeniSahne = new SfmlSahne();

	Model* yeniModel = new Model("kovboy.txt");

	
	yeniSahne->modelEkle(yeniModel);

	yeniSahne->cizimDongusuBaslat();

	return 0;
}