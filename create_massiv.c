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

static int	*sort_massiv(int *massiv, int argc);
static void	obmen(int *m_first, int *m_second, int *massiv);

int	*create_massiv(int argc, char **argv)
{
	int	i;
	int	m;
	int	number;
	int	*massiv;

	i = 1;
	m = 0;
	massiv = malloc(sizeof(int) * (argc - 1));
	while (i < argc)
	{
		number = ft_atoi(argv[i]);
		massiv[m] = number;
		m++;
		i++;
	}
	massiv = sort_massiv(massiv, argc);
	return (massiv);
}

static int	*sort_massiv(int *massiv, int argc)
{
	int	m_first;
	int	m_second;
	int	flag;

	if (argc < 3)
		return (massiv);
	flag = 1;
	while (flag == 1)
	{
		flag = 0;
		m_first = 0;
		m_second = 1;
		while (m_second < (argc - 1))
		{
			if (massiv[m_first] < massiv[m_second])
			{
				obmen(&m_first, &m_second, massiv);
				flag = 1;
			}
			else
			{
				m_first++;
				m_second++;
			}
		}
	}
	return (massiv);
}

static void	obmen(int *m_first, int *m_second, int *massiv)
{
	int	temp;

	temp = massiv[*m_first];
	massiv[*m_first] = massiv[*m_second];
	massiv[*m_second] = temp;
}
