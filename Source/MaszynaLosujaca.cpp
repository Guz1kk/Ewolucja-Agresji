#include "MaszynaLosujaca.hpp"
#include <chrono>
#include <random>
#include <iostream>

MaszynaLosujaca::MaszynaLosujaca(int przedzial_dolny, int przedzial_gorny) : distrib(przedzial_dolny, przedzial_gorny)
{	
	std::random_device rd;
	std::mt19937::result_type seed = rd() ^ ((std::mt19937::result_type)
						     std::chrono::duration_cast<std::chrono::seconds>(
							 std::chrono::system_clock::now().time_since_epoch())
							 .count() +
						 (std::mt19937::result_type)
						     std::chrono::duration_cast<std::chrono::microseconds>(
							 std::chrono::high_resolution_clock::now().time_since_epoch())
							 .count());

	this->gen.seed(seed);
}

int MaszynaLosujaca::losujLiczbe()
{
	int random_number = distrib(gen);
	//printf("%d\n", random_number);
	return random_number;
}