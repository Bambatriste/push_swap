#include "push_swap.h"

void	sort_2(t_stack **la, t_stack **lb, t_flist *f_list)
{
	t_stack	*a;
	t_stack	*a_next;

	a = *la;
	a_next = a->next;
	if (a->value > a_next->value)
		print_comp(la, lb, f_list, "sa");
}

/*case 1 = SA
case 2 = RA + SA
case 3 = RA
case 4 = RRA
case 5 = SA + RA
*/

int	case_3(int a, int b, int c)
{
	if (a > b && a < c)
		return (1);
	if (a > b && a > c && b > c)
		return (2);
	if (a > b && a > c && b < c)
		return (3);
	if (a < b && b > c && a > c)
		return (4);
	if (a < b && b > c && a < c)
		return (5);
	return (0);
}

void	sort_3(t_stack **la, t_stack **lb, t_flist *f_list)
{
	t_stack	*a;
	t_stack	*a_next;
	t_stack	*a_last;

	a = *la;
	a_next = a->next;
	a_last = get_last(a);
	if (case_3(a->value, a_next->value, a_last->value) == 1)
		print_comp(la, lb, f_list, "sa");
	else if (case_3(a->value, a_next->value, a_last->value) == 2)
	{
		print_comp(la, lb, f_list, "ra");
		print_comp(la, lb, f_list, "sa");
	}
	else if (case_3(a->value, a_next->value, a_last->value) == 3)
		print_comp(la, lb, f_list, "ra");
	else if (case_3(a->value, a_next->value, a_last->value) == 4)
		print_comp(la, lb, f_list, "rra");
	else if (case_3(a->value, a_next->value, a_last->value) == 5)
	{
		print_comp(la, lb, f_list, "sa");
		print_comp(la, lb, f_list, "ra");
	}
}

int	find_lowest_value(t_stack *a, int nb_elems)
{
	int	lowest_value;

	lowest_value = a->value;
	while (a)
	{
		if (a->value <= lowest_value)
			lowest_value = a->value;
		a = a->next;
	}
	return (lowest_value);
}

void	small_sort(t_stack **la, t_stack **lb, t_flist *f_list)
{
	int	size;

	size = get_stacksize(*la);
	if (size == 2)
		sort_2(la, lb, f_list);
	else if (size == 3)
		sort_3(la, lb, f_list);
}
