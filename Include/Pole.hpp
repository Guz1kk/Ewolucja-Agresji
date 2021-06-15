#pragma once

#include <vector>
#include <memory>

class Zwierze;

/** \brief Klasa przetwarzajaca informacje o konkretnym polu */
class Pole
{
public:
	/** \brief Konstruktor parametryczny tworzacy pole na podstawie koordynatow i wartosci
	 * @param x Polozenie pola na osi OX
	 * @param y Polozenie pola na osi OY
	 * @param wartosc Wartosc pola
	 */
	Pole(int x, int y, int wartosc);
	/** \brief Metoda zwracajaca wartosc pola
	 * @see wartosc_pola
	 */
	int getWartoscPola();
	/** \brief Metoda zwracajaca liczbe zwierzat na polu
	 * @see zwierzeta_na_polu
	 */
	int getLiczbaZwierzatNaPolu();
	/** \brief Metoda zwracajaca polozenie pola na osi OX
	 * @see pozycja_x
	 */
	int getPozycjaX();
	/** \brief Metoda zwracajaca polozenie pola na osi OY
	 * @see pozycja_y
	 */
	int getPozycjaY();
	/** \brief Metoda zwracajaca tablice wskaznikow na zwierzeta na polu
	 * @see zwierzeta_na_polu
	 */
	std::vector<std::shared_ptr<Zwierze>> getZwierzetaNaPolu();
	/** \brief Metoda ustawia wartosc pola
	 * @see wartosc_pola
	 */
	void setWartoscPola(int wartosc);
	/** \brief Metoda ustawia polozenia pola na osi OX
	 * @see pozycja_x
	 */
	void setPozycjaX(int x);
	/** \brief Metoda ustawia polozenia pola na osi OY
	 * @see pozycja_y
	 */
	void setPozycjaY(int y);
	/** \brief Metoda odpowiada na pytanie, czy jakis jastrzab znajduje sie na tym polu
	 * @see zwierzeta_na_polu
	 */
	bool isJastrzabNaPolu();
	/** \brief Metoda odpowiada na pytanie, czy jakis golab znajduje sie na tym polu
	 * @see zwierzeta_na_polu
	 */
	bool isGolabNaPolu();
	/** \brief Metoda odpowiada na pytanie, czy na polu jest tylko jedno zwierze
	 * @see zwierzeta_na_polu
	 */
	bool isZwierzeSamoNaPolu();
	/** \brief Metoda odpowiada na pytanie, czy na polu jest wiecej niz dwa zwierzeta
	 * @see zwierzeta_na_polu
	 */
	bool isWiecejNizDwaZwierzetaNaPolu();
	/** \brief Metoda dodaje zwierze do pola
	 * @param zwierze wskaznik na zwierze do dodania
	 * @see zwierzeta_na_polu
	 * @see Zwierze
	 */
	void dodajZwierzeDoPola(std::shared_ptr<Zwierze> zwierze);
	/** \brief Metoda usuwa zwierze z pola
	 * @param zwierze wskaznik na zwierze do usuniecia
	 * @see zwierzeta_na_polu
	 * @see Zwierze
	 */
	void usunZwierzeZPola(std::shared_ptr<Zwierze> zwierze);
	/** \brief Metoda zwraca zwierze z konkretnej pozycji tablicy zwierzat na polu
	 * @param pozycja pozycja z ktorej zwierze zostanie pobrane
	 * @see zwierzeta_na_polu
	 * @see Zwierze
	 */
	std::shared_ptr<Zwierze> getZwierzeNaPoluNaPozycji(int pozycja);

protected:
	/** \brief Wartosc mozliwa do pozyskania przez zwierzeta. Przyjmuje ona wartosc 200 dla pola z jedzeniem i 0 dla pola pustego
	 */
	int wartosc_pola;
	/** \brief Polozenie pola na osi OX */
	int pozycja_x;
	/** \brief Polozenie pola na osi OY */
	int pozycja_y;
	/** \brief Tablica zwierzat, ktore znajduja sie aktualnie na polu.
	 * 
	 * Teoretycznie poprawe wydajnosci powinno dac tu std::set, jednak w typowym przypadku wielkosc wektora jest bardzo mala, a uzycie bardziej skomplikowanej struktury danych naraza kod na bledy, poza tym trzebaby rozwiazac problem porownywania
	 */ 
	std::vector<std::shared_ptr<Zwierze>> zwierzeta_na_polu;
};