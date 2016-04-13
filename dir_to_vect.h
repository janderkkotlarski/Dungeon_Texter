std::vector <int> dir_to_vect(bool& looping)
{
	std::vector <int> vect{0, 0};
	
	const direction dir{type_to_dir()};
	
	if (dir == direction::up)
	{
		vect[0] = -1;
	}
	else if (dir == direction::down)
	{
		vect[0] = 1;
	}
	else if (dir == direction::right)
	{
		vect[1] = 1;
	}
	else if (dir == direction::left)
	{
		vect[1] = -1;
	}
	else if (dir == direction::done)
	{
		looping = false;
	}
	
	return vect;	
}
