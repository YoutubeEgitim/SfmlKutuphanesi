#ifndef Model_hpp
#define Model_hpp
#include<map>
#include<string>
#include<SFML\Graphics.hpp>
class Animasyon;
class Model
{
public:
	Model(std::string dosyaIsmi);


	void ciz(sf::RenderWindow* pencere);


private:
	std::map<std::string, Animasyon*> m_Animasyonlar;

	std::string m_AktifAnimasyon;

};


#endif
