#include "push_swap.h"

int	get_stacksize(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

t_stack	*get_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	else if (lst->next == NULL)
	{
		return (lst);
	}
	else
		while (lst->next)
			lst = lst->next;
	return (lst);
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i <= nb && i <= 46340)
	{
		if (i * i == nb)
			return (i);
		else if (i * i > nb)
			return (i - 1);
		i++;
	}
	return (0);
}

int	find_highest_value(t_stack *la, int nb_elems)
{
	int	highest_value;
	int	la_value;
	int	i;

	i = 0;
	highest_value = la->value;
	while (i < nb_elems)
	{
		if (highest_value <= la->value)
			highest_value = la->value;
		la = la->next;
		i++;
	}
	return (highest_value);
}

int	is_sorted(t_stack *a)
{
	int		sorted;
	t_stack	*a_next;

	sorted = 1;
	while (a)
	{
		if (a->next == NULL)
			break ;
		a_next = a->next;
		if (a->value > a_next->value)
			sorted = 0;
		a = a->next;
	}
	return (sorted);
}
