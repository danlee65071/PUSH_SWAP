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

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*buf;

	buf = *stack_b;
	*stack_b = (*stack_b)->prev;
	if (*stack_b != NULL)
		(*stack_b)->next = NULL;
	if (!(*stack_a))
	{
		*stack_a = malloc(sizeof(t_list));
		(*stack_a)->chislo = buf->chislo;
		(*stack_a)->flag = buf->flag;
		(*stack_a)->order = buf->order;
		(*stack_a)->next = NULL;
		(*stack_a)->prev = NULL;
	}
	else
	{
		(*stack_a)->next = malloc(sizeof(t_list));
		(*stack_a)->next->chislo = buf->chislo;
		(*stack_a)->next->flag = buf->flag;
		(*stack_a)->next->order = buf->order;
		(*stack_a)->next->next = NULL;
		(*stack_a)->next->prev = *stack_a;
		*stack_a = (*stack_a)->next;
	}
	free (buf);
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*buf;

	buf = *stack_a;
	*stack_a = (*stack_a)->prev;
	(*stack_a)->next = NULL;
	if (!(*stack_b))
	{
		*stack_b = malloc(sizeof(t_list));
		(*stack_b)->chislo = buf->chislo;
		(*stack_b)->flag = buf->flag;
		(*stack_b)->order = buf->order;
		(*stack_b)->next = NULL;
		(*stack_b)->prev = NULL;
	}
	else
	{
		(*stack_b)->next = malloc(sizeof(t_list));
		(*stack_b)->next->chislo = buf->chislo;
		(*stack_b)->next->flag = buf->flag;
		(*stack_b)->next->order = buf->order;
		(*stack_b)->next->next = NULL;
		(*stack_b)->next->prev = *stack_b;
		*stack_b = (*stack_b)->next;
	}
	free (buf);
	write(1, "pb\n", 3);
}

// void	pa(t_list **stack_a, t_list **stack_b)
// {
// 	t_list	*buf;

// 	buf = *stack_b;
// 	*stack_b = (*stack_b)->prev;
// 	(*stack_a)->next = malloc(sizeof(t_list));
// 	(*stack_a)->next->chislo = buf->chislo;
// 	(*stack_a)->next->order = buf->order;
// 	(*stack_a)->next->flag = buf->flag;
// 	(*stack_a)->next->next = NULL;
// 	(*stack_a)->next->prev = *stack_a;
// 	*stack_a = (*stack_a)->next;
// 	free (buf);
// 	write(1, "pa\n", 3);
// }

// void	pa(t_list **stack_a, t_list **stack_b)
// {
// 	t_list	*buf;

// 	buf = *stack_b;
// 	*stack_b = (*stack_b)->prev;
// 	// (*stack_b)->next = NULL;
// 	addelem_num(stack_a, buf->chislo, buf->order, buf->flag);
// 	free (buf);
// 	write(1, "pa\n", 3);
// }
