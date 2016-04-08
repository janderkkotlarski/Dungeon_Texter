#include <iostream>

#include <vector>

#include "maak_veld.h"

#include "toon_veld.h"

int main()
{
	std::vector <std::vector <char>> speelveld;
	
	const int breedte{10};
	
	const int hoogte{7};
	
	maak_veld(speelveld, breedte, hoogte);
	
	#include "doet_iets.h"
	
	toon_veld(speelveld, breedte, hoogte);	
	
	#include "doet_iets.h"
	
	#include "doet_iets.h"

	return 0;
}
