/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:14:09 by ahuge             #+#    #+#             */
/*   Updated: 2023/11/22 19:23:44 by ahuge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*trim_the_line(char *full_line, size_t	surplus)
{
	int		i;
	char	*final_line;

	i = 0;
	final_line = malloc(sizeof(char) * (ft_strlen(full_line) - surplus + 1));
	if (!final_line)
		return (NULL);
	while (full_line[i] && full_line[i] != '\n')
	{
		final_line[i] = full_line[i];
		i++;
	}
	if (full_line[i] == '\n')
	{
		final_line[i] = '\n';
		i++;
	}
	final_line[i] = 0;
	free (full_line);
	return (final_line);
}

char	*save_surplus(char *full_line)
{
	int		i;
	int		j;
	char	*surplus;

	i = 0;
	j = 0;
	if (!full_line)
		return (NULL);
	while (full_line[i] && full_line[i] != '\n')
		i++;
	if (full_line[i] == '\n')
		i++;
	surplus = malloc(sizeof(char) * (ft_strlen(full_line) - i + 1));
	if (!surplus)
		return (NULL);
	while (full_line[i])
	{
		surplus[j] = full_line[i];
		i++;
		j++;
	}
	surplus[j] = 0;
	return (surplus);
}

char	*fill_the_lines(int fd, char *lines, char *buffer)
{
	int	x;

	x = 1;
	while (!(ft_strchr(buffer, '\n')) && x != 0)
	{
		x = read(fd, buffer, BUFFER_SIZE);
		if (x >= 0)
			buffer[x] = 0;
		if (x == -1 || x == 0)
		{
			free (buffer);
			if (lines[0] != 0 && x == 0)
				return (lines);
			free(lines);
			return (NULL);
		}
		lines = ft_strjoin(lines, buffer);
		if (!lines)
			return (NULL);
	}
	free(buffer);
	return (lines);
}

char	*line_to_trim(int fd, char *surplus)
{
	char	*buffer;
	char	*lines;
	char	*full_line;

	lines = malloc(sizeof(char) * (ft_strlen(surplus) + 1));
	if (!lines)
		return (NULL);
	lines[0] = 0;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	buffer[0] = 0;
	if (surplus)
	{
		ft_strlcpy(lines, surplus, ft_strlen(surplus) + 1);
		free (surplus);
	}
	full_line = fill_the_lines(fd, lines, buffer);
	return (full_line);
}

char	*get_next_line(int fd)
{
	char		*full_line;
	static char	*surplus = NULL;
	char		*final_line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	full_line = line_to_trim(fd, surplus);
	if (!full_line)
		return (NULL);
	surplus = save_surplus(full_line);
	if (!surplus)
		return(NULL);
	if (surplus[0] == 0)
	{
		free(surplus);
		surplus = NULL;
	}
	final_line = trim_the_line(full_line, ft_strlen(surplus));
	return (final_line);
}
/*
int main (void)
{
	int 	fd = open("test2.txt", O_RDONLY);
	char	*line;
	for (int i = 0; i < 2; i++)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free (line);
	}
	close (fd);
	return (1);
}
*/