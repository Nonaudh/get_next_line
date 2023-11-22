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

char	*malloc_and_fill(char *s1)
{
	s1 = malloc(sizeof(char) * 1);
	s1[0] = 0;
	return (s1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		z;
	char	*tab;

	i = 0;
	z = 0;
	if (!s1)
		s1 = malloc_and_fill(s1);
	if (!s1 && !s2)
		return (NULL);
	tab = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (tab == NULL)
		return (NULL);
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	while (s2[z])
	{
		tab[i + z] = s2[z];
		z++;
	}
	tab[i + z] = 0;
	return (tab);
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
