bool gamble()
{	
	unsigned int max_unsigned {static_cast<unsigned int>(-1)};	
	std::random_device rand;	
	const float random_part{static_cast<float>(rand())/static_cast<float>(max_unsigned)};
	
	const float fraction{0.65f};
	assert(fraction > 0.0f);
	assert(fraction < 1.0f);
	
	if (random_part > fraction)
	{
		return true;
	}
	
	return false;
}
