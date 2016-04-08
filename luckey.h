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
