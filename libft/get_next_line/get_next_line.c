#include "get_next_line.h"

static int	ft_check_input(int fd, int *len, char **buf);
static void	ft_append_line(int len, char **buf, char **nextline, char **rest);
static int	ft_check_newline(char **nextline, char **rest);
static int	ft_check_end_of_file(char *nextfile, char **buf);

char	*get_next_line(int fd)
{
	static char	*rest = 0;
	char		*buf;
	char		*nextline;
	int			len;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (0);
	if (!ft_check_input(fd, &len, &buf))
		return (0);
	ft_append_line(len, &buf, &nextline, &rest);
	while (len)
	{
		free(buf);
		if (ft_check_newline(&nextline, &rest))
			return (nextline);
		if (!ft_check_input(fd, &len, &buf))
			return (0);
		rest = nextline;
		ft_append_line(len, &buf, &nextline, &rest);
	}
	if (ft_check_end_of_file(nextline, &buf))
		return (0);
	if (ft_check_newline(&nextline, &rest))
		return (nextline);
	return (nextline);
}

static int	ft_check_input(int fd, int *len, char **buf)
{
	*buf = malloc(BUFFER_SIZE + 1);
	if (!(*buf))
		return (0);
	*len = read(fd, *buf, BUFFER_SIZE);
	if (*len == -1)
	{
		free(*buf);
		return (0);
	}
	return (1);
}

static void	ft_append_line(int len, char **buf, char **nextline, char **rest)
{
	(*buf)[len] = '\0';
	*nextline = ft_strjoin_2(*rest, *buf);
	free(*rest);
	*rest = 0;
}

static int	ft_check_newline(char **nextline, char **rest)
{
	static int	i = 0;

	while ((*nextline)[i] != '\0')
	{
		if ((*nextline)[i] == '\n')
		{
			*rest = ft_strjoin_2(*nextline + i + 1, "");
			(*nextline)[i + 1] = '\0';
			i = 0;
			return (1);
		}
		++i;
	}
	return (0);
}

static int	ft_check_end_of_file(char *nextline, char **buf)
{
	free(*buf);
	if (nextline[0] == '\0')
	{
		free(nextline);
		return (1);
	}
	return (0);
}
