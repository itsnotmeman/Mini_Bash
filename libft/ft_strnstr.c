#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i != len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (haystack[i] == needle[j] && needle[j] != '\0')
			{
				i++;
				j++;
			}
			if (i > len)
				break ;
			i = i - j;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}
