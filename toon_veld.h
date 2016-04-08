void toon_veld(const std::vector <std::vector<char>>& speelveld, const int breedte, const int hoogte)
{
	for (int tel_1{0}; tel_1 < hoogte; ++tel_1)
	{
		for (int tel_2{0}; tel_2 < breedte; ++tel_2)
		{
			std::cout << speelveld[tel_2][tel_1];
		}
		
		std::cout << '\n';
	}
}
