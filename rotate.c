#include "push_swap.h"

void	r(t_stack **la)
{
	t_stack	*a1;
	t_stack	*a2;
	t_stack	*a3;

	if (*la == NULL)
		return ;
	a2 = (t_stack *)*la;
	a1 = (t_stack *)*la;
	a3 = (t_stack *)*la;
	a3 = a3->next;
	if (a3 == NULL)
		return ;
	while (a1->next)
		a1 = a1->next;
	a2->next = NULL;
	a1->next = a2;
	*la = a3;
}

void	rev_r(t_stack **la)
{
	t_stack	*a1;
	t_stack	*a2;
	t_stack	*a3;

	if (*la == NULL)
		return ;
	a2 = (t_stack *)*la;
	a1 = (t_stack *)*la;
	a3 = (t_stack *)*la;
	while (a1->next)
		a1 = a1->next;
	a1->next = a2;
	while (a3->next != a1)
		a3 = a3->next;
	a3->next = NULL;
	*la = a1;
}

void	rr(t_stack **la, t_stack **lb)
{
	r(la);
	r(lb);
}

void	rrr(t_stack **la, t_stack **lb)
{
	rev_r(la);
	rev_r(lb);
}
