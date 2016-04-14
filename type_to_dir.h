direction type_to_dir()
{
	char typed{' '};
	
	direction dir{direction::none};
	assert(dir == direction::none);
	
	typed_char(typed);
	
	std::cout << typed << '\n';
	
	switch (typed)
	{
		case 'w':
			dir = direction::up;
			break;
		case 's':
			dir = direction::down;
			break;
		case 'd':
			dir = direction::right;
			break;
		case 'a':
			dir = direction::left;
			break;
		case '0':
			dir = direction::done;
			break;
		default:
			dir = direction::none;		
	}
	
	return dir;	
}
