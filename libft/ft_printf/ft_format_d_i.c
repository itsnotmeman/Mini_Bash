#include "ft_printf.h"

static int	*ft_format_d_i_2(int *array);
static int	*ft_format_plus(int *array);

int	*ft_format_d_i(int *array)
{
	if (array[6] > -1)
		array[1] = 0;
	else if (array[6] == (-1) && array[1] == 0)
		array[6] = -2;
	if (array[2])
	{
		if (array[3] || array[4] || array[8])
			--array[5];
		array = ft_format_plus(array);
		if (array[5] < array[6])
			array = ft_zeros_before_nb(array);
		if (array[5] > array[7] && array[5] > array[6])
			array = ft_zeros_before_nb_2(array);
		else
			array[5] = 0;
	}
	else if (array[5] > array[6])
		array = ft_format_d_i_2(array);
	else if (array[5] <= array[6])
	{
		array = ft_format_plus(array);
		array = ft_zeros_before_nb_2(array);
		array[5] = 0;
	}
	return (array);
}

static int	*ft_format_d_i_2(int *array)
{
	if (array[3] || array[4] || array[8])
		--array[5];
	if (array[6] != (-1))
		array = ft_spaces_zeros_padding(array);
	array = ft_format_plus(array);
	while (array[6] > array[7] || array[5] > array[7])
	{
		if (array[1] || array[6] > array[7])
			array[9] += write(1, "0", 1);
		else
			array[9] += write(1, " ", 1);
		--array[6];
		--array[5];
	}
	array[5] = 0;
	return (array);
}

static int	*ft_format_plus(int *array)
{
	if (array[8])
	{
		array[9] += write(1, "-", 1);
	}
	else if (array[4])
	{
		array[9] += write(1, "+", 1);
	}
	else if (array[3])
	{
		array[9] += write(1, " ", 1);
	}
	return (array);
}
