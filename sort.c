#include "push_swap.h"

void	swap_if_lower(t_stack **la, t_stack **lb, t_flist *flist)
{
	t_stack	*b;
	t_stack	*b_next;

	if (!*lb || !*la)
		return ;
	b = *lb;
	b_next = b->next;
	if (b->next == NULL)
		return ;
	if (b->value < b_next->value)
		print_comp(la, lb, flist, "sb");
}

void	p_chunks(t_stack **la, t_stack **lb, t_flist *f_list, t_index *i_data)
{
	int			i;
	int			j;
	int			key;
	t_keysdir	*keysdir;

	i = 0;
	j = 0;
	keysdir = malloc(sizeof(t_keysdir));
	if (!keysdir)
		ft_exit(la, lb, &i_data, NULL);
	while (i < i_data->chunks)
	{
		key = i_data->keys[i];
		while (j++ < i_data->chunksize)
		{
			find_next_key_left(*la, key, keysdir);
			find_next_key_right(*la, key, keysdir);
			r_closest(la, lb, f_list, keysdir);
			print_comp(la, lb, f_list, "pb");
			swap_if_lower(la, lb, f_list);
		}
		i++;
		j = 0;
	}
	free(keysdir);
}

void	sort(t_stack **la, t_stack **lb, t_flist *f_list, t_index *index_data)
{
	int	highest_val;

	p_chunks(la, lb, f_list, index_data);
	if (get_stacksize(*la) == 3)
		sort_3(la, lb, f_list);
	else if (get_stacksize(*la) == 2)
		sort_2(la, lb, f_list);
	else
	{
		while (*la)
		{
			print_comp(la, lb, f_list, "pb");
			swap_if_lower(la, lb, f_list);
		}
	}
	while (*lb)
	{
		highest_val = find_highest_value(*lb, get_stacksize(*lb));
		get_dir_and_count(*lb, highest_val, index_data);
		r_stack(la, lb, index_data, f_list);
		print_comp(la, lb, f_list, "pa");
	}
}
