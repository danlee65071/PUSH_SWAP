/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:55:40 by lcharlet          #+#    #+#             */
/*   Updated: 2021/10/19 01:48:39 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algoritm(t_list **stack_a, t_list **stack_b, t_data *data)
{
	if (data->argc < 7)
	{
		less_six(stack_a, stack_b, data);
		return ;
	}
	data->max_order = find_max_order(stack_a);
	data->mid_order = data->max_order / 2 + data->next;
	put_in_b(stack_a, stack_b, data);
	while (find_last(stack_a)->order != data->mid_order)
	{
		while (put_in_a(stack_a, stack_b, data) > 0)
			;
		back_to_b(stack_a, stack_b, data);
	}
	sort_second_half(stack_a, stack_b, data);
}

int	find_max_order(t_list **stack)
{
	int		max_order;
	t_list	*p;

	p = *stack;
	if (*stack == NULL)
		return (0);
	max_order = (*stack)->order;
	while (p != NULL)
	{
		if (max_order < p->order)
			max_order = p->order;
		p = p->prev;
	}
	return (max_order);
}

void less_six (t_list **stack_a, t_list **stack_b, t_data *data)
{
	void (*funcs[4])(t_list **stack_a, t_list **stack_b);
	funcs[0] = &sort_two_el;
	funcs[1] = &sort_three_el;
	funcs[2] = &sort_four_el;
	funcs[3] = &sort_five_el;

	funcs[data->argc - 3](stack_a, stack_b);
}
