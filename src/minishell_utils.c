#include "minishell.h"

int	count_commands(char *argv[])
{
	int	i;

	i = 0;
	if (argv == NULL)
		return (0);
	while (argv[i] != NULL)
		++i;
	return (i);
}

int	path_is_directory(const char *path)
{
	struct stat	path_stat;

	if (stat(path, &path_stat) == -1)
		return (FAILURE);
	return (S_ISDIR(path_stat.st_mode));
}
