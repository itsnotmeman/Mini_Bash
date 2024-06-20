#include "libft.h"

static char	*nullptr(void);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	if (s == 0)
		return (0);
	if ((size_t)start > ft_strlen(s))
	{
		ptr = nullptr();
		return (ptr);
	}
	i = 0;
	if ((ft_strlen(s) - start) < len)
		ptr = ft_calloc((ft_strlen(s) - start + 1), sizeof(char));
	else
		ptr = ft_calloc((len + 1), sizeof(char));
	if (ptr == 0)
		return (0);
	while (i < len && s[start + i] != '\0')
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static char	*nullptr(void)
{
	char	*ptr;

	ptr = ft_calloc(1, sizeof(char));
	if (ptr == 0)
		return (0);
	ptr[0] = '\0';
	return (ptr);
}
