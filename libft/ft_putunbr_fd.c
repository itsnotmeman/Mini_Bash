#include "libft.h"

static int	ft_power_ten(int n);
static int	ft_count_digits(unsigned int n);

int	ft_putunbr_fd(unsigned int n, int fd)
{
	unsigned int	digit;
	int				exp;
	unsigned int	remainder;
	int				printed_len;

	printed_len = 1;
	exp = ft_power_ten(ft_count_digits(n));
	while (exp > 1)
	{
		remainder = n % exp;
		digit = (n - remainder);
		digit = (digit / exp) + '0';
		write(fd, &digit, 1);
		n = remainder;
		exp /= 10;
		++printed_len;
	}
	digit = n + '0';
	write(fd, &digit, 1);
	return (printed_len);
}

static int	ft_power_ten(int n)
{
	int	p;

	p = 1;
	while (n > 1)
	{
		p = p * 10;
		n--;
	}
	return (p);
}

static int	ft_count_digits(unsigned int n)
{
	int	counter;

	counter = 1;
	while (n >= 10)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}
