/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:00:49 by ahuge             #+#    #+#             */
/*   Updated: 2023/11/22 18:43:24 by ahuge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h>

char	*get_next_line(int fd);
int	    ft_strlen(const char *s);
char	*ft_strchr(const char *src, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif
