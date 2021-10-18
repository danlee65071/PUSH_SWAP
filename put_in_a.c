/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:55:40 by lcharlet          #+#    #+#             */
/*   Updated: 2021/10/19 02:07:07 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int one_two_free_els_to_a(t_list **stack_a, t_list **stack_b, t_data *data);
static int	check_next_element(t_list **stack_a, t_list **stack_b,
								 t_data *data);

int	put_in_a(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	mid;
	int	max;
	int	qnty_push;

	data->flag++;
	max = find_max_order(stack_b);
	mid = (max - data->next) / 2 + data->next;
	qnty_push = 0;
	while (qnty_push < max - mid + 1)
	{
		if (*stack_b == NULL)
			return (0);
		if (check_next_element(stack_a, stack_b, data) == 1)
			continue ;
		if (qnty_els_in_stack(stack_b) < 6)
			return (one_two_free_els_to_a(stack_a, stack_b, data));
		if ((*stack_b)->order >= mid)
		{
			(*stack_b)->flag = data->flag;
			pa(stack_a, stack_b);
			top_down(stack_a, stack_b, data);
			qnty_push++;
		}
		else
			rb(stack_b, 0);
	}
	return (qnty_els_in_stack(stack_b));
}

static int one_two_free_els_to_a(t_list **stack_a, t_list **stack_b, t_data *data)
{
	t_list	*iterator;

	iterator = *stack_b;
	while (iterator)
	{
		iterator->flag = data->flag;
		iterator = iterator->prev;
	}
	check_next_element(stack_a, stack_b, data);
	while (qnty_els_in_stack(stack_b))
	{
		pa(stack_a, stack_b);
		top_down(stack_a, stack_b, data);
	}
	return 0;
}

int	qnty_els_in_stack(t_list **stack)
{
	int	qnty;
	t_list	*iterator;

	qnty = 0;
	iterator = *stack;
	while (iterator != NULL)
	{
		qnty++;
		iterator = iterator->prev;
	}
	return (qnty);
}

static int	check_next_element(t_list **stack_a, t_list **stack_b, t_data *data)
{
	if ((*stack_b) && (*stack_b)->order == data->next)
	{
		(*stack_b)->flag = data->flag;
		pa(stack_a, stack_b);
		if (*stack_b && (*stack_b)->order < data->next)
			rr(stack_a, stack_b);
		else
			ra(stack_a, 0);
		data->next++;
		return (1);
	}
	else if ((*stack_b) && (*stack_b)->prev
		&& (*stack_b)->prev->order == data->next)
		sb(stack_b, 0);
	else if ((*stack_b) && find_last(stack_b)->order == data->next)
		rrb(stack_b, 0);
	else if (*stack_b && find_last(stack_b)->next
		&& find_last(stack_b)->next->order == data->next)
	{
		rrb(stack_b, 0);
		rrb(stack_b, 0);
	}
	else
		return (0);
	(*stack_b)->flag = data->flag;
	pa(stack_a, stack_b);
	if ((*stack_b) && (*stack_b)->order < data->next)
		rr(stack_a, stack_b);
	else
		ra(stack_a, 0);
	data->next++;
	return (1);
}
