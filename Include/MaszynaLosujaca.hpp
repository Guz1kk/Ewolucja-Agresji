#pragma once

#include <random>

/** \brief Klasa przetwarzajaca losowanie liczb
 * 
 * Do wygenerowania pseudolosowej liczby wykorzystanych zostalo kilka algorytmow. <br>
 * Najpierw brana jest pseudolosowa liczba z std::random_engine <br>
 * Nastepnie jest ona xorowana z suma liczby sekund i mikrosekund od 1 stycznia 1970 roku <br>
 * Wynik uzywany jest jako seed do algorytmu mt19937 <br>
 * Wywolujac algorytm mt19937 uzyskujemy ciag liczb, realnie nieodroznialnych od ciagu losowego
 */
class MaszynaLosujaca
{
public:
	/** \brief Konstruktor parametryczny tworzacy maszyne losujaca na podstawie dolnej granicy i gornej granicy
	 * 
	 * Losowane sa liczby calkowite z przedzialu [przedzial_dolny, przedzial_gorny]
	 * @param przedzial_dolny najmniejsza mozliwa do wylosowania liczba calkowita
	 * @param przedzia_gorny najwieksza mozliwa do wylosowania liczba calkowita
	 */
	MaszynaLosujaca(int przedzial_dolny, int przedzial_gorny);
	/** \brief Metoda zwracajaca losowa liczba z przedzialu [przedzial_dolny, przedzial_gorny]
	 * @see MaszynaLosujaca()
	 */
	int losujLiczbe();
private:
	std::mt19937 gen;
	std::uniform_int_distribution<unsigned> distrib;
};