/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego & parinder <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:38:02 by luhego & parinder #+#    #+#             */
/*   Updated: 2023/12/12 18:33:35 by parinder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	sig_prompt(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_status = 130;
	}
	else if (sig == SIGQUIT)
		g_status = 131;
}

static void	sig_fork(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		g_status = 130;
	}
	else if (sig == SIGQUIT)
	{
		printf("Quit (core dumped)\n");
		g_status = 131;
	}
}

static void	sig_heredoc(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		g_status = 130;
		close(0);
	}
	else if (sig == SIGQUIT)
		g_status = 131;
}

void	ft_set_sighandler(int mode)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (mode == PROMPT)
		sa.sa_handler = &sig_prompt;
	else if (mode == FORK)
		sa.sa_handler = &sig_fork;
	else if (mode == HEREDOC)
		sa.sa_handler = &sig_heredoc;
	sigaction(SIGINT, &sa, 0);
	sigaction(SIGQUIT, &sa, 0);
}
