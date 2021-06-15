#pragma once

#include "Plansza.hpp"
#include "Pole.hpp"
#include "Zwierzeta.hpp"
#include <list>
#include <memory>

/** \brief Struktura przechowujaca informacje o liczbie zywych zwierzat */
struct LiczbaPtakow
{
	int liczba_golebi;
	int liczba_jastrzebi;
};

/** \brief Klasa obslugujaca cala symulacje */
class Symulacja
{
public:
	/** \brief Konstruktor parametryczny tworzacy symulacje na podstawie rozmiaru planszy i poczatkowej liczby ptakow
	 * @param rozmiar_planszy Dlugosc boku planszy, ktora jest kwadratem
	 * @param LiczbaPtakow struktura przechowujaca liczbe ptakow
	 * @see Plansza
	 * @see LiczbaPtakow
	 */
	Symulacja(int rozmiar_planszy, LiczbaPtakow poczatkowa_liczba_ptakow);
	/** \brief Glowny interfejs, symuluje caly aktualny dzien
	 * 
	 * Metoda ta rozmieszcza jedzenie i zwierzeta, obsluguje jedzenie, umieranie i rozmnazanie 
	 */
	void przetworzTure();
	/** \brief Metoda zwraca liczbe zwierzat danego typu
	 * @see typy_zwierzat
	 */
	int getLiczbaZwierzecia(typy_zwierzat typ_zwierzecia);

protected:
	/** \brief Przechowuje liczbe aktualnie zywych zwierzat
     * @see LicznikZwierzat
     */
	LicznikZwierzat licznik_zwierzat;
	/** \brief Przechowuje pola
	 * 
	 * Plansza na ktorej odbywa sie symulacja. Przechowuje wszystkie pola i informacje o ich ilosci
	 * @see Plansza
	 * @see Pole
	 */
	Plansza plansza;
	/** \brief Lista wskaznikow na wszystkie zwierzata do przetworzenia w aktualnym dniu
	 * @see Zwierze
	 * @see lista_zwierzat_w_nastepnej_turze
	 */
	std::list<std::shared_ptr<Zwierze>> lista_zwierzat;
	/** \brief Lista zwierzat zostanie zastapiana ta lista w nastepnym dniu
	 * @see lista_zwierzat
	 * @see Zwierze
	 */
	std::list<std::shared_ptr<Zwierze>> lista_zwierzat_w_nastepnej_turze;
	/** \brief Dodaje zwierze do listy zwierzat
	 * 
	 * Technicznie rzecz ujmujac, metoda dodaje zwierze do listy zwierzat w nastepnej turze
	 * @param zwierze wskaznik na zwierze ktore zostaje dodane do listy
	 * @see lista_zwierzat_w_nastpnej_turze
	 * @see lista_zwierzat
	 * @see Zwierze*/
	void dodajZwierzeDoListy(std::shared_ptr<Zwierze> zwierze);
	/** \brief Symuluje zycie zwierzecia w ciagu aktualnego dnia
	 * 
	 * Odpowiada za jedzenie, umieranie, rozmnazanie. Nie odpowiada za ruch.
	 * @param zwierze wskaznik na zwierze ktore zostaje przetworzone
	 * @see Zwierze
	 * @see lista_zwierzat
	 */
	void przetworzZwierze(std::shared_ptr<Zwierze> zwierze);
	/** \brief Losowo rozmieszcza jedzenie na planszy
	 * 
	 * Losuje ktorym z pol na planszy zostanie przypisana wartosc 200, a ktorym wartosc 0
	 * @see Plansza
	 * @see Pole
	 * @see MaszynaLosujaca
	 */ 
	void rozmieszczJedzenie();
	/** \brief Losowo rozmieszcza zwierzeta na planszy
	 * 
	 * Losuje koordynaty nie wieksze niz wielkosc boku planszy, nastepnie odczytuje z planszy pole o konkretnych koordynatach i ustawia na nim zwierze. Procedura wykonywana jest dla kazdego zwierzecia na liscie
	 * @see lista_zwierzat
	 * @see MaszynaLosujaca
	 * @see Zwierze
	 * @see Pole
	 */
	void rozmieszczZwierzeta(); 
	/** \brief Usuwa zwierze z listy i z pola na ktorym stoi
	 * 
	 * Technicznie rzecz ujmujac nie usuwa zwierzecia z listy, a po prostu nie dodaje go do listy przetwarzanej w nastepnym dniu
	 * @param zwierze wskaznik na zwierze do zabicia
	 * @see lista_zwierzat
	 * @see lista_zwierzat_w_nastepnej_turze
	 * @see Zwierze
	 * @see Pole
	 */
	void zabijZwierze(std::shared_ptr<Zwierze> zwierze);
	/** \brief Dodaje nowe zwierze do listy
	 * 
	 * Dodaje nowe zwierze do listy zwierzat przetwarzanej w nastepnej turze. Nowemu zwierzeciu nie zostaje przypisane zadne pole (robi to rozmieszczZwierzeta(), w nastepnej turze)
	 * @param zwierze wskaznik na zwierze do rozmnozenia
	 * @see lista_zwierzat
	 * @see lista_zwierzat_w_nastepnej_turze
	 * @see Zwierze
	 */
	void rozmnozZwierze(std::shared_ptr<Zwierze> zwierze); //nowe zwierze nie ma przypisanego pola na ktorym stoi, pole zostaje przypisane w nastepnym dniu za pomoca rozmieszczZwierzeta()
};