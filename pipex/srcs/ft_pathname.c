/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathname.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:30:23 by jchen2            #+#    #+#             */
/*   Updated: 2025/02/02 16:32:36 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_path_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

static char	*join_path(const char *dir, const char *cmd)
{
	char	*path_sep;
	char	*path;

	path_sep = ft_strjoin(dir, "/");
	if (!path_sep)
		return (NULL);
	path = ft_strjoin(path_sep, cmd);
	free(path_sep);
	return (path);
}

static char	*search_exe(char **paths, const char *cmd)
{
	int		i;
	char	*path;

	i = 0;
	while (paths[i])
	{
		path = join_path(paths[i], cmd);
		if (!path)
			return (NULL);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

char	*ft_pathname(char *cmd, char **envp)
{
	char	*path_env;
	char	**paths;
	char	*exe_path;

	exe_path = NULL;
	path_env = find_path_env(envp);
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	exe_path = search_exe(paths, cmd);
	free_split(paths);
	return (exe_path);
}
