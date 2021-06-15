#include "Zwierzeta.hpp"
#include "Pole.hpp"
#include "MaszynaLosujaca.hpp"
#include <vector>
#include <memory>

Zwierze::Zwierze()
{
	this->stan_zycia_zwierzecia = true;
	this->pozyskana_wartosc = 100;
	this->pole_na_ktorym_stoi_zwierze = nullptr;
}
Zwierze::Zwierze(std::shared_ptr<Pole> pole)
{
	this->stan_zycia_zwierzecia = true;
	this->pozyskana_wartosc = 100;
	this->setPole(pole);
}
std::shared_ptr<Pole> Zwierze::getPole()
{
	return this->pole_na_ktorym_stoi_zwierze;
}
int Zwierze::getPozyskanaWartosc()
{
	return this->pozyskana_wartosc;
}
void Zwierze::setPole(const std::vector<std::vector<std::shared_ptr<Pole>>> &plansza, int pozycjaX, int pozycjaY)
{
	this->pole_na_ktorym_stoi_zwierze = plansza[pozycjaX][pozycjaY];
}
void Zwierze::setPole(std::shared_ptr<Pole> pole)
{
	this->pole_na_ktorym_stoi_zwierze = pole;
}
void Zwierze::setPozyskanaWartosc(int wartosc)
{
	this->pozyskana_wartosc = wartosc;
}
void Zwierze::setStanZycia(bool _stan_zycia)
{
	this->stan_zycia_zwierzecia = _stan_zycia;
}
bool Zwierze::isZwierzeZyje()
{
	return this->stan_zycia_zwierzecia;
}
void Golab::jedz()
{
	if (this->getPole()->isWiecejNizDwaZwierzetaNaPolu())
	{
		this->setPozyskanaWartosc(0);
	}
	else
	{
		this->setPozyskanaWartosc(this->getPole()->getWartoscPola());
		if (!this->getPole()->isZwierzeSamoNaPolu())
		{
			if (this->getPole()->isJastrzabNaPolu())
			{
				this->oddajJedzenie();
			}
			else
			{
				this->dzielSieJedzeniem();
			}
		}
	}
}
typy_zwierzat Golab::getTypZwierzecia()
{
	return GOLAB;
}
void Golab::dzielSieJedzeniem()
{
	this->setPozyskanaWartosc(this->getPozyskanaWartosc() - 100);
}
void Golab::oddajJedzenie()
{
	this->setPozyskanaWartosc(this->getPozyskanaWartosc() - 150);
}
void Jastrzab::jedz()
{
	if (this->getPole()->isWiecejNizDwaZwierzetaNaPolu())
	{
		this->setPozyskanaWartosc(0);
	}
	else
	{
		this->setPozyskanaWartosc(this->getPole()->getWartoscPola());
		if (!this->getPole()->isZwierzeSamoNaPolu())
		{
			if (this->getPole()->isJastrzabNaPolu())
			{
				this->walczOJedzenie();
			}
			else
			{
				this->zabierzJedzenie();
			}
		}
	}
}
typy_zwierzat Jastrzab::getTypZwierzecia()
{
	return JASTRZAB;
}
void Jastrzab::walczOJedzenie()
{
	this->setPozyskanaWartosc(this->getPozyskanaWartosc() - 200);
}
void Jastrzab::zabierzJedzenie()
{
	this->setPozyskanaWartosc(this->getPozyskanaWartosc() + 50);
}
LicznikZwierzat::LicznikZwierzat(int _liczba_golebi, int _liczba_jastrzebi)
{
	this->liczba_golebi = _liczba_golebi;
	this->liczba_jastrzebi = _liczba_jastrzebi;
}
int LicznikZwierzat::getLiczbaZwierzecia(typy_zwierzat typ_zwierzecia)
{
	switch (typ_zwierzecia)
	{
	case GOLAB:
		return liczba_golebi;
		break;
	case JASTRZAB:
		return liczba_jastrzebi;
		break;
	default:
		return -1;
		break;
	}
}
void LicznikZwierzat::inkrementujLiczbeZwierzecia(typy_zwierzat typ_zwierzecia)
{
	switch (typ_zwierzecia)
	{
	case GOLAB:
		liczba_golebi++;
		break;
	case JASTRZAB:
		liczba_jastrzebi++;
		break;
	}
}
void LicznikZwierzat::dekrementujLiczbeZwierzecia(typy_zwierzat typ_zwierzecia)
{
	switch (typ_zwierzecia)
	{
	case GOLAB:
		liczba_golebi--;
		break;
	case JASTRZAB:
		liczba_jastrzebi--;
		break;
	}
}