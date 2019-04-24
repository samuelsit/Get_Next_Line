#include "get_next_line.h"
#include "libft/libft.h" 
int main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int i = 1;
	int ret = 1;

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
			printf("line %d : <%s> - return = %d\n", i, line, ret);
			free(line);
			i++;
		}
	}
	return (0);
}
