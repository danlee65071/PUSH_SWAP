/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:55:40 by lcharlet          #+#    #+#             */
/*   Updated: 2021/10/16 20:07:34 by lcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void move_next_pta(t_pta *pta, int mid_order)
{
	while (pta->first && !(pta->first->order >= mid_order))
	{
		pta->first = pta->first->prev;
		pta->count_for_first++;
	}
	while (pta->last && !(pta->last->order >= mid_order))
	{
		pta->last = pta->last->next;
		pta->count_for_last++;
	}
}

int	find_max_order_again(t_list **stack)
{
	int		max_order;
	t_list	*p;

	if (*stack == NULL)
		return (0);
	p = *stack;
	max_order = p->order;
	while (p != NULL)
	{
		if (p->order > max_order)
			max_order = p->order;
		p = p->prev;
	}
	return (max_order);
}

t_list *find_last(t_list **stack_b)
{
	t_list	*last;

	last = *stack_b;
	if (!last)
		return NULL;
	while (last->prev != NULL)
		last = last->prev;
	return (last);
}