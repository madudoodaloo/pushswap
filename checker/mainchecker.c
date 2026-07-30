#include "checker.h"

static int	ft_checksyntax(char **cmdl)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	while (cmdl[i])
	{
		if (ft_checkint(cmdl[i]) < 0)
			return (-1);
		i++;
	}
	return (0);
}

float	checker_tokenizer(char **cmdl, t_stack **a)
{
	int	options;
	int	max;
	int	i;

	max = ft_matrixlen(cmdl);
	bench->elements = max;
	i = 0;
	while (cmdl[i] && i < max)
		ft_node_addback(a, ft_nodenew(ft_atoi(cmdl[i++])));
	return (compute_disorder(a));
}


int	checker_parser(char **cmdl, t_stack **a, t_bench *bench)
{
	if (!cmdl || !cmdl[0])
		ft_error(1, a, cmdl);
	if (ft_checksyntax(cmdl) < 0)
		ft_error(2, a, cmdl);
	if (ft_checkdups(cmdl))
		ft_error(3, a, cmdl);
	checker_tokenizer(cmdl, a, bench);
	free_matrix(cmdl);
	return (0);
}

char	**lexer(int ac, char **av)
{
	int		i;
	char	*str;
	char	*temp;
	char	**cmdline;

	i = 0;
	str = ft_strdup("");
	if (!str)
		return (NULL);
	while (++i < ac)
	{
		temp = ft_strjoin(str, av[i]);
		free(str);
		str = ft_strjoin(temp, " ");
		free(temp);
	}
	cmdline = ft_split_strs(str, WHITESPACES);
	free(str);
	return (cmdline);
}


int parse_args
{
	
}


int	main(int ac, char **av)
{
	char	*line;

	if (ac > 1)
	{
		check_nulls(ac, av);

		
		while ((line = get_next_line(STDIN_FILENO)))
		{
			if ()

			
		}
	}
}
