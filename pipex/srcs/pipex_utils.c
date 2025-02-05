/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:21:15 by jchen2            #+#    #+#             */
/*   Updated: 2025/02/05 16:40:49 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	error_close_exit(char *message, t_pipex *px, int exit_code)
{
	if (px->cmd1)
		free_split(px->cmd1);
	if (px->cmd2)
		free_split(px->cmd2);
	if (px->fd[0] != -1)
		close(px->fd[0]);
	if (px->fd[1] != -1)
		close(px->fd[1]);
	if (px->pfd[0] != -1)
		close(px->pfd[0]);
	if (px->pfd[1] != -1)
		close(px->pfd[1]);
	perror(message);
	exit(exit_code);
}

void	create_pipe(t_pipex *px)
{
	if (pipe(px->pfd) == -1)
		error_close_exit("Fail to create pipe\n", px, 1);
}

void	parse_cmd(char *args, char ***cmd_args, t_pipex *px)
{
	*cmd_args = ft_split(args, ' ');
	if (!(*cmd_args))
		error_close_exit("Fail to split cmd\n", px, 1);
}
