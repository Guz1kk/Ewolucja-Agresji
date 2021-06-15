#pragma once

#include "Zwierzeta.hpp"
#include "Pole.hpp"
#include <vector>
#include <memory>

/** \brief Klasa przetwarzajaca informacje o zbiorze pol (planszy) */
class Plansza
{
public:
	/** \brief Konstruktor parametryczny tworzacy plansze w ksztalcie kwadratu o zadanej wielkosci
	 * 
	 * @param rozmiar_planszy rozmiar boku planszy
	 */
	Plansza(int rozmiar_planszy);
	/** \brief Metoda ustawia miejsce o zadanych koordynatach na planszy na konkretne pole
	 * 
	 * @param x Polozenie miejsca na osi OX
	 * @param y Polozenie miejsca na osi OY
	 * @param pole Wskaznik na pole ktore ma zostac ustawione
	 */
	void setPoleNaPlanszy(int x, int y, std::shared_ptr<Pole> pole);
	/** \brief Metoda zwraca rozmiar boku planszy */
	unsigned getRozmiarPlanszy();
	/** \brief Metoda zwraca wskaznik na pole z pozycji o zadanych koordynatach
	 * 
	 * @param x Polozenie pola na osi OX
	 * @param y Polozenie pola na osi OY
	 */
	std::shared_ptr<Pole> getPoleZPozycji(int x, int y);
	/** \brief Metoda zwraca plansze w formie dwuwymiarowego std::vector wskaznikow na pola */
	std::vector<std::vector<std::shared_ptr<Pole>>> getPlansza();

private:
	std::vector<std::vector<std::shared_ptr<Pole>>> v_plansza;
};