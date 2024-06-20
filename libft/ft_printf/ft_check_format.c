#include "ft_printf.h"

static int	ft_print_p(va_list args, char format);
static int	ft_print_s(va_list args, int len);

int	ft_check_format_1(char format, va_list args, int array_6)
{
	long	n;
	int		printed_len;

	printed_len = 0;
	if (format == '%')
	{
		printed_len = write(1, "%", 1);
	}
	else if (format == 'c')
	{
		n = va_arg(args, int);
		printed_len = write(1, &n, 1);
	}
	else if (format == 'd' || format == 'i')
	{
		n = va_arg(args, int);
		if (n == 0 && array_6 == 0)
			return (printed_len);
		if (n < 0)
			n = n * (-1);
		printed_len = ft_putunbr_fd(n, 1);
	}
	else if (format == 's')
		printed_len = ft_print_s(args, array_6);
	return (printed_len);
}

int	ft_check_format_2(char format, va_list args, int array_6)
{
	unsigned long	l;
	int				printed_len;
	int				u;

	printed_len = 0;
	if (format == 'p')
	{
		printed_len = ft_print_p(args, format);
	}
	else if (format == 'x' || format == 'X')
	{
		l = va_arg(args, unsigned int);
		if (l == 0 && array_6 == 0)
			return (printed_len);
		printed_len += ft_print_hex_fd(format, l, 1);
	}
	else if (format == 'u')
	{
		u = va_arg(args, int);
		if (u == 0 && array_6 == 0)
			return (printed_len);
		printed_len = ft_putunbr_fd(u, 1);
	}
	return (printed_len);
}

static int	ft_print_p(va_list args, char format)
{
	unsigned long	p;
	int				printed_len;

	printed_len = 0;
	p = va_arg(args, unsigned long);
	printed_len = write(1, "0x", 2);
	printed_len += ft_print_hex_fd(format, p, 1);
	return (printed_len);
}

static int	ft_print_s(va_list args, int len)
{
	char	*s;
	int		printed_len;

	printed_len = 0;
	s = va_arg(args, char *);
	if (!s)
	{
		printed_len = ft_putnstr_fd("(null)", len, 1);
		return (printed_len);
	}
	while (s && *s != '\0' && len > 0)
	{
		printed_len += write(1, s, 1);
		++s;
		--len;
	}
	return (printed_len);
}

int	*ft_array_reset(int *array)
{
	array[0] = 0;
	array[1] = 0;
	array[2] = 0;
	array[3] = 0;
	array[4] = 0;
	array[5] = 0;
	array[6] = 0;
	array[7] = 0;
	array[8] = 0;
	return (array);
}
