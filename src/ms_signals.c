#include "minishell.h"

void	handle_ctrlc_outside_rl(int signo)
{
	if (signo == SIGINT)
	{
		g_status = CTRL_C;
		ft_printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
	}
}

void	handle_ctrlc_inside_rl(int signo)
{
	if (signo == SIGINT)
	{
		g_status = CTRL_C;
		ft_printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	handle_ctrlc_inside_heredoc(int signo)
{
	if (signo == SIGINT)
	{
		g_status = CTRL_C;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
	}
}
