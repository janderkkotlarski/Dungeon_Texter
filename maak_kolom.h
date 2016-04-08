std::vector <char> maak_kolom(const int hoogte)
{
	std::vector <char> kolom;
	
	for (int tel_1{0}; tel_1 < hoogte; ++tel_1)
	{
		kolom.push_back('!');
	}
	
	return kolom;
}
