#include <iostream>
#include <memory>
#include <vector>
#include <exception>
#include "Symulacja.hpp"

int main()
{
	try
	{
		int rozmiar_planszy;
		std::cout << "Podaj rozmiar boku planszy: ";
		std::cin >> rozmiar_planszy;
		int liczba_golebi;
		std::cout << "Podaj liczbe golebi: ";
		std::cin >> liczba_golebi;
		int liczba_jastrzebi;
		std::cout << "Podaj liczbe jastrzebi: ";
		std::cin >> liczba_jastrzebi;
		int liczba_dni;
		std::cout << "Podaj liczbe dni, przez ktore trwac bedzie symulacja: ";
		std::cin >> liczba_dni;
		int liczba_symulacji;
		std::cout << "Podaj liczbe symulacji, ktore maja sie wykonac: ";
		std::cin >> liczba_symulacji;
		if ((!std::cin.good()) || (rozmiar_planszy < 0) || (liczba_golebi < 0) || (liczba_jastrzebi < 0) || (liczba_dni < 0) || (liczba_symulacji <= 0))
		{
			std::cout << "\nWprowadzono bledne dane\n";
			return 2137;
		}
		std::vector<std::unique_ptr<Symulacja>> tablica_symulacji;
		try
		{
			for (int i = 0; i < liczba_symulacji; i++)
			{
				tablica_symulacji.push_back(std::unique_ptr<Symulacja>(new Symulacja(rozmiar_planszy, {liczba_golebi, liczba_jastrzebi})));
			}
		}
		catch (const std::length_error e)
		{
			std::cerr << "\nWprowadzono za duze dane\n";
			return 2137;
		}
		catch (const std::bad_alloc e)
		{
			std::cerr << "\nWprowadzono za duze dane\n";
			return 2137;
		}
		for (int i = 0; i < liczba_dni; i++)
		{
			int liczba_golebi = 0;
			int liczba_jastrzebi = 0;
			for (int i = 0; i < liczba_symulacji; i++)
			{
				liczba_golebi += tablica_symulacji[i]->getLiczbaZwierzecia(GOLAB);
				liczba_jastrzebi += tablica_symulacji[i]->getLiczbaZwierzecia(JASTRZAB);
				tablica_symulacji[i]->przetworzTure();
			}
			liczba_golebi /= liczba_symulacji;
			liczba_jastrzebi /= liczba_symulacji;
			std::cout << "Dzien " << i + 1 << ":" << std::endl;
			std::cout << "    Liczba golebi: " << liczba_golebi << std::endl;
			std::cout << "    Liczba jastrzebi: " << liczba_jastrzebi << std::endl;
			std::cout << std::endl;
		}
	}
	catch (...)
	{
		std::cerr << "\nWprowadzono bledne dane\n";
		return 2137;
	}
	return 0;
}