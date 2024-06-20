#include "ft_printf.h"

static int	*ft_p_2(char *format, va_list args, va_list args_2, int *array);
static int	*ft_print_flags(const char *format, va_list args, int *array);
static int	*ft_check_flags(const char *format, int *array);
static int	ft_check_flags_len(const char *format);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_list	args_2;
	int		*array;
	int		len;

	va_start(args, format);
	va_copy(args_2, args);
	array = ft_calloc(10, sizeof(int));
	if (array == 0)
		return (0);
	ft_p_2((char *)format, args, args_2, array);
	va_end(args);
	va_end(args_2);
	len = array[9];
	free(array);
	return (len);
}

static int	*ft_p_2(char *format, va_list args, va_list args_2, int *array)
{
	while (*format != '\0')
	{
		if (*format == '%')
		{
			array = ft_print_flags(format + 1, args, array);
			format = format + ft_check_flags_len(format + 1);
			if (ft_strchr("cspdiuxX%", *(++format)))
			{
				array[9] += ft_check_format_1(*format, args_2, array[6]);
				array[9] += ft_check_format_2(*format, args_2, array[6]);
				while (array[5] > 0)
				{
					array[9] += write(1, " ", 1);
					--array[5];
				}
			}
			else
				return (0);
		}
		else
			array[9] += write(1, format, 1);
		++format;
		array = ft_array_reset(array);
	}
	return (array);
}

static int	*ft_print_flags(const char *format, va_list args, int *array)
{
	array = ft_check_flags(format, array);
	format = format + ft_check_flags_len(format);
	array = ft_count_len_1(*format, args, array);
	array = ft_count_len_2(*format, args, array);
	array = ft_count_len_3(*format, args, array);
	if (*format == '%')
		array = ft_format_percent(array);
	else if (*format == 'c' || *format == 'p')
		array = ft_format_c_p(array);
	else if (*format == 's')
		array = ft_format_str(array);
	else if (*format == 'd' || *format == 'i')
		array = ft_format_d_i(array);
	else if (*format == 'u')
		array = ft_format_u(array);
	else if (*format == 'x' || *format == 'X')
		array = ft_format_hex(array, *format);
	return (array);
}

static int	*ft_check_flags(const char *format, int *array)
{
	while (ft_strchr("-0# +", *(format)))
	{
		if (*format == '#')
			array[0]++;
		else if (*format == '0')
			array[1]++;
		else if (*format == '-')
			array[2]++;
		else if (*format == ' ')
			array[3]++;
		else if (*format == '+')
			array[4]++;
		++format;
	}
	if (ft_isdigit(*format))
	{
		array[5] = ft_atoi(format);
		format += ft_nbrlen(array[5], 0, 1);
	}
	array[6] = -1;
	if (*format == '.')
		array[6] = ft_atoi(format + 1);
	return (array);
}

static int	ft_check_flags_len(const char *format)
{
	int	flags_len;

	flags_len = 0;
	while (ft_strchr("-0.# +", *format) || ft_isdigit(*format))
	{
		flags_len++;
		format++;
	}
	return (flags_len);
}
