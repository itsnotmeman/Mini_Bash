#include "libft.h"

int	ft_hexlen(unsigned long n)
{
	int	counter;

	counter = 1;
	while (n >= 16)
	{
		n /= 16;
		counter++;
	}
	return (counter);
}
