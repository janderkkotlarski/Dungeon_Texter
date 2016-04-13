direction type_to_dir()
{
	char typed{' '};
	
	direction dir{direction::none};
	assert(dir == direction::none);
	
	typed_char(typed);
	
	switch (typed)
	{
		case 'w':
			dir = direction::up;
		case 's':
			dir = direction::down;
		case 'd':
			dir = direction::right;
		case 'a':
			dir = direction::left;		
	}
	
	switch (dir)
	{
		case direction::up:
			std::cout << "up\n";
		case direction::down:
			std::cout << "down\n";
		case direction::right:
			std::cout << "right\n";
		case direction::left:
			std::cout << "left\n";	
		case direction::none:
			std::cout << "none\n";
	}
	
	return dir;	
}
