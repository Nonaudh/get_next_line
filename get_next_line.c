/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:14:09 by ahuge             #+#    #+#             */
/*   Updated: 2023/11/22 18:30:41 by ahuge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*left_line(char *temp)
{
	int	i = 0;
	int	j = 0;
	char	*tab;

	while (temp[i] && temp[i - 1] != '\n')
		i++;

	tab = malloc(sizeof(char) * (ft_strlen(temp) - i + 1));
		if (!tab)
			return (NULL);
	while (temp[i])
	{
		tab[j] = temp[i];
		i++;
		j++;
	}
	tab[j] = 0;
	return (tab);
}

char	*line_to_trim(int fd, char *tab)
{
	char	*buffer;
	char	*temp;
	int	x = 1;

	temp = tab;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);

	while (x != 0 && !(ft_strchr(buffer, '\n')))
	{
		x = read(fd, buffer, BUFFER_SIZE);
			if (x == -1)
				return (NULL);
		temp = ft_strjoin(temp, buffer);
			if (!temp)
				return (NULL);
	}
	return (temp);
		
}

char	*trim_the_line(char *tab)
{
	int	i = 0;
	char	*temp;
	
	temp = malloc(sizeof(char) * (ft_strlen(tab) + 1));
		if (!temp)
			return (NULL);
	while (tab[i] && tab[i - 1] != '\n')
	{
		temp[i] = tab[i];
		i++;
	}
	temp[i] = 0;
	return (temp);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	static char	*tab = NULL;
	
	buffer = line_to_trim(fd, tab);
		if (!buffer)
			return (NULL);	
	tab = left_line(buffer);
	buffer = trim_the_line(buffer);
		if (!buffer)
			return (NULL);
	return (buffer);
}

int main ()
{
	int fd = open("test.txt", O_RDONLY);
	for (int i = 0; i < 8; i++)
		printf("%s", get_next_line(fd));

}
