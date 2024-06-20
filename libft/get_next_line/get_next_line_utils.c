#include "get_next_line.h"

char	*ft_strjoin_2(char *s1, char *s2)
{
	char	*ptr;
	int		i;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	i = 0;
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (0);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		++i;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		ptr[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	ptr[i + ft_strlen(s1)] = '\0';
	return (ptr);
}
