/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:48:59 by jchen2            #+#    #+#             */
/*   Updated: 2025/02/05 16:49:31 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exe_cmd1(t_pipex *px)
{
	char	*pathname;

	if (dup2(px->fd[0], STDIN_FILENO) == -1)
		error_close_exit("dup2 px->fd[0] fails\n", px, 1);
	if (dup2(px->pfd[1], STDOUT_FILENO) == -1)
		error_close_exit("dup2 px->pfd[1] fails\n", px, 1);
	close(px->pfd[0]);
	close(px->pfd[1]);
	close(px->fd[0]);
	close(px->fd[1]);
	pathname = ft_pathname(px->cmd1[0], px->envp);
	if (!pathname)
		error_close_exit("Command not found\n", px, 127);
	execve(pathname, px->cmd1, px->envp);
	error_close_exit("execve fails\n", px, 1);
}

static void	exe_cmd2(t_pipex *px)
{
	char	*pathname;

	if (px->fd[1] == -1)
		error_close_exit("Fail to open outfile\n", px, 1);
	if (dup2(px->pfd[0], STDIN_FILENO) == -1)
		error_close_exit("dup2 pfd[0] fails\n", px, 1);
	if (dup2(px->fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 outfile fails");
		exit(1);
	}
	close(px->pfd[0]);
	close(px->pfd[1]);
	close(px->fd[0]);
	close(px->fd[1]);
	pathname = ft_pathname(px->cmd2[0], px->envp);
	if (!pathname)
		error_close_exit("Command not found\n", px, 127);
	execve(pathname, px->cmd2, px->envp);
	error_close_exit("execve fails\n", px, 1);
}

static void	fork_exe(t_pipex *px)
{
	int	status;

	px->pid[0] = fork();
	if (px->pid[0] == -1)
		error_close_exit("Fail to create child process\n", px, 1);
	if (px->pid[0] == 0)
		exe_cmd1(px);
	px->pid[1] = fork();
	if (px->pid[1] == -1)
		error_close_exit("Fail to create child process\n", px, 1);
	if (px->pid[1] == 0)
		exe_cmd2(px);
	close(px->pfd[0]);
	close(px->pfd[1]);
	close(px->fd[0]);
	close(px->fd[1]);
	waitpid(px->pid[0], NULL, 0);
	waitpid(px->pid[1], &status, 0);
	free_split(px->cmd1);
	free_split(px->cmd2);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	else
		exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;

	if (argc != 5)
	{
		perror("The arguments is not 5\n");
		exit(1);
	}
	px.fd[0] = open(argv[1], O_RDONLY);
	if (px.fd[0] == -1)
	{
		px.fd[0] = open("/dev/null", O_RDONLY);
		if (px.fd[0] == -1)
			error_close_exit("Fail to open /dev/null\n", &px, 1);
	}
	px.fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	px.envp = envp;
	create_pipe(&px);
	parse_cmd(argv[2], &px.cmd1, &px);
	parse_cmd(argv[3], &px.cmd2, &px);
	fork_exe(&px);
	return (0);
}
