#include "Symulacja.hpp"
#include "Plansza.hpp"
#include "MaszynaLosujaca.hpp"
#include <iostream>

Symulacja::Symulacja(int rozmiar_planszy, LiczbaPtakow poczatkowa_liczba_ptakow) : licznik_zwierzat(poczatkowa_liczba_ptakow.liczba_golebi, poczatkowa_liczba_ptakow.liczba_jastrzebi), plansza(rozmiar_planszy)
{
	for (int i = 0; i < poczatkowa_liczba_ptakow.liczba_golebi; i++)
	{
		std::shared_ptr<Zwierze> golab(new Golab());
		this->dodajZwierzeDoListy(golab);
	}
	for (int i = 0; i < poczatkowa_liczba_ptakow.liczba_jastrzebi; i++)
	{
		std::shared_ptr<Zwierze> jastrzab(new Jastrzab());
		this->dodajZwierzeDoListy(jastrzab);
	}
}

void Symulacja::rozmieszczJedzenie()
{
	MaszynaLosujaca MaszynaLosujacaJedzenie = MaszynaLosujaca(0, 1);
	for (unsigned i = 0; i < plansza.getRozmiarPlanszy(); i++)
	{
		for (unsigned j = 0; j < plansza.getRozmiarPlanszy(); j++)
		{
			int wartosc;
			bool isJedzenieNaPolu = MaszynaLosujacaJedzenie.losujLiczbe();
			if (isJedzenieNaPolu)
			{
				wartosc = 200;
			}
			else
			{
				wartosc = 0;
			}
			std::shared_ptr<Pole> pole(new Pole(j, i, wartosc));
			plansza.setPoleNaPlanszy(j, i, pole);
		}
	}
}
void Symulacja::rozmieszczZwierzeta()
{
	MaszynaLosujaca MaszynaLosujacaKoordynaty = MaszynaLosujaca(0, this->plansza.getRozmiarPlanszy() - 1);
	for (auto it = lista_zwierzat.begin(); it != lista_zwierzat.end(); it++)
	{
		std::shared_ptr<Pole> pole_na_ktorym_stoi_zwierze = it->get()->getPole();
		if (pole_na_ktorym_stoi_zwierze != nullptr)
		{
			pole_na_ktorym_stoi_zwierze->usunZwierzeZPola(*it);
		}	
		int pozycjaX = MaszynaLosujacaKoordynaty.losujLiczbe();
		int pozycjaY = MaszynaLosujacaKoordynaty.losujLiczbe();
		it->get()->setPole(this->plansza.getPoleZPozycji(pozycjaX, pozycjaY));
		pole_na_ktorym_stoi_zwierze = it->get()->getPole();
		pole_na_ktorym_stoi_zwierze->dodajZwierzeDoPola(*it);
	}
}
void Symulacja::dodajZwierzeDoListy(std::shared_ptr<Zwierze> zwierze)
{
	this->lista_zwierzat_w_nastepnej_turze.push_back(zwierze);
}
void Symulacja::przetworzZwierze(std::shared_ptr<Zwierze> zwierze)
{
	zwierze->jedz();
	MaszynaLosujaca MaszynaLosujacaSzanse = MaszynaLosujaca(1, 100);
	int przetrwanie = MaszynaLosujacaSzanse.losujLiczbe();
	if (przetrwanie > zwierze->getPozyskanaWartosc())
	{
		this->zabijZwierze(zwierze);
	}
	else
	{
		this->dodajZwierzeDoListy(zwierze);
		int rozmazanie = MaszynaLosujacaSzanse.losujLiczbe();
		if (rozmazanie <= zwierze->getPozyskanaWartosc() - 100)
		{
			this->rozmnozZwierze(zwierze);
		}
	}
}
void Symulacja::zabijZwierze(std::shared_ptr<Zwierze> zwierze)
{
	//printf("Umarlo zwierze. Zylo na pozycji X: %d Y: %d\n", zwierze->getPole()->getPozycjaX(), zwierze->getPole()->getPozycjaY());
	zwierze->getPole()->usunZwierzeZPola(zwierze);
	licznik_zwierzat.dekrementujLiczbeZwierzecia(zwierze->getTypZwierzecia());
}
void Symulacja::rozmnozZwierze(std::shared_ptr<Zwierze> zwierze)
{
	//printf("Rozmnozylo sie zwierze na pozycji X: %d Y: %d\n", zwierze->getPole()->getPozycjaX(), zwierze->getPole()->getPozycjaY());
	std::shared_ptr<Zwierze> nowe_zwierze;
	switch (zwierze->getTypZwierzecia())
	{
	case GOLAB:
		nowe_zwierze = std::shared_ptr<Zwierze>(new Golab());
		break;
	case JASTRZAB:
		nowe_zwierze = std::shared_ptr<Zwierze>(new Jastrzab());
		break;
	}
	this->dodajZwierzeDoListy(nowe_zwierze);
	licznik_zwierzat.inkrementujLiczbeZwierzecia(nowe_zwierze->getTypZwierzecia());
}
void Symulacja::przetworzTure()
{
	if (this->lista_zwierzat_w_nastepnej_turze.size() == 0)
	{
		return;
	}
	lista_zwierzat = lista_zwierzat_w_nastepnej_turze;
	lista_zwierzat_w_nastepnej_turze.erase(lista_zwierzat_w_nastepnej_turze.begin(), lista_zwierzat_w_nastepnej_turze.end());
	this->rozmieszczJedzenie();
	this->rozmieszczZwierzeta();
	for (auto it = lista_zwierzat.begin(); it != lista_zwierzat.end(); it++)
	{
		this->przetworzZwierze(*it);
	}
}
int Symulacja::getLiczbaZwierzecia(typy_zwierzat typ_zwierzecia)
{
	return licznik_zwierzat.getLiczbaZwierzecia(typ_zwierzecia);
}