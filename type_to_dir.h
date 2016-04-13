direction type_to_dir()
{
	char typed{' '};
	
	direction dir{direction::none};
	assert(dir == direction::none);
	
	typed_char(typed);

	if (typed == 'w')
	{
		dir = direction::up;
	}
	else if (typed == 's')
	{
		dir = direction::down;
	}
	else if (typed == 'd')
	{
		dir = direction::right;
	}
	else if (typed == 'a')
	{
		dir = direction::left;
	}
	else if (typed == '0')
	{
		dir = direction::done;
	}
	
	return dir;	
}
