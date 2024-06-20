#include "libft.h"

static void		print_digits(int n, int exp, int fd);
static int		power_ten(int n);
static int		count_digits(int n);

void	ft_putnbr_fd(int n, int fd)
{
	int	digit;
	int	exp;
	int	remainder;

	exp = power_ten(count_digits(n));
	if (n < 0)
	{
		write(fd, "-", 1);
		remainder = n % exp;
		digit = (n - remainder);
		digit = (((-1) * digit) / exp) + '0';
		write(fd, &digit, 1);
		n = (-1) * remainder;
		if (exp > 1)
			print_digits(n, (exp / 10), fd);
	}
	else
		print_digits(n, exp, fd);
}

static void	print_digits(int n, int exp, int fd)
{
	int	remainder;
	int	digit;

	while (exp > 1)
	{
		remainder = n % exp;
		digit = (n - remainder);
		digit = (digit / exp) + '0';
		write(fd, &digit, 1);
		n = remainder;
		exp /= 10;
	}
	digit = n + '0';
	write(fd, &digit, 1);
}

static int	power_ten(int n)
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

static int	count_digits(int n)
{
	int	counter;

	counter = 1;
	if (n > 0)
	{
		while (n >= 10)
		{
			n /= 10;
			counter++;
		}
	}
	else if (n < 0)
	{
		while (n <= -10)
		{
			n /= 10;
			counter++;
		}
	}
	return (counter);
}
