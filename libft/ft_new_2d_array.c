#include "libft.h"

void	**ft_new_2d_void_array(int row, int col, int type_size)
{
	void	**array;
	int		i;

	array = malloc((row + 1) * sizeof(void *));
	if (!array)
		return (0);
	i = 0;
	while (i < row)
	{
		array[i] = malloc(col * type_size);
		if (!array[i])
		{
			while (i != 0)
			{
				free(array[i - 1]);
				--i;
			}
			free(array);
			return (0);
		}
		++i;
	}
	array[i] = 0;
	return (array);
}

int	**ft_new_2d_int_array(int row, int col)
{
	int	**array;
	int	i;

	array = malloc((row + 1) * sizeof(int *));
	if (!array)
		return (0);
	i = 0;
	while (i < row)
	{
		array[i] = malloc(col * sizeof(int));
		if (!array[i])
		{
			while (i != 0)
			{
				free(array[i - 1]);
				--i;
			}
			free(array);
			return (0);
		}
		++i;
	}
	array[i] = 0;
	return (array);
}

char	**ft_new_2d_char_array(int row, int col)
{
	char	**array;
	int		i;

	array = malloc((row + 1) * sizeof(char *));
	if (!array)
		return (0);
	i = 0;
	while (i < row)
	{
		array[i] = malloc(col * sizeof(char));
		if (!array[i])
		{
			while (i != 0)
			{
				free(array[i - 1]);
				--i;
			}
			free(array);
			return (0);
		}
		++i;
	}
	array[i] = 0;
	return (array);
}
