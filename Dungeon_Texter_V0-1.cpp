#include <iostream>
#include <cstdio>
#include <cmath>
#include <stdio.h>
#include <termios.h>
#include <unistd.h> 
#include <string>
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

int main()
{
	const std::string program_name{"Dungeon Texter V0.1"};
	assert(program_name != "");
	
	char typed{' '};
	assert(typed = ' ');
	
	while (typed == ' ')
	{
		typed = get_char();
	}
	
	std::cout << typed << '\n';
	
	return 0;
}
