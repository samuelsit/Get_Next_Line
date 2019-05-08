#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;
	int	i;
	int	ret;

	i = 1;
	ret = 1;
	if (argc > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (0);
	}
	else if (argc < 2)
	{
		ft_putstr("File name missing.\n");
		return (0);
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			printf("%s\n", line);
			free(line);
			i++;
		}
	}
	return (0);
}
