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

char	*trim_the_line(char *full_line)
{
	int	i = 0;
	char	*final_line;

	final_line = malloc(sizeof(char) * (ft_strlen(full_line) + 1));
		if (!final_line)
			return (NULL);
	while (full_line[i] && full_line[i] != '\n')
	{
		final_line[i] = full_line[i];
		i++;
	}
	i++;////////////////////////////// to check
	final_line[i] = 0;
	free (full_line);
	return (final_line);
}

char	*save_surplus(char *full_line)
{
	int	i = 0;
	int	j = 0;
	char	*surplus;
	if (!full_line)
		return (NULL);
	while (full_line[i] && full_line[i] != '\n')
		i++;
	if (full_line[i] == '\n')
	{	
		i++;///////////////////////////// to check
	}
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

char	*line_to_trim(int fd, char *surplus)
{
	char	*buffer;
	char	*line = NULL;
	int	x = 1;

	if (surplus)
	{
		line = malloc(sizeof(char) * (ft_strlen(surplus) + 1));
		line[0] = 0;
		ft_strlcpy(line, surplus, ft_strlen(surplus) + 1);
		free (surplus);
	}

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
	buffer[0] = 0;
	while (!(ft_strchr(buffer, '\n')) && x != 0)
	{
		x = read(fd, buffer, BUFFER_SIZE);
		buffer[x] = 0;
		
			if (x == -1)
			{
				free(buffer);
				return (NULL);
			}
		line = ft_strjoin(line, buffer);
			if (!line)
				return (NULL);
	}
	free(buffer);
	return (line);	
}

char	*get_next_line(int fd)
{
	char		*full_line;
	static char	*surplus = NULL;/////////////////// malloc ou alloc ?
	char		*final_line;
	
	
	full_line = line_to_trim(fd, surplus);
		if (!full_line)
			return (NULL);		
	surplus = save_surplus(full_line);
		if (!surplus)
			return (NULL);
	final_line = trim_the_line(full_line);
		if (!final_line)
			return (NULL);
	return (final_line);
}

int main ()
{
	int fd = open("test.txt", O_RDONLY);
	char	*line;
	for (int i = 0; i < 4; i++)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free (line);
	}
	close (fd);
	return (1);
}
