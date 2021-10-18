#include "push_swap.h"

void first_last_ptb(t_list **stack_a, t_list **stack_b, t_pta *ptb, int i)
{
	if (i == 1)
	{
		pb(stack_a, stack_b);
		ptb->first = *stack_a;
		ptb->count_for_first = 1;
		ptb->last = find_last(stack_a);
		ptb->count_for_last = 2;
	}
	if (i == 2)
	{
		rra(stack_a, 0);
		pb(stack_a, stack_b);
		ptb->first = *stack_a;
		ptb->count_for_first = 1;
		ptb->last = find_last(stack_a);
		ptb->count_for_last = 2;
	}
}

void move_next_ptb(t_pta *ptb, t_data *data)
{
	while (ptb->first && !(ptb->first->order <= data->mid_order))
	{
		ptb->first = ptb->first->prev;
		ptb->count_for_first++;
	}
	while (ptb->last && !(ptb->last->order <= data->mid_order))
	{
		ptb->last = ptb->last->next;
		ptb->count_for_last++;
	}
}

void	first_last_prev_ptb(t_list **stack_a, t_list **stack_b, t_pta *ptb, int i)
{
	if (i == 1)//first
	{
		while (ptb->count_for_first != 1)
		{
			ra(stack_a, 0);
			ptb->count_for_first--;
		}
		pb(stack_a, stack_b);
		ptb->first = *stack_a;
		ptb->count_for_first = 1;
		ptb->last = find_last(stack_a);;
		ptb->count_for_last = 2;
	}
	else if (i == 2 )//last
	{
		while (ptb->count_for_last != 1)
		{
			rra(stack_a, 0);
			ptb->count_for_last--;
		}
		pb(stack_a, stack_b);
		ptb->first = *stack_a;
		ptb->last = find_last(stack_a);
		ptb->count_for_first = 1;
		ptb->count_for_last = 2;
	}
}