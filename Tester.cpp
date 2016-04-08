#include <stdio.h>

int main ()
{
  char c;
  // puts ("Enter text. Include a dot ('.') in a sentence to exit:");
  while (c != '\n')
  {
    c = getchar();
    putchar (c);
    if (c == '.')
    {
		c = '\n';
	}
  }
  return 0;
}
