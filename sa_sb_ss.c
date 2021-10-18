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

void	sa(t_list **stack, int is_ss)
{
	t_list	*ch_top;
	t_list	*ch_top_minus_minus;

	ch_top = *stack;
	if ((*stack)->prev->prev != NULL)
		ch_top_minus_minus = (*stack)->prev->prev;
	else
		ch_top_minus_minus = NULL;
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
	(*stack)->prev = ch_top;
	if (ch_top_minus_minus != NULL)
		ch_top_minus_minus->next = ch_top;
	ch_top->next = *stack;
	ch_top->prev = ch_top_minus_minus;
	if (!is_ss)
		write(1, "sa\n", 3);
}

void	sb(t_list **stack, int is_ss)
{
	t_list	*ch_top;
	t_list	*ch_top_minus_minus;

	ch_top = *stack;
	if ((*stack)->prev->prev != NULL)
		ch_top_minus_minus = (*stack)->prev->prev;
	else
		ch_top_minus_minus = NULL;
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
	(*stack)->prev = ch_top;
	if (ch_top_minus_minus != NULL)
		ch_top_minus_minus->next = ch_top;
	ch_top->next = *stack;
	ch_top->prev = ch_top_minus_minus;
	if (!is_ss)
		write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a, 1);
	sb(stack_b, 1);
	write(1, "ss\n", 3);
}
