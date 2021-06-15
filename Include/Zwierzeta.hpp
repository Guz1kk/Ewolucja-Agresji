#pragma once
#include <memory>
#include <vector>

/** \brief Typ wyliczeniowy przechowujace stale oznaczajace typ zwierzecia */
enum typy_zwierzat
{
	GOLAB,
	JASTRZAB
};

class Pole;

/** \brief Klasa przetwarzajaca informacje o konkretnym zwierzeciu */
class Zwierze
{
public:
	/** \brief Konstruktor domyslny
	 * 
	 * Ustawia stan zycia zwierzeta na true, pozyskana wartosc na 100 i wskaznik na pole na null pointer
	 * @see stan_zycia_zwierzecia
	 * @see pozyskana_wartosc
	 * @see pole_na_ktorym_stoi_zwierze
	 */
	Zwierze();
	/** \brief Konstruktor parametryczny, tworzy zwierze i przypisuje je do konkretnego pola
	 * 
	 * Ustawia stan zycia zwierzecia na true, pozyskana wartosc na 100 i pole na pole
	 * @param pole wskaznik na pole na ktorym ma zostac ustawione zwierze
	 * @see stan_zycia_zwierzecia
	 * @see pozyskana_wartosc
	 * @see pole_na_ktorym_stoi_zwierze
	 */
	Zwierze(std::shared_ptr<Pole> pole);
	/** \brief Pure virtual metoda obslugujaca jedzenie
	 * 
	 * Implementacja rozni sie w zaleznosci od typu zwierzecia
	 */
	virtual void jedz() = 0;
	/** \brief Metoda zwracajaca wskaznik na pole, na ktorym stoi zwierze
	 * 
	 * @see Pole
	 */
	std::shared_ptr<Pole> getPole();
	/** \brief Metoda zwracajaca wartosc pozyskana przez zwierze
	 * 
	 * @see pozyskana_wartosc
	 */
	int getPozyskanaWartosc();
	/** \brief Metoda zwracajaca typ zwierzecia 
	 * 
	 */
	virtual typy_zwierzat getTypZwierzecia() = 0;
	/** \brief Metoda ustawiajaca stan zycia zwierzecia
	 * @param _stan_zycia wartosc na ktora zostanie ustawiony stan zycia
	 * @see stan_zycia_zwierzecia
	 */
	void setStanZycia(bool _stan_zycia);
	/** \brief Metoda odpowiadajaca na pytanie, czy zwierze zyje
	 * @see stan_zycia_zwierzecia
	 */
	bool isZwierzeZyje();
	/** \brief Metoda ustawiajaca pole, na pole o zadanych koordynatach na planszy
	 * @param plansza referencja do planszy z ktorego nalezy pobrac pole
	 * @param pozycjaX polozenie pola na osi OX
	 * @param pozycjaY polozenie pola na osi OY
	 */
	void setPole(const std::vector<std::vector<std::shared_ptr<Pole>>> &plansza, int pozycjaX, int pozycjaY);
	/** \brief Metoda ustawiajaca pole, na pole pod zadanym wskaznikiem
	 * @param pole Wskaznik na pole, ktore zostanie ustawione
	 */
	void setPole(std::shared_ptr<Pole> pole);
protected:
	/** \brief Stan zycia zwierzecia
	 */
	bool stan_zycia_zwierzecia;
	/** \brief Pozyskana przez zwierze wartosc
	 */
	int pozyskana_wartosc;
	/** \brief Metoda ustawiajaca pozyskana przez zwierze wartosc, na zadana wartosc
	 * @param _pozyskana_wartosc wartosc na ktora zostanie ustawiona pozyskana wartosc
	 * @see pozyskana_wartosc
	 */
	void setPozyskanaWartosc(int _pozyskana_wartosc);
	/** \brief Wskaznik na pole na ktorym stoi zwierze
	 */
	std::shared_ptr<Pole> pole_na_ktorym_stoi_zwierze;
};

/** \brief Klasa przetwarzajaca dane o konkretnym golebiu */
class Golab : public Zwierze
{
public:
	/** \brief Metoda odpowiadajaca za jedzenie golebia
	 * 
	 * Jezeli golab znajduje sie sam na polu, to pozyskuje cala jego wartosc. <br>
	 * Jezeli na polu znajduje sie inny golab, golab pozyskuje polowe wartosci pola. <br>
	 * Jezeli na polu znajduje sie jastrzab, golab pozyskuje 25% wartosci pola. <br>
	 * Jezeli na polu znajduja sie wiecej niz dwie jednostki, golab pozyskuje wartosc 0 <br>
	 * @see pozyskana_wartosc
	 */
	void jedz();
	typy_zwierzat getTypZwierzecia();

private:
	/** \brief Metoda odpowiadajaca za oddawanie jedzenia jastrzabowi
	 * 
	 * Jezeli na polu znajduje sie jastrzab, to golab pozyskuje 25% wartosci pola
	 * @see Golab::jedz()
	 */
	void oddajJedzenie();
	/** \brief Metoda odpowiadajaca za dzielenie sie jedzeniem z innym golebiem
	 * 
	 * Jezeli na polu znajduje sie inny golab, to golab pozyskuje 50% wartosci pola
	 * @see Golab::jedz()
	 */
	void dzielSieJedzeniem();
};

/** \brief Klasa przetwarzajaca dane o konkretnym jastrzebiu */
class Jastrzab : public Zwierze
{
public:
	/** \brief Metoda odpowiadajaca za jedzenie jastrzebia
	 * 
	 * Jezeli jastrzab znajduje sie sam na polu, to pozyskuje cala jego wartosc. <br>
	 * Jezeli na polu znajduje sie inny jastrzab, jastrzab pozyskuje wartosc 0. <br>
	 * Jezeli na polu znajduje sie golab, jastrzab pozyskuje 75% wartosci pola. <br>
	 * Jezeli na polu znajduja sie wiecej niz dwie jednostki, jastrzab pozyskuje wartosc 0
	 * @see pozyskana_wartosc
	 */
	void jedz();
	typy_zwierzat getTypZwierzecia();

private:
	/**  \brief Metoda odpowiadajaca za walke o jedzenie z innym jastrzebiem
	 * 
	 * Jezeli na polu znajduje sie inny jastrzab, jastrzab pozyskuje wartosc 0
	 * @see Jastrzab::jedz()
	 */
	void walczOJedzenie();
	/** \brief Metoda odpowiadajaca za zabieranie jedzenia golebiowi
	 * 
	 * Jezeli na polu znajduje sie golab, jastrzab pozyskuje 75% wartosci pola 
	 * @see Jastrzab::jedz()
	 */
	void zabierzJedzenie();
};

/** \brief Klasa przetwarzajaca dane o ilosci zwierzat */
class LicznikZwierzat
{
public:
	/** \brief Konstruktor parametryczny tworzacy LicznikZwierzat na podstawie wartosci poczatkowej poszczegolnych zwierzat
	 * @param _liczba_golebi poczatkowa liczba golebi
	 * @param _liczba_jastrzebi poczatkowa liczba jastrzebi
	 */
	LicznikZwierzat(int _liczba_golebi, int _liczba_jastrzebi);
	/** \brief Metoda zwracajaca liczbe konkretnego zwierzecia
	 * @param typ_zwierzecia typ zwierzecia
	 * @see typy_zwierzat
	 */
	int getLiczbaZwierzecia(typy_zwierzat typ_zwierzecia);
	/** \brief Metoda inkrementujaca liczbe konkretnego zwierzecia
	 * @param typ_zwierzecia typ zwierzecia
	 * @see typy_zwierzat
	 */
	void inkrementujLiczbeZwierzecia(typy_zwierzat typ_zwierzecia);
	/** \brief Metoda dekrementujaca liczbe konkretnego zwierzecia
	 * @param typ_zwierzecia typ zwierzecia
	 * @see typy_zwierzat
	 */
	void dekrementujLiczbeZwierzecia(typy_zwierzat typ_zwierzecia);

private:
	/** \brief Pole przechowujace liczbe golebi */
	int liczba_golebi;
	/** \brief Pole przechowujace liczbe jastrzebi */
	int liczba_jastrzebi;
};