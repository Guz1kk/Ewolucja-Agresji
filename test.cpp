#include "Symulacja.hpp"
#include "MaszynaLosujaca.hpp"
#include <cmath>
#include <iostream>
#include <vector>

class SymulacjaTest : public Symulacja
{
public:
	SymulacjaTest(int rozmiar_planszy, LiczbaPtakow poczatkowa_liczba_ptakow);
	void testujRozmieszczJedzenie() { this->rozmieszczJedzenie(); }
	void testujRozmieszczZwierzeta() { this->rozmieszczZwierzeta(); }
	std::vector<std::vector<std::shared_ptr<Pole>>> getPlansza() { return this->plansza.getPlansza(); }
};

SymulacjaTest::SymulacjaTest(int rozmiar_planszy, LiczbaPtakow poczatkowa_liczba_ptakow) : Symulacja(rozmiar_planszy, poczatkowa_liczba_ptakow)
{
}
bool checkIfRandomNumberGeneratorWorksProperly()
{
	MaszynaLosujaca testowa_maszyna_losujaca = MaszynaLosujaca(0, 99);
	std::vector<int> random_numbers_vector(100);
	for (int i = 0; i < 100; i++)
	{
		random_numbers_vector[i] = 0;
	}
	for (int i = 0; i < 1000000; i++)
	{
		random_numbers_vector[testowa_maszyna_losujaca.losujLiczbe()]++;
	}
	for (int amout_of_numbers_in_result : random_numbers_vector)
	{
		if (!(amout_of_numbers_in_result > 9500 && amout_of_numbers_in_result < 10500))
		{
			return false;
		}
	}
	return true;
}
bool checkIfRozmieszczJedzenieWorksProperly()
{
	SymulacjaTest testowa_symulacja = SymulacjaTest(1000, {0, 0});
	testowa_symulacja.testujRozmieszczJedzenie();
	for (auto kolumna : testowa_symulacja.getPlansza())
	{
		for (auto pole : kolumna)
		{
			if (pole->getWartoscPola() != 0 && pole->getWartoscPola() != 200)
			{
				return false;
			}
		}
	}
	return true;
}
bool checkIfRozmieszczZwierzetaWorksProperly()
{
	SymulacjaTest testowa_symulacja = SymulacjaTest(10, {100, 100});
	testowa_symulacja.testujRozmieszczZwierzeta();
	for (auto kolumna : testowa_symulacja.getPlansza())
	{
		for (auto pole : kolumna)
		{
			for (auto kolumna2 : testowa_symulacja.getPlansza())
			{
				for (auto pole2 : kolumna2)
				{
					if (pole == pole2)
					{
						continue;
					}
					for (auto zwierze : pole->getZwierzetaNaPolu())
					{
						if (zwierze->getPole() != pole)
						{
							return false;
						}
						for (auto zwierze2 : pole2->getZwierzetaNaPolu())
						{
							if (zwierze2->getPole() != pole2)
							{
								return false;
							}
							if (zwierze == zwierze2)
							{
								return false;
							}
						}
					}
				}
			}
		}
	}
	return true;

}

int main()
{
	int number_of_tests = 0;
	int number_of_tests_passed = 0;
	if (checkIfRandomNumberGeneratorWorksProperly())
	{
		std::cout << "Random Number Generator test passed!" << std::endl;
		number_of_tests_passed++;
		number_of_tests++;
	}
	else
	{
		std::cout << "Random Number Generator test failed!" << std::endl;
		number_of_tests++;
	}
	if (checkIfRozmieszczJedzenieWorksProperly())
	{
		std::cout << "Rozmieszcz Jedzenie test passed!" << std::endl;
		number_of_tests_passed++;
		number_of_tests++;
	}
	else
	{
		std::cout << "Rozmieszcz Jedzenie test failed!" << std::endl;
		number_of_tests++;
	}
	if (checkIfRozmieszczZwierzetaWorksProperly())
	{
		std::cout << "Rozmieszcz Zwierzeta test passed!" << std::endl;
		number_of_tests_passed++;
		number_of_tests++;
	}
	else
	{
		std::cout << "Rozmieszcz Zwierzeta test failed!" << std::endl;
		number_of_tests++;
	}
	if (number_of_tests == number_of_tests_passed)
	{
		std::cout << "All tests passed!" << std::endl;
	}
	else
	{
		std::cout << number_of_tests - number_of_tests_passed << " test(s) failed!" << std::endl;
	}
}