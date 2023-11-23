/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:39:12 by ahuge             #+#    #+#             */
/*   Updated: 2023/11/22 18:00:16 by ahuge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlcpy(char *dest, const char *src, size_t size)
{
		size_t	i;
		int		x;

		i = 0;
		x = ft_strlen(src);
		if (size != 0)
		{
			while (src[i] && i < size - 1)
				{
						dest[i] = src[i];
						i++;
				}
				dest[i] = 0;
		}
		return (x);
}

char	*ft_strchr(const char *src, int c)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && src[i] != (char) c)
		i++;
	if (src[i] == (char) c)
		return ((char *)src + i);
	return (0);
}

char	*malloc_and_fill(char *s1)
{
	s1 = malloc(sizeof(char) * 1);
	s1[0] = 0;
	return (s1);
}

char	*ft_strjoin(char *line, char *buffer)
{
	int		i;
	int		z;
	char	*tab;

	i = 0;
	z = 0;
	if (!line)
		line = malloc_and_fill(line);
	if (!line || !buffer)
		return (NULL);
	tab = malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(buffer) + 1));
	if (tab == NULL)
		return (NULL);
	if (line)
	{
	while (line[i])
	{
		tab[i] = line[i];
		i++;
	}
	}
	while (buffer[z])
	{
		tab[i + z] = buffer[z];
		z++;
	}
	tab[i + z] = 0;
	free (line);
	return (tab);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
