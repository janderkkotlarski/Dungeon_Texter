#include <iostream>

#include <cstdio>
#include <stdio.h>
#include <termios.h>
#include <unistd.h> 

#include <string>
#include <vector>

#include <random>

#include <cassert>

enum class direction {up, down, right, left, none};

#include "get_char.h"
#include "typed_char.h"

#include "gamble.h"
#include "luckey.h"

#include "create_dungeon.h"
#include "initiate_dungeon.h"

#include "display_dungeon.h"

#include "type_to_dir.h"

std::vector <int> dir_to_vect()
{
	std::vector <int> vect{0, 0};
	
	const direction dir{type_to_dir()};
	
	switch (dir)
	{
		case direction::up:
			vect[1] = -1;
		case direction::down:
			vect[1] = 1;
		case direction::right:
			vect[0] = 1;
		case direction::left:
			vect[0] = -1;
		case direction::none:
			;
	}
	
	return vect;	
}

void check_and_move(std::vector <std::vector<char>>& dungeon, std::vector <int>& player)
{
	const int side_length_1{static_cast<int>(dungeon.size())};
	assert(side_length_1 > 0);
	
	const int side_length_2{static_cast<int>(dungeon[0].size())};
	assert(side_length_2 > 0);
	
	const std::vector <int> vect{dir_to_vect()};
	
	std::cout << vect[0] << ':' << vect[1];
	
	const std::vector <int> next{(player[0] + vect[0] + side_length_1) % side_length_1,
								 (player[1] + vect[1] + side_length_2) % side_length_2};
	
	if (dungeon[next[0]][next[1]] == ' ')
	{
		dungeon[next[0]][next[1]] = '*';
		dungeon[player[0]][player[1]] = ' ';
		player = next;
	}	
}

int main()
{
	const std::string program_name{"Dungeon Texter V0.3"};
	assert(program_name != "");
	
	char typed{' '};
	assert(typed = ' ');
	
	typed_char(typed);
	
	std::cout << "Welcome to " << program_name << '\n';
	
	std::vector <std::vector <char>> dungeon;
	
	std::vector <int> player{0, 0};
	
	const int dungeon_side{10};
	assert(dungeon_side >= 5);
	
	create_dungeon(dungeon, dungeon_side);
	initiate_dungeon(dungeon, player);
	
	while (true)
	{
		display_dungeon(dungeon);
		check_and_move(dungeon, player);
	}
	
	return 0;
}
