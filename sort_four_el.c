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

static void	convert_stack(t_list	**stack_a, t_stack_els	*els);
static int	find_min(t_list	**stack_a);

void	sort_four_el(t_list	**stack_a, t_list	**stack_b)
{
	t_stack_els	els;
	int			min;
	int			i;
	t_list		*iterator;

	convert_stack(stack_a, &els);
	if (!(els.a < els.b && els.c < els.d && els.b < els.c))
	{
		if (els.b < els.a && els.c < els.d && els.a < els.c)
			sa(stack_a, 0);
		else if (els.b < els.c && els.c < els.d && els.d < els.a)
			ra(stack_a, 0);
		else if (els.d < els.a && els.a < els.b && els.b < els.c)
			rra(stack_a, 0);
		else
		{
			min = find_min(stack_a);
			i = 0;
			iterator = *stack_a;
			while (iterator->chislo != min)
			{
				i++;
				iterator = iterator->prev;
			}
			if (i == 3)
				rra(stack_a, 0);
			else if (i == 2)
			{
				rra(stack_a, 0);
				rra(stack_a, 0);
			}
			else if (i == 1)
				sa(stack_a, 0);
			pb(stack_a, stack_b);
			sort_three_el(stack_a, stack_b);
			pa(stack_a, stack_b);
		}

	}
}


static void	convert_stack(t_list	**stack_a, t_stack_els	*els)
{
	els->a = (*stack_a)->chislo;
	els->b = (*stack_a)->prev->chislo;
	els->c = (*stack_a)->prev->prev->chislo;
	els->d = (*stack_a)->prev->prev->prev->chislo;
}

static int	find_min(t_list	**stack_a)
{
	int		min;
	t_list	*i;

	i = *stack_a;
	min = (*stack_a)->chislo;
	while (i != NULL)
	{
		if (i->chislo < min)
			min = i->chislo;
		i = i->prev;
	}
	return (min);
}