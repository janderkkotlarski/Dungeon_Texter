void check_and_move(std::vector <std::vector<char>>& dungeon, std::vector <int>& player, bool& looping)
{
	const int side_length_1{static_cast<int>(dungeon.size())};
	assert(side_length_1 > 0);
	
	const int side_length_2{static_cast<int>(dungeon[0].size())};
	assert(side_length_2 > 0);
	
	const std::vector <int> vect{dir_to_vect(looping)};

	const std::vector <int> next{(player[0] + vect[0] + side_length_1) % side_length_1,
								 (player[1] + vect[1] + side_length_2) % side_length_2};
	
	if (dungeon[next[0]][next[1]] == ' ')
	{
		dungeon[next[0]][next[1]] = '*';
		dungeon[player[0]][player[1]] = ' ';
		player = next;
	}
	else if (dungeon[next[0]][next[1]] == '@')
	{
		dungeon[next[0]][next[1]] = '*';
		dungeon[player[0]][player[1]] = ' ';
		player = next;
		looping = false;
	}
}
