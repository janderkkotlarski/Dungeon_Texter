void initiate_dungeon(std::vector <std::vector <char>>& dungeon, std::vector <int>& player)
{
	const int free_side{1};	
	
	const int side_length_x{static_cast<int>(dungeon.size())};
	assert(side_length_x > 3);
	
	const int side_radius_x{(side_length_x - 1)/2};
	
	const int side_length_y{static_cast<int>(dungeon[0].size())};		
	assert(side_length_y > 3);
	
	const int side_radius_y{(side_length_y - 1)/2};	
	
	for (int count_1{0}; count_1 < side_length_x; ++count_1)
	{
		for (int count_2{0}; count_2 < side_length_y; ++count_2)
		{
			if (((abs(count_1 - side_radius_x) > free_side) ||
				(abs(count_2 - side_radius_y) > free_side))) 
			{
				if (((abs(count_1 - side_radius_x) +
					abs(count_2 - side_radius_y)) % 2) == 1)
				{
					if (gamble())
					{
						dungeon[count_1][count_2] = '#';
					}
				}
				
				if (((abs(count_1 - side_radius_x) % 2) == 1) &&
					((abs(count_2 - side_radius_y) % 2) == 1))
				{
					dungeon[count_1][count_2] = '#';
				}				
			}
		}		
	}
	
	dungeon[side_radius_x][side_radius_y] = '*';
				
	player[0] = side_radius_x;
	player[1] = side_radius_y;
	
	int side_x{side_length_x};
	int side_y{side_length_y};
	
	luckey(side_x, side_y);
	
	dungeon[side_x][side_y] = '@';
}
