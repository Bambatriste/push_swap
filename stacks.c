#include "push_swap.h"

t_stack	*get_at(t_stack *head, int pos)
{
	while (head->value != pos)
		head = head->next;
	return (head);
}

t_stack	*destroy_node(t_stack *head, int pos)
{
	t_stack	*cur;
	t_stack	*prec;
	int		i;

	cur = head;
	prec = head;
	i = 0;
	if (head == NULL)
		return (NULL);
	if (pos == 0)
	{
		cur = head->next;
		free(head);
		head = cur;
		return (head);
	}
	while (i < pos)
	{
		i++;
		prec = cur;
		cur = cur->next;
	}
	prec->next = cur->next;
	free(cur);
	return (head);
}

t_stack	*destroy_chain(t_stack *head, int chain_size)
{
	int	i;

	i = 0;
	while (i < chain_size)
	{
		head = destroy_node(head, 0);
		i++;
	}
	return (head);
}

t_stack	*create_node(int value)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->value = value;
	stack->next = NULL;
	return (stack);
}

t_stack	*add_node(t_stack *list, int pos, int value)
{
	int		i;
	t_stack	*prec;
	t_stack	*cur;
	t_stack	*cell;

	prec = list;
	cur = list;
	cell = create_node((value));
	if (list == NULL)
		return (cell);
	if (pos == 0)
	{
		cell->next = list;
		return (cell);
	}
	i = 0;
	while (i < pos)
	{
		i++;
		prec = cur;
		cur = cur->next;
	}
	prec->next = cell;
	cell->next = cur;
	return (list);
}
