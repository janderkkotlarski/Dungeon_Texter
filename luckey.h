void luckey(int& side_x, int& side_y)
{	
	assert(side_x > 0);
	assert(side_y > 0);
	
	const int radius_x{(side_x - 1)/2};
	const int radius_y{(side_y - 1)/2};
	
	const int half_radius_x{radius_x/2 + 1};
	const int half_radius_y{radius_y/2 + 1};
	
	int place_x{0};
	int place_y{0};
	
	unsigned int max_unsigned {static_cast<unsigned int>(-1)};	
	std::random_device rand;
	
	while ((abs(place_x) <= half_radius_x) && (abs(place_y) <= half_radius_y))
	{
		place_x = static_cast<int>(
			trunc(static_cast<float>(side_x)*static_cast<float>(rand())/static_cast<float>(max_unsigned))) -
			radius_x;
			
		place_y = static_cast<int>(
			trunc(static_cast<float>(side_y)*static_cast<float>(rand())/static_cast<float>(max_unsigned))) -
			radius_y;	
	}
	
	side_x = place_x + radius_x;
	side_y = place_y + radius_y;
}
