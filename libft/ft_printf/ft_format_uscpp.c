#include "ft_printf.h"

int	*ft_format_u(int *array)
{
	if (array[6] > -1)
		array[1] = 0;
	if (array[2])
	{
		if (array[5] < array[6])
			array = ft_zeros_before_nb(array);
		if (array[5] > array[7] && array[5] > array[6])
			array = ft_zeros_before_nb_2(array);
		else
			array[5] = 0;
	}
	else if (array[5] > array[6])
	{
		array = ft_spaces_zeros_padding(array);
		array = ft_zeros_before_nb(array);
		array[5] = 0;
	}
	else if (array[5] <= array[6])
	{
		array = ft_zeros_before_nb(array);
		array[5] = 0;
	}
	return (array);
}

int	*ft_format_str(int *array)
{
	if (array[6] < 0 || array[6] > array[7])
		array[6] = array[7];
	if (array[2])
	{
		if (array[5] > array[6])
			array[5] = (array[5] - array[6]);
		else
			array[5] = 0;
	}
	else if (array[5] > array[6])
	{
		while (array[5] > array[6])
		{
			array[9] += write(1, " ", 1);
			--array[5];
		}
		array[5] = array[5] - array[6];
	}
	else
		array[5] = 0;
	return (array);
}

int	*ft_format_c_p(int *array)
{
	if (array[2])
	{
		if (array[5] > array[7])
			array[5] = (array[5] - array[7]);
		else
			array[5] = 0;
	}
	else if (array[5])
	{
		while (array[5] > array[7])
		{
			array[9] += write(1, " ", 1);
			--array[5];
		}
		array[5] = array[5] - array[7];
	}
	return (array);
}

int	*ft_format_percent(int *array)
{
	if (array[2])
	{
		if (array[5] > 1)
			--array[5];
	}
	else if (array[5])
	{
		while (array[5] > 1)
		{
			if (array[1])
				array[9] += write(1, "0", 1);
			else
				array[9] += write(1, " ", 1);
			--array[5];
		}
		--array[5];
	}
	return (array);
}
