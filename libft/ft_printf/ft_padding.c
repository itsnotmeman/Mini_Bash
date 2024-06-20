#include "ft_printf.h"

int	*ft_zeros_before_nb(int *array)
{
	while (array[6] > array[7])
	{
		array[9] += write(1, "0", 1);
		--array[6];
	}
	return (array);
}

int	*ft_zeros_before_nb_2(int *array)
{
	if (array[6] > array[7])
	{
		array[5] = array[5] - array[6];
		array = ft_zeros_before_nb(array);
	}
	else
		array[5] = array[5] - array[7];
	return (array);
}

int	*ft_spaces_zeros_padding(int *array)
{
	while (array[5] > array[6] && array[5] > array[7])
	{
		if (array[1])
			array[9] += write(1, "0", 1);
		else
			array[9] += write(1, " ", 1);
		--array[5];
	}
	return (array);
}
