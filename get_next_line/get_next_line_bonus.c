/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:12:02 by jchen2            #+#    #+#             */
/*   Updated: 2024/12/02 12:00:53 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_line(char **storage)
{
	char	*line;
	char	*temp;
	int		len;

	len = 0;
	while ((*storage)[len] != '\n' && (*storage)[len] != '\0')
		len++;
	if ((*storage)[len] == '\n')
		len++;
	line = (char *)malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	line[len] = '\0';
	temp = *storage;
	*storage = ft_strdup(*storage + len);
	if (!*storage)
	{
		free(temp);
		return (NULL);
	}
	while (len--)
		line[len] = (temp)[len];
	free(temp);
	return (line);
}

static int	read_update(int fd, char **storage, char *block)
{
	ssize_t	count;
	char	*temp;

	while (1)
	{
		count = read(fd, block, BUFFER_SIZE);
		if (count <= 0)
			return (count);
		block[count] = '\0';
		if (*storage)
		{
			temp = *storage;
			*storage = ft_strjoin(*storage, block);
			free(temp);
		}
		else
			*storage = ft_strdup(block);
		if (!(*storage))
			return (-1);
		if (ft_strchr(*storage, '\n'))
			break ;
	}
	return (count);
}

static t_list	*get_fd_storage(t_list *fd_list, int fd)
{
	int	i;

	i = 0;
	while (i < FD_SIZE)
	{
		if (fd_list[i].fd == fd)
			return (&fd_list[i]);
		if (fd_list[i].fd == 0)
		{
			fd_list[i].fd = fd;
			fd_list[i].storage = NULL;
			return (&fd_list[i]);
		}
		i++;
	}
	return (NULL);
}

static void	free_fd_storage(t_list *fd_list, int fd)
{
	int	i;

	i = 0;
	while (i < FD_SIZE)
	{
		if (fd_list[i].fd == fd)
		{
			free(fd_list[i].storage);
			fd_list[i].storage = NULL;
			fd_list[i].fd = 0;
			return ;
		}
	}
}

char	*get_next_line(int fd)
{
	static t_list	fd_stor_list[FD_SIZE];
	t_list			*current_fd;
	char			*line;
	char			*block;
	int				count;

	current_fd = get_fd_storage(fd_stor_list, fd);
	if (fd < 0 || BUFFER_SIZE <= 0 || !current_fd)
		return (NULL);
	block = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!block)
		return (NULL);
	count = read_update(fd, &current_fd->storage, block);
	free(block);
	block = NULL;
	if (!current_fd->storage)
		return (NULL);
	if (count == 0 && ft_strlen(current_fd->storage) == 0)
	{
		free_fd_storage(fd_stor_list, fd);
		return (NULL);
	}
	line = get_line(&current_fd->storage);
	return (line);
}
/*
#include "get_next_line_bonus.h"
#include <stdio.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void *read_file(void *arg) {
    int fd = *((int *)arg);
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        printf("Thread %lu read: %s", pthread_self(), line);
        free(line);
    }
    
    close(fd);
    return NULL;
}

int main() {
    pthread_t threads[3];
    int fd1, fd2, fd3;

    fd1 = open("example1.txt", O_RDONLY);
    fd2 = open("example2.txt", O_RDONLY);
	fd3 = open("example3.txt", O_RDONLY);

    if (fd1 < 0 || fd2 < 0 || fd3 < 0) {
        perror("Error opening file");
        return 1;
    }

    pthread_create(&threads[0], NULL, read_file, &fd1);
    pthread_create(&threads[1], NULL, read_file, &fd2);
	pthread_create(&threads[2], NULL, read_file, &fd3);

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
	pthread_join(threads[2], NULL);

    return 0;
}

*/