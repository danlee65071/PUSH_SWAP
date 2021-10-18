/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:55:40 by lcharlet          #+#    #+#             */
/*   Updated: 2021/10/19 02:00:30 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_in_b(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	qnty_push;

	qnty_push = 0;
	while (qnty_push < data->mid_order - data->next + 1)
	{
		if ((*stack_a)->order <= data->mid_order
			&& (*stack_a)->order > data->next - 1)
		{
			pb(stack_a, stack_b);
			qnty_push++;
		}
		else if (find_last(stack_a)->order <= data->mid_order
			&& find_last(stack_a)->order > data->next - 1)
		{
			if (*stack_b && (*stack_b)->order < data->next)
				rrr(stack_a, stack_b);
			else
				rra(stack_a, 0);
			pb(stack_a, stack_b);
			qnty_push++;
		}
		else
		{
			if (*stack_b && (*stack_b)->order < data->next)
				rr(stack_a, stack_b);
			else
				ra(stack_a, 0);
		}
	}
}

