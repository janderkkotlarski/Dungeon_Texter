void initiate_dungeon(std::vector <std::vector <char>>& dungeon)
{
	const int free_side{1};	
	const int side_length_1{static_cast<int>(dungeon.size())};
	assert(side_length_1 > 1);
	
	const int side_radius_1{(side_length_1 - 1)/2};
	
	bool exit{false};
	
	for (int count_1{0}; count_1 < side_length_1; ++count_1)
	{
		const int side_length_2{static_cast<int>(dungeon[count_1].size())};		
		const int side_radius_2{(side_length_2 - 1)/2};
		assert(side_length_2 > 1);
		
		for (int count_2{0}; count_2 < side_length_2; ++count_2)
		{
			if (((abs(count_1 - side_radius_1) > free_side) ||
				(abs(count_2 - side_radius_2) > free_side)))
			{
				if (gamble())
				{
					dungeon[count_1][count_2] = '#';
				}
				
				if (luckey(side_length_1, side_length_2) && !exit)
				{
					dungeon[count_1][count_2] = '@';
					exit = true;
				}				
			}			
			
			if ((count_1 == side_radius_1) && (count_2 == side_radius_2))
			{
				dungeon[count_1][count_2] = '*';
			}			
		}		
	}	
	
	if (!exit)
	{
		dungeon[0][0] = '@';
	}	
}
