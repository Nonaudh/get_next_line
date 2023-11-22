/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuge <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:00:49 by ahuge             #+#    #+#             */
/*   Updated: 2023/11/22 18:01:29 by ahuge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 10

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h>

int	    ft_strlen(const char *s);
char	*ft_strchr(const char *src, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif
