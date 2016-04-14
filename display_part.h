void display_part(const std::vector <std::vector <char>>& dungeon, const std::vector <int>& player, const int sight, const int level)
{
	for (int count{0}; count < 40; ++count)
	{
		std::cout << '\n';
	}
	
	std::cout << "   [w]   \n";
	std::cout << "[a][s][d]\n";
	std::cout << "Level: " << level << '\n';
	
	assert(sight > 0);
	
	const int side_length_1{static_cast<int>(dungeon.size())};	
	assert(side_length_1 > 0);
	
	const int side_length_2{static_cast<int>(dungeon[0].size())};
	assert(side_length_2 > 0);
	
	int point_x{0};
	int point_y{0};	
	
	for (int count_1{-(sight + 1)}; count_1 <= sight + 1; ++count_1)
	{
		point_x = (player[0] + count_1 + side_length_1) % side_length_1;
		
		for (int count_2{-(sight + 1)}; count_2 <= sight + 1; ++count_2)
		{
			point_y = (player[1] + count_2 + side_length_2) % side_length_2;
			
			if ((count_2 >= -sight) && (count_2 <= sight))
			{
				if ((count_1 >= -sight) && (count_1 <= sight))
				{
					std::cout << dungeon[point_x][point_y];
				}
				else
				{
					std::cout << '-';
				}
			}
			else
			{
				if ((count_1 >= -sight) && (count_1 <= sight))
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
