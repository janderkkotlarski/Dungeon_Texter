#include "maak_kolom.h"

void maak_veld(std::vector <std::vector<char>>& speelveld, const int breedte, const int hoogte)
{
	for (int tel_1{0}; tel_1 < breedte; ++tel_1)
	{
		speelveld.push_back(maak_kolom(hoogte));
	}
}
