#include "libft.h"

static long	create_number(const char *str, int i);

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long			number;
	unsigned long	max_long;

	max_long = 9223372036854775807;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	number = create_number(str, i);
	if ((unsigned long)number > max_long + 1 && sign == (-1))
		return (0);
	else if ((unsigned long)number > max_long && sign == 1)
		return (-1);
	return (sign * number);
}

static long	create_number(const char *str, int i)
{
	long	number;

	number = 0;
	while (ft_isdigit(str[i]))
	{
		number = (number * 10) + (str[i] - 48);
		i++;
	}
	return (number);
}
