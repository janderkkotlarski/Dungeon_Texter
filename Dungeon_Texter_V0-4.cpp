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

#include "display_dungeon.h"

#include "type_to_dir.h"
#include "dir_to_vect.h"
#include "check_and_move.h"



int main()
{
	const std::string program_name{"Dungeon Texter V0.4"};
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
	
	bool looping{true};
	
	while (looping)
	{
		display_dungeon(dungeon);
		check_and_move(dungeon, player, looping);
	}
	
	return 0;
}
