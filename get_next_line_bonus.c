/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:07:44 by mvolkman          #+#    #+#             */
/*   Updated: 2024/01/18 07:31:59 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*init_storage(char *storage)
{
	if (!storage)
	{
		storage = malloc(1);
		if (storage)
			storage[0] = '\0';
	}
	return (storage);
}

char	*cleanup_and_return(char **storage, char *line)
{
	free(*storage);
	*storage = NULL;
	return (line);
}

char	*extract_line(char **storage)
{
	char	*next_line_pos;
	char	*line;
	char	*new_storage;

	next_line_pos = ft_strchr(*storage, '\n');
	if (!next_line_pos)
	{
		if ((*storage)[0] == '\0')
		{
			free(*storage);
			*storage = NULL;
			return (NULL);
		}
		line = ft_strdup(*storage);
		return (cleanup_and_return(storage, line));
	}
	line = ft_substr(*storage, 0, next_line_pos - *storage + 1);
	if (!line)
		return (cleanup_and_return(storage, line));
	new_storage = ft_strdup(next_line_pos + 1);
	if (!new_storage)
		return (cleanup_and_return(storage, line));
	free(*storage);
	*storage = new_storage;
	return (line);
}

char	*read_to_storage(int fd, char *storage)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	last_read_bytes;
	char	*temp;

	last_read_bytes = read(fd, buffer, BUFFER_SIZE);
	while (last_read_bytes > 0)
	{
		buffer[last_read_bytes] = '\0';
		temp = ft_strjoin(storage, buffer);
		free(storage);
		if (!temp)
			return (NULL);
		storage = temp;
		if (ft_strchr(storage, '\n'))
			break ;
		last_read_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	if (last_read_bytes == -1)
	{
		free(storage);
		return (NULL);
	}
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[FD_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(storage[fd]);
		storage[fd] = NULL;
		return (NULL);
	}
	storage[fd] = init_storage(storage[fd]);
	if (!storage[fd])
		return (NULL);
	storage[fd] = read_to_storage(fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = extract_line(&storage[fd]);
	return (line);
}
