#include "libft.h"

static char	**ft_recursion(char **array, char *s, char c, int flag);
static int	ft_check_array_size(char const *s, char c);
static int	ft_chunk_size(char *s, char c);

char	**ft_split(char const *s, char c)
{
	int		flag;
	char	**array;

	if (s == 0)
		return (0);
	flag = 0;
	array = ft_calloc(ft_check_array_size(s, c), sizeof(char *));
	if (array == 0)
		return (0);
	array = ft_recursion(array, (char *)s, c, flag);
	return (array);
}

static char	**ft_recursion(char **array, char *s, char c, int flag)
{
	int	i;

	i = 0;
	if (s[i] == 0)
	{
		array[flag] = 0;
		return (array);
	}
	while (s[i] == c)
		i++;
	if (ft_strlen(s + i) == 0)
	{
		array[flag] = 0;
		return (array);
	}
	array[flag] = ft_substr(s + i, 0, ft_chunk_size(s + i, c));
	flag++;
	array = ft_recursion(array, (s + i + ft_chunk_size(s + i, c)), c, flag);
	return (array);
}

static int	ft_check_array_size(char const *s, char c)
{
	int	i;
	int	array_size;

	i = 0;
	array_size = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
			i++;
		array_size++;
	}
	if (s[i - 1] != c)
		array_size++;
	return (array_size);
}

static int	ft_chunk_size(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}
