/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:38:41 by lcharlet          #+#    #+#             */
/*   Updated: 2021/10/17 23:25:20 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	back_to_b(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int flag;
	int max_order;

	flag = (*stack_a)->flag;
	max_order = (*stack_a)->order;
	while ((*stack_a)->flag == flag && flag != 0)
	{
		while ((*stack_a)->order == data->next)
		{
			ra(stack_a, 0);
			data->next++;
		}
		if ((*stack_a)->prev->order == data->next)
		{
			sa(stack_a, 0);
			continue ;
		}
		if (max_order < (*stack_a)->order && (*stack_a)->flag == flag)
			max_order = (*stack_a)->order;
		if ((*stack_a)->flag == flag)
			pb(stack_a, stack_b);
	}
	return (max_order);
}
