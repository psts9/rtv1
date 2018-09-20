#include "rtv1.h"
#include "init.h"
#include "loop.h"
#include "libft.h"

int main(int argc, char **argv)
{
	t_prog	prog;

	if (argc != 2)
	{
		ft_putstr("Usage: ");
		ft_putstr(argv[0]);
		ft_putendl(" scene_file");
		return (1);
	}
	init(&prog, argv[0]);
	run(&prog, argv[1]);
	return (0);
}
