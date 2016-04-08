void typed_char(char& typed)
{
	typed = ' ';
	assert(typed == ' ');
	
	while (typed == ' ')
	{
		typed = get_char();
	}	
}
