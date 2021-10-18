/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:55:40 by lcharlet          #+#    #+#             */
/*   Updated: 2021/10/17 22:14:21 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack, int is_rr)
{
	t_list	*buf;
	t_list	*iterator;

	if (*stack == NULL || (*stack)->prev == NULL)
		return ;
	buf = (*stack);
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
	iterator = *stack;
	while (iterator->prev != NULL)
		iterator = iterator->prev;
	iterator->prev = buf;
	buf->prev = NULL;
	buf->next = iterator;
	if (!is_rr)
		write(1, "ra\n", 3);
}

void	rb(t_list **stack, int is_rr)
{
	t_list	*buf;
	t_list	*iterator;

	if (*stack == NULL || (*stack)->prev == NULL)
		return ;
	buf = (*stack);
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
	iterator = *stack;
	while (iterator->prev != NULL)
		iterator = iterator->prev;
	iterator->prev = buf;
	buf->prev = NULL;
	buf->next = iterator;
	if (!is_rr)
		write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a == NULL || (*stack_a)->prev == NULL || *stack_b == NULL || (*stack_b)->prev == NULL)
		return ;
	ra(stack_a, 1);
	rb(stack_b, 1);
	write(1, "rr\n", 3);
}
