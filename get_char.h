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
