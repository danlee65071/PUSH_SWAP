/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_second_half.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:06:12 by lcharlet          #+#    #+#             */
/*   Updated: 2021/10/19 02:01:21 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_end(t_list **stack_a, t_list **stack_b, t_data *data);

void	sort_second_half(t_list **stack_a, t_list **stack_b, t_data *data)
{
	while (!is_sorted(stack_a))
	{
		top_down(stack_a, stack_b, data);
		if (sort_end(stack_a, stack_b, data))
			return ;
		data->mid_order = (data->max_order - data->next) / 2 + data->next;
		put_in_b(stack_a, stack_b, data);
		while (find_last(stack_a)->order > data->next - 1)
		{
			if (*stack_b && (*stack_b)->order < data->next)
				rrr(stack_a, stack_b);
			else
				rra(stack_a, 0);
		}
		while (qnty_els_in_stack(stack_b) != 0)
		{
			while (put_in_a(stack_a, stack_b, data) > 0)
				;
			back_to_b(stack_a, stack_b, data);
			top_down(stack_a, stack_b, data);
		}
	}
}

static int	sort_end(t_list **stack_a, t_list **stack_b, t_data *data)
{
	if (data->next >= data->max_order - 5)
	{
		while ((*stack_a)->order >= data->next)
		{
			pb(stack_a, stack_b);
			top_down(stack_a, stack_b, data);
		}
		while (put_in_a(stack_a, stack_b, data) > 0)
			;
		top_down(stack_a, stack_b, data);
		return (1);
	}
	return (0);
}

int	is_sorted(t_list **stack_a)
{
	t_list	*iterator;

	iterator = *stack_a;
	while (iterator->prev)
	{
		if (iterator->order > iterator->prev->order)
			return (0);
		iterator = iterator->prev;
	}
	return (1);
}