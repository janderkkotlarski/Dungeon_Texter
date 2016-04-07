#include <iostream>

#include <cstdio>
#include <stdio.h>
#include <termios.h>
#include <unistd.h> 

#include <string>
#include <vector>

#include <random>

#include <cassert>

int get_char()
{
	struct termios old_t, new_t;
	
	int character;
  
	tcgetattr(STDIN_FILENO, &old_t);
  
	new_t = old_t;  
	new_t.c_lflag &= ~(ICANON | ECHO);
  
	tcsetattr(STDIN_FILENO, TCSANOW, &new_t);
  
	character = getchar();
  
	tcsetattr(STDIN_FILENO, TCSANOW, &old_t);
  
	return character;  
}

char typed_char()
{
	char typed{' '};
	
	while (typed == ' ')
	{
		typed = get_char();
	}
	
	return typed;
	
}



bool gamble()
{	
	unsigned int max_unsigned {static_cast<unsigned int>(-1)};	
	std::random_device rand;	
	const float random_part{static_cast<float>(rand())/static_cast<float>(max_unsigned)};
	
	const float fraction{0.35f};
	assert(fraction > 0.0f);
	assert(fraction < 1.0f);
	
	if (random_part > fraction)
	{
		return true;
	}
	
	return false;
}

bool luckey(const int side_1, const int side_2)
{	
	assert(side_1 > 0);
	assert(side_2 > 0);
	
	unsigned int max_unsigned {static_cast<unsigned int>(-1)};	
	std::random_device rand;	
	const float random_part{static_cast<float>(rand())/static_cast<float>(max_unsigned)};
	
	const float square_fraction{1.3f/static_cast<float>(side_1*side_2)};
	
	const float fraction{1.0f - square_fraction};
	assert(fraction > 0.0f);
	assert(fraction < 1.0f);
	
	if (random_part > fraction)
	{
		return true;
	}
	
	return false;
}

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


int main()
{
	const std::string program_name{"Dungeon Texter V0.3"};
	assert(program_name != "");
	
	char typed{' '};
	assert(typed = ' ');
	
	typed = typed_char();
	
	std::cout << "Welcome to " << program_name << '\n';
	
	std::vector <std::vector <char>> dungeon;
	
	const int dungeon_side{5};
	assert(dungeon_side >= 5);
	
	create_dungeon(dungeon, dungeon_side);
	initiate_dungeon(dungeon);	
	display_dungeon(dungeon);	
	
	return 0;
}
