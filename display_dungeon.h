void display_dungeon(const std::vector <std::vector <char>>& dungeon)
{
	const int side_length_1{static_cast<int>(dungeon.size())};
	
	for (int count_1{-1}; count_1 <= side_length_1; ++count_1)
	{
		int side_length_2{static_cast<int>(dungeon[0].size())};
		
		if ((count_1 > -1) && (count_1 < side_length_1))
		{
			side_length_2 = static_cast<int>(dungeon[count_1].size());
		}
				
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
