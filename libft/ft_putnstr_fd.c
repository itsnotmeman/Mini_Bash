#include "libft.h"

int	ft_putnstr_fd(char *s, int n, int fd)
{
	int	i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i] != '\0' && i < n)
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}
