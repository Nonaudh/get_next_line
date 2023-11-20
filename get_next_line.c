#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void    ft_putstr(char *tab)
{
	printf("%s", tab);
}


char	*get_next_line(int fd)
{
	int buffsize = 10;
	char *tab;
	int x = buffsize;

	tab = malloc(sizeof(char) * buffsize);
	while (x == buffsize)
	{
		x = read(fd, tab, buffsize);
		if (x != 0)
			ft_putstr(tab);
	}
	return (tab);
}

int 	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	get_next_line(fd);

}
