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

// #include "enum_class_direction.h"

#include "type_to_dir.h"

void move_player(std::vector <std::vector <char>>& dungeon, const direction& dir)
{
	
	
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
	
	const int dungeon_side{10};
	assert(dungeon_side >= 5);
	
	create_dungeon(dungeon, dungeon_side);
	initiate_dungeon(dungeon);	
	display_dungeon(dungeon);	
	
	return 0;
}
