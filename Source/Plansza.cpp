#include "Plansza.hpp"
#include "MaszynaLosujaca.hpp"

Plansza::Plansza(int rozmiar_planszy)
{
	this->v_plansza.resize(rozmiar_planszy);
	for (int i = 0; i < rozmiar_planszy; i++)
	{
		this->v_plansza[i].resize(rozmiar_planszy);
	}
}
unsigned Plansza::getRozmiarPlanszy()
{
	return v_plansza.size();
}
std::vector<std::vector<std::shared_ptr<Pole>>> Plansza::getPlansza()
{
	return v_plansza;
}
void Plansza::setPoleNaPlanszy(int x, int y, std::shared_ptr<Pole> pole)
{
	v_plansza[y][x] = pole;
	pole->setPozycjaX(x);
	pole->setPozycjaY(y);
}
std::shared_ptr<Pole> Plansza::getPoleZPozycji(int x, int y)
{
	return v_plansza[y][x];
}