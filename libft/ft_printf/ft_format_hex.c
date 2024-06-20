#include "ft_printf.h"

static int	*ft_format_hex_2(int *array, char format);
static int	*ft_format_sharp(int *array, char format);

int	*ft_format_hex(int *array, char format)
{
	if (array[6] > -1)
		array[1] = 0;
	if (array[2])
	{
		if (array[5] <= array[6])
		{
			array = ft_format_sharp(array, format);
			array = ft_zeros_before_nb(array);
			array[5] = 0;
		}	
		else if (array[5] > array[7])
		{
			array = ft_format_sharp(array, format);
			ft_zeros_before_nb_2(array);
		}
		else
		{
			array = ft_format_sharp(array, format);
			array[5] = 0;
		}
	}
	array = ft_format_hex_2(array, format);
	return (array);
}

static int	*ft_format_hex_2(int *array, char format)
{
	if (array[5] > array[6] && !array[2])
	{
		if (array[0])
			array[5] -= 2;
		if (!(array[0] && array[1]))
			array = ft_spaces_zeros_padding(array);
		array = ft_format_sharp(array, format);
		if (array[0])
			array[6] = array[5] + 2;
		array = ft_zeros_before_nb(array);
		array[5] = 0;
	}
	else if (array[5] <= array[6] && !array[2])
	{
		array = ft_format_sharp(array, format);
		array = ft_zeros_before_nb(array);
		array[5] = 0;
	}
	return (array);
}

static int	*ft_format_sharp(int *array, char format)
{
	if (array[0] && format == 'x')
	{
		array[9] += write(1, "0x", 2);
		array[5] -= 2;
	}
	else if (array[0] && format == 'X')
	{
		array[9] += write(1, "0X", 2);
		array[5] -= 2;
	}
	return (array);
}
