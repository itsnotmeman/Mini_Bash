#include "libft.h"

static int	ft_char_is_in_set(char c, const char *set);
static int	ft_right(const char *set, const char *s, int beginning, int len_s1);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		beginning;
	int		end;
	int		len_s1;
	char	*trim;

	if (s1 == 0)
		return (0);
	beginning = 0;
	end = 0;
	len_s1 = ft_strlen(s1);
	while (s1[beginning] != '\0')
	{
		if (ft_char_is_in_set(s1[beginning], set) == 0)
			break ;
		beginning++;
	}
	if (s1[beginning] != '\0')
		end = ft_right(set, s1, beginning, len_s1);
	trim = ft_substr(s1, beginning, len_s1 - end - beginning);
	return (trim);
}

static int	ft_right(const char *set, const char *s1, int beginning, int len_s1)
{
	int	end;

	end = 0;
	while ((len_s1 - end) >= 0 && (len_s1 - end) > beginning)
	{
		if (ft_char_is_in_set(s1[len_s1 - end - 1], set) == 0)
			break ;
		end++;
	}
	return (end);
}

static int	ft_char_is_in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
