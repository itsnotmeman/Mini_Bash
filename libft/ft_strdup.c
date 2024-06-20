#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (ptr == 0)
		return (0);
	while (i <= ft_strlen(s1))
	{
		ptr[i] = s1[i];
		i++;
	}
	return (ptr);
}
