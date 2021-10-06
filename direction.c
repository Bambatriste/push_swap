#include "push_swap.h"

void	get_dir_and_count(t_stack *a, int value, t_index *index_data)
{
	int	count_left;
	int	size;

	count_left = 0;
	size = get_stacksize(a);
	if (!a)
		return ;
	while (a && a->value != value)
	{
		a = a->next;
		count_left++;
	}
	if (count_left <= size / 2)
	{
		index_data->dir = LEFT;
		index_data->r_count = count_left;
	}
	else
	{
		index_data->dir = RIGHT;
		index_data->r_count = size - count_left;
	}
}

void	r_stack(t_stack **la, t_stack **lb, t_index *i_data, t_flist *f_list)
{
	if (i_data->dir == LEFT)
	{
		while (i_data->r_count)
		{
			i_data->r_count--;
			print_comp(la, lb, f_list, "rb");
		}
	}
	else if (i_data->dir == RIGHT)
	{
		while (i_data->r_count)
		{
			i_data->r_count--;
			print_comp(la, lb, f_list, "rrb");
		}
	}
}

void	find_next_key_left(t_stack *a, int key, t_keysdir *keysdir)
{
	int	count_left;

	count_left = 0;
	if (!a)
		return ;
	while (a)
	{
		if (a->value <= key)
			break ;
		count_left++;
		a = a->next;
	}
	keysdir->left_count = count_left;
	keysdir->left_value = a->value;
}

void	find_next_key_right(t_stack *a, int key, t_keysdir *keysdir)
{
	int	count_right;
	int	max_count;
	int	size;
	int	value;

	count_right = 0;
	max_count = 0;
	size = get_stacksize(a);
	if (!a)
		return ;
	while (a)
	{
		if (a->value <= key)
		{
			max_count = count_right;
			value = a->value;
		}
		count_right++;
		a = a->next;
	}
	keysdir->right_count = size - max_count;
	keysdir->right_value = value;
}

void	r_closest(t_stack **la, t_stack **lb, t_flist *f_list, t_keysdir *kdir)
{
	if (kdir->left_count <= kdir->right_count)
	{
		while (kdir->left_count)
		{
			kdir->left_count--;
			print_comp(la, lb, f_list, "ra");
		}
	}
	else
	{
		while (kdir->right_count)
		{
			kdir->right_count--;
			print_comp(la, lb, f_list, "rra");
		}
	}
}
