#include <iostream>

#include <cstdio>
#include <stdio.h>
#include <termios.h>
#include <unistd.h> 

#include <string>
#include <vector>

#include <random>

#include <cassert>

enum class direction {up, down, right, left, none, done};

#include "get_char.h"
#include "typed_char.h"

#include "gamble.h"
#include "luckey.h"

#include "create_dungeon.h"
#include "initiate_dungeon.h"

#include "display_part.h"

#include "type_to_dir.h"
#include "dir_to_vect.h"
#include "check_and_move.h"



int main()
{
	const std::string program_name{"Dungeon Texter V0.4"};
	assert(program_name != "");

	std::cout << "Welcome to " << program_name << '\n';
	
	const int sight{2};
	assert(sight > 0);
	
	const int begin_side{4};
	assert(begin_side >= 4);
	
	int level{1};
	assert(level > 0);
	
	const int max_level{10};
	assert(max_level >= level);
	
	while (max_level >= level)
	{
		std::vector <std::vector <char>> dungeon;	
		std::vector <int> player{0, 0};
		
		const int dungeon_side{begin_side + level};
		assert(dungeon_side >= 5);
		
		create_dungeon(dungeon, dungeon_side);
		initiate_dungeon(dungeon, player);
		
		bool looping{true};
		
		while (looping)
		{
			display_part(dungeon, player, sight, level);
			check_and_move(dungeon, player, looping);
		}
		
		++level;
	}
	
	return 0;
}
