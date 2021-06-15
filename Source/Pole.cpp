#include "Pole.hpp"
#include "Zwierzeta.hpp"
#include <memory>
#include <vector>

Pole::Pole(int x, int y, int wartosc)
{
	setPozycjaX(x);
	setPozycjaY(y);
	setWartoscPola(wartosc);
}
int Pole::getWartoscPola()
{
	return this->wartosc_pola;
}
int Pole::getLiczbaZwierzatNaPolu()
{
	return this-> zwierzeta_na_polu.size();
}
int Pole::getPozycjaX()
{
	return this->pozycja_x;
}
int Pole::getPozycjaY()
{
	return this->pozycja_y;
}
std::vector<std::shared_ptr<Zwierze>> Pole::getZwierzetaNaPolu()
{
	return this->zwierzeta_na_polu;
}
void Pole::setWartoscPola(int wartosc)
{
	this->wartosc_pola = wartosc;
}
void Pole::setPozycjaX(int x)
{
	this->pozycja_x = x;
}
void Pole::setPozycjaY(int y)
{
	this->pozycja_y = y;
}
bool Pole::isJastrzabNaPolu()
{
	bool _isJastrzabNaPolu = false;
	for (auto it = zwierzeta_na_polu.begin(); it != zwierzeta_na_polu.end(); it++)
	{
		if (it->get()->getTypZwierzecia() == typy_zwierzat(JASTRZAB))
		{
			_isJastrzabNaPolu = true;
			break;
		}
	}
	return _isJastrzabNaPolu;
}
bool Pole::isGolabNaPolu()
{
	bool _isGolabNaPolu = false;
	for (auto it = zwierzeta_na_polu.begin(); it != zwierzeta_na_polu.end(); it++)
	{
		if (it->get()->getTypZwierzecia() == typy_zwierzat(GOLAB))
		{
			_isGolabNaPolu = true;
			break;
		}
	}
	return _isGolabNaPolu;
}
bool Pole::isZwierzeSamoNaPolu()
{
	return this->getLiczbaZwierzatNaPolu() == 1;
}
bool Pole::isWiecejNizDwaZwierzetaNaPolu()
{
	return this->getLiczbaZwierzatNaPolu() > 2;
}
void Pole::dodajZwierzeDoPola(std::shared_ptr<Zwierze> zwierze)
{
	zwierzeta_na_polu.push_back(zwierze);
}
void Pole::usunZwierzeZPola(std::shared_ptr<Zwierze> zwierze)
{
	for (auto it = zwierzeta_na_polu.begin(); it != zwierzeta_na_polu.end(); it++)
	{
		if (it->get() == zwierze.get())
		{
			zwierzeta_na_polu.erase(it);
			break;
		}
	}
}
std::shared_ptr<Zwierze> Pole::getZwierzeNaPoluNaPozycji(int pozycja)
{
	return zwierzeta_na_polu[pozycja];
}