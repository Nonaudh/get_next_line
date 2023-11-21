#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*line_to_trim(int fd, char *tab)
{
	char	*buffer = malloc(sizeof(char) * 10);
	int	x;
	while (x != 0 && !(ft_strchr(buffer, '\n')))
	{
		x = read(fd, buffer, 10);
		tab = ft_strjoin(tab, buffer);
	}
	free(buffer);
	printf("tab to trim = %s\n", tab);
	return (tab);
}

char	*trim_the_line(char *tab)
{
	char	*str;
	int	i = 0;
	int	j = 0;

	while (tab[i] && tab[i] != '\n')
		i++;
	
	str = malloc(sizeof(char) * (i + 1));
	while (j < i)
	{
		str[j] = tab[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*next_line(char *tab)
{
	int	i = 0;

	while (tab[i] && tab[i] != '\n')
		i++;
	printf("tab = %s\n", tab);
	return (tab + i);
}

char	*get_next_line(int fd)
{
	static char *tab;
	char	*buffer;

	tab = line_to_trim(fd, tab);
	buffer = trim_the_line(tab);
	tab = next_line(tab);
	return (buffer);
}

int 	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	printf("|%s|\n", get_next_line(fd));
	printf("|%s|\n", get_next_line(fd));
	printf("|%s|\n", get_next_line(fd));
	printf("|%s|\n", get_next_line(fd));
	printf("|%s|\n", get_next_line(fd));


}
