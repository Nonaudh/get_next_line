#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3

#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

int	ft_strlen(const char *s);
char	*ft_strchr(const char *src, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif