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
	
	return dir;	
}
