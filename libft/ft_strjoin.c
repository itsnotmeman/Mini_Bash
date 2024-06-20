#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_len;
	char	*str;

	if (s1 == 0 || s2 == 0)
		return (0);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	str = ft_calloc(total_len + 1, sizeof(char));
	if (str == 0)
		return (0);
	ft_strlcpy(str, s1, total_len + 1);
	ft_strlcat(str, s2, total_len + 1);
	return (str);
}
