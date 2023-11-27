#include "../../minishell.h"

int	ft_echo(t_cmd *cmds)
{
	int	i;

	i = 1;
	if (cmds->cmd[1] && !ft_strncmp(cmds->cmd[1], "-n", 3))
		i = 2;
	while (cmds->cmd[i])
	{
		write(cmds->fd_out, cmds->cmd[i], ft_strlen(cmds->cmd[i]) + 1);
		i++;
	}
	if (!cmds->cmd[1] || ft_strncmp(cmds->cmd[1], "-n", 3))
		write(cmds->fd_out, "\n", 2);
	return  (0);
}
