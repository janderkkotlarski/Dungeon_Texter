void display_dungeon(const std::vector <std::vector <char>>& dungeon)
{
	for (int count{0}; count < 40; ++count)
	{
		std::cout << '\n';
	}
	
	const int side_length_1{static_cast<int>(dungeon.size())};	
	assert(side_length_1 > 0);
	
	const int side_length_2{static_cast<int>(dungeon[0].size())};
	assert(side_length_2 > 0);
	
	for (int count_1{-1}; count_1 <= side_length_1; ++count_1)
	{		
		for (int count_2{-1}; count_2 <= side_length_2; ++count_2)
		{
			if ((count_2 > -1) && (count_2 < side_length_2))
			{
				if ((count_1 > -1) && (count_1 < side_length_1))
				{
					std::cout << dungeon[count_1][count_2];
				}
				else
				{
					std::cout << '-';
				}
			}
			else
			{
				if ((count_1 > -1) && (count_1 < side_length_1))
				{
					std::cout << '|';
				}
				else
				{
					std::cout << '+';
				}
			}
		}
		
		std::cout << '\n';		
	}	
}
