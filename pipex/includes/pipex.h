/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:06:34 by jchen2            #+#    #+#             */
/*   Updated: 2025/02/05 16:37:33 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include "../libft/libft.h"

typedef struct s_pipex
{
	int		fd[2];
	int		pfd[2];
	pid_t	pid[2];
	char	**cmd1;
	char	**cmd2;
	char	**envp;
}	t_pipex;

void	error_close_exit(char *message, t_pipex *px, int exit_code);
void	create_pipe(t_pipex *px);
void	parse_cmd(char *args, char ***cmd_args, t_pipex *px);
char	*ft_pathname(char *cmd, char **envp);
void	free_split(char **split);

#endif
