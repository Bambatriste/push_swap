#include "push_swap.h"

void	print_comp(t_stack **la, t_stack **lb, t_flist *flist, char *move)
{
	ft_putstr_fd(move, 1);
	ft_putchar_fd('\n', 1);
	if (ft_strncmp(move, "sa", 2) == 0)
		flist->fs(la);
	else if (ft_strncmp(move, "sb", 2) == 0)
		flist->fs(lb);
	else if (ft_strncmp(move, "pa", 2) == 0)
		flist->fp(la, lb);
	else if (ft_strncmp(move, "pb", 2) == 0)
		flist->fp(lb, la);
	else if (ft_strncmp(move, "ss", 2) == 0)
		flist->fss(la, lb);
	else if (ft_strncmp(move, "ra", 2) == 0)
		flist->fr(la);
	else if (ft_strncmp(move, "rb", 2) == 0)
		flist->fr(lb);
	else if (ft_strncmp(move, "rra", 3) == 0)
		flist->frev_r(la);
	else if (ft_strncmp(move, "rrb", 3) == 0)
		flist->frev_r(lb);
	else if (ft_strncmp(move, "rrr", 3) == 0)
		flist->frrr(la, lb);
	else if (ft_strncmp(move, "rr", 2) == 0)
		flist->frr(la, lb);
}

void	free_all(t_stack **la, t_stack **lb, t_index *index_data)
{
	destroy_chain(*la, get_stacksize(*la));
	destroy_chain(*lb, get_stacksize(*lb));
	free(index_data->keys);
	free(index_data);
}

int	main(int ac, char **av)
{
	t_stack		*head_a;
	t_stack		*head_b;
	t_flist		f_list;
	t_index		*index_data;
	int			*array;

	head_a = NULL;
	head_b = NULL;
	if (ac != 1)
		parsing(ac, av, &head_a, &array);
	else
		return (0);
	if (!(init(&f_list, &index_data)))
		ft_exit(&head_a, NULL, NULL, NULL);
	if (!get_keys(array, head_a, index_data))
		ft_exit(&head_a, NULL, &index_data, &array);
	if (!is_sorted(head_a) && index_data->size_a <= 3)
		small_sort(&head_a, &head_b, &f_list);
	else if (!is_sorted(head_a))
		sort(&head_a, &head_b, &f_list, index_data);
	free_all(&head_a, &head_b, index_data);
	return (0);
}
