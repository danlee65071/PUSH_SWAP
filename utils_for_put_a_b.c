#include "push_swap.h"

t_pta *init_pta(t_list **stack_b, t_pta *pta)
{
	if (pta == NULL)
		pta = malloc(sizeof(t_list));
	pta->count_for_first = 1;
	pta->count_for_last = 2;
	pta->first = *stack_b;
	pta->last = find_last(stack_b);
	return (pta);
}

void	paste_flags(t_list *iterator, t_data *data)
{
	while (iterator != NULL)
	{
		iterator->flag = data->flag;
		iterator = iterator->prev;
	}
}

void first_last_pta(t_list **stack_a, t_list **stack_b, t_data *data, t_pta *pta, int i)
{
	if (i == 1)//first
	{
		pa(stack_a, stack_b);
		top_down(stack_a, data);
		init_pta(stack_b, pta);
	}
	else if (i == 2)
	{
		pta->last = pta->last->next;
		pta->count_for_last = 2;
		rrb(stack_b, 0);
		pa(stack_a, stack_b);
		top_down(stack_a, data);
		pta->first = *stack_b;
		pta->count_for_first = 1;
	}
}

void	first_last_prev_pta(t_list **stack_a, t_list **stack_b, t_data *data, t_pta *pta, int i)
{
	if (i == 1)//first
	{
		while (pta->count_for_first != 1)
		{
			rb(stack_b, 0);
			pta->count_for_first--;
		}
	}
	else if (i == 2 )//last
	{
		while (pta->count_for_last != 1)
		{
			rrb(stack_b, 0);
			pta->count_for_last--;
		}
	}
	pa(stack_a, stack_b);
	top_down(stack_a, data);
	init_pta(stack_b, pta);
}

void top_down(t_list **stack_a, t_data *data)
{
	while ((*stack_a)->order == data->next || (*stack_a)->prev->order == data->next)
	{
		if  ((*stack_a)->prev->order == data->next)
			sa(stack_a, 0);
		ra(stack_a, 0);
		data->next++;
	}
}