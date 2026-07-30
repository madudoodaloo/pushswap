#include "checker.h"

int	main(int ac, char **av)
{
	char	*line;

	if (ac > 1)
	{
		check_nulls(ac, av);
		push_swap(ac, av);
		while ((line = get_next_line(STDOUT_FILENO)))
		{
			if ()

			
		}
	}
}
