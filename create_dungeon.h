void create_dungeon(std::vector <std::vector <char>>& dungeon, const int dungeon_side)
{	
	const int side_length{2*dungeon_side + 1};
	
	for (int count_1{0}; count_1 < side_length; ++count_1)
	{
		std::vector <char> dungeon_strip;
		
		for (int count_2{0}; count_2 < side_length; ++count_2)
		{
			dungeon_strip.push_back(' ');
		}
		
		dungeon.push_back(dungeon_strip);		
	}	
}
