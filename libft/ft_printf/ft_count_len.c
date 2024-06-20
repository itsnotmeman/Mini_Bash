#include "ft_printf.h"

int	*ft_count_len_1(char format, va_list args, int *array)
{
	long	n;

	if (format == '%' || format == 'c')
		array[7] = 1;
	if (format == 'c')
		va_arg(args, int);
	else if (format == 'd' || format == 'i')
	{
		n = va_arg(args, int);
		if (n < 0)
		{
			array[8] = 1;
			n = n * (-1);
		}
		array[7] = ft_nbrlen(n, n, 1);
		if (n == 0 && array[6] == 0)
			array[7] = 0;
	}
	return (array);
}

int	*ft_count_len_2(char format, va_list args, int *array)
{
	unsigned long	l;

	if (format == 'p')
	{
		l = va_arg(args, unsigned long);
		array[7] = ft_hexlen(l) + 2;
	}
	else if (format == 'x' || format == 'X')
	{
		l = va_arg(args, unsigned int);
		if (l == 0)
			array[0] = 0;
		array[7] = ft_hexlen(l);
		if (l == 0 && array[6] == 0)
			array[7] = 0;
	}
	return (array);
}

int	*ft_count_len_3(char format, va_list args, int *array)
{
	char	*s;
	int		u;

	if (format == 's')
	{
		s = va_arg(args, char *);
		if (!s && array[6] < 6 && array[6] > (-1))
			array[7] = array[6];
		if (!s)
			array[7] = 6;
		else
			array[7] = ft_strlen(s);
	}
	else if (format == 'u')
	{
		u = va_arg(args, int);
		array[7] = ft_nbrlen(u, u, 0);
		if (u == 0 && array[6] == 0)
			array[7] = 0;
	}
	return (array);
}
