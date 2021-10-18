/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addelem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:30:51 by lcharlet          #+#    #+#             */
/*   Updated: 2021/10/17 22:14:21 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*addelem(t_list **stack, char *new_chislo)
{
	t_list	*temp;
	t_list	*p;
	int		number;

	number = ft_atoi(new_chislo);
	temp = malloc(sizeof(t_list));
	p = (*stack)->next;
	(*stack)->next = temp;
	temp->chislo = number;
	temp->next = p;
	temp->prev = *stack;
	temp->flag = 0;
	if (p != NULL)
		p->prev = temp;
	return (temp);
}
