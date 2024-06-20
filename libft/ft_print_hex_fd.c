#include "libft.h"

static unsigned long	ft_power_hex(int n);
static int				ft_count_digits(unsigned long n);
static void				ft_write_digit(const char format, int digit, int fd);

int	ft_print_hex_fd(const char format, unsigned long n, int fd)
{
	unsigned long	exp;
	unsigned long	remainder;
	unsigned long	digit;
	int				printed_len;

	printed_len = 1;
	exp = ft_power_hex(ft_count_digits(n));
	while (exp > 1)
	{
		remainder = n % exp;
		digit = (n - remainder);
		digit = (digit / exp);
		ft_write_digit(format, digit, fd);
		n = remainder;
		exp /= 16;
		++printed_len;
	}
	ft_write_digit(format, n, fd);
	return (printed_len);
}

static void	ft_write_digit(const char format, int digit, int fd)
{
	if (digit >= 10 && (format == 'x' || format == 'p'))
		digit = digit - 10 + 'a';
	else if (digit >= 10 && format == 'X')
		digit = digit - 10 + 'A';
	else
		digit = digit + '0';
	write(fd, &digit, 1);
}

static unsigned long	ft_power_hex(int n)
{
	unsigned long	p;

	p = 1;
	while (n > 1)
	{
		p = p * 16;
		n--;
	}
	return (p);
}

static int	ft_count_digits(unsigned long n)
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
