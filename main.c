#include "cub3d.h"

int main()
{
	int fd;
	int a;
	char *line;

	fd = open("../map.cub", O_RDONLY);

	while ((a = get_next_line(fd, &line)) > 0)
	{
		printf("%d |%s", a, line);
		free(line);
	}

	printf("%d ", i);
	printf("%s\n", line);

	close(fd);
	return (0);
}

