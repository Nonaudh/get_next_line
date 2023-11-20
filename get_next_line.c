#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	int buffsize = 25;
	char *tab;
	int x = 1;

	tab = malloc(sizeof(char) * 250);
	while (x != 0)
	{
		x = read(fd, tab, buffsize);
	}
	return (tab);
}

int main ()
{
	int fd = open("test.txt", O_RDONLY);
	char *tab =  get_next_line(fd);
	printf("%s", tab);
	free (tab);
	

}
