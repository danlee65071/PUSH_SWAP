/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_norm_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:30:51 by lcharlet          #+#    #+#             */
/*   Updated: 2021/10/17 22:14:21 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_double(int argc, char **argv);
static int	check_number(int argc, char **argv, int num, int i);
static int	already_sort(int argc, char **argv);

int	is_norm_args(int argc, char **argv)
{
	int	i;
	int	j;
	int	is_double;
	int	alr_sort;

	i = 1;
	j = 0;
	if (argc == 1)
	{
		printf ("%s", "Пусто\n");
		return (-1);
	}
	while (i < argc)
	{
		if (argv[i][j] == '0')
		{
			j++;
			if (argv[i][j] != '\0')
			{
				printf ("%s", "Wrong_argument\n");
				return (-1);
			}
		}
		if (argv[i][j] == '-')
		{
			j++;
			{
				if (argv[i][j] == '0')
					return (-1);
			}
		}
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < 48 || argv[i][j] > 71)
			{
				printf ("%s", "Wrong_argument\n");
				return (-1);
			}
			j++;
		}
		i++;
		j = 0;
	}
	is_double = check_double(argc, argv);
	if (is_double < 0)
	{
		printf ("%s", "Wrong_argument\n");
		return (-1);
	}
	alr_sort = already_sort(argc, argv);
	if (alr_sort == 0)
		return (2);
	return (0);
}

static int	check_double(int argc, char **argv)
{
	int	i;
	int	num;
	int	res;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		res = check_number(argc, argv, num, i);
		if (res < 0)
			return (-1);
		i++;
	}
	return (0);
}

static int	check_number(int argc, char **argv, int num, int i)
{
	int	all_num;

	i = i + 1;
	while (i < argc)
	{
		all_num = ft_atoi(argv[i]);
		if (all_num == num)
			return (-1);
		i++;
	}
	return (0);
}

static int already_sort(int argc, char **argv)
{
	int	i;

	i = argc - 1;
	while (i > 1)
	{
		if (ft_atoi(argv[i]) > ft_atoi(argv[i - 1]))
			i--;
		else
			return (-1);
	}
	return (0);
}
