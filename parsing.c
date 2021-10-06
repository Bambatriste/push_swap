#include "push_swap.h"

int	check_digits(char *str)
{
	if (str[0] != '-')
	{
		if (!ft_is_only_digits(str))
			return (0);
	}
	else
	{
		if (ft_strlen(str) == 1)
			return (0);
		str++;
		if (!ft_is_only_digits(str))
			return (0);
	}
	return (1);
}

int	check_str(char *str)
{
	const char	*int_max = "2147483647";
	const char	*int_min = "-2147483648";

	if (!check_digits(str))
		return (0);
	if (ft_strlen(str) > 11)
		return (0);
	else if (ft_strlen(str) == 11)
	{
		if (str[0] != '-')
			return (0);
		else if (ft_strncmp(str, int_min, 11) > 0)
			return (0);
	}
	else if (ft_strlen(str) == 10)
	{
		if (ft_strncmp(str, int_max, 10) > 0)
			return (0);
	}
	return (1);
}

void	ft_exit(t_stack **la, t_stack **lb, t_index **index_data, int **array)
{
	destroy_chain(*la, get_stacksize(*la));
	if (lb)
		destroy_chain(*lb, get_stacksize(*lb));
	if (index_data)
		free(*index_data);
	if (array)
		free(*array);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	check_doubles(int value, t_stack *a)
{
	if (!a)
		return (0);
	while (a)
	{
		if (value == a->value)
			return (1);
		a = a->next;
	}
	return (0);
}

void	parsing(int ac, char **av, t_stack **la, int **array)
{
	int	i;
	int	value;

	i = 1;
	while (i < ac)
	{
		if (!check_str(av[i]))
			ft_exit(la, NULL, NULL, NULL);
		value = ft_atoi(av[i]);
		if (check_doubles(value, *la))
			ft_exit(la, NULL, NULL, NULL);
		*la = add_node(*la, i - 1, value);
		i++;
	}
	*array = malloc(sizeof(int) * i);
	if (!*array)
		ft_exit(la, NULL, NULL, NULL);
	i = 1;
	while (i < ac)
	{
		value = ft_atoi(av[i]);
		(*array)[i - 1] = value;
		i++;
	}
}
