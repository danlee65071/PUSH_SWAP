/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlet <lcharlet@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:30:51 by lcharlet          #+#    #+#             */
/*   Updated: 2021/10/18 14:42:35 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				chislo;
	struct s_list	*prev;
	struct s_list	*next;
	int				order;
	int				flag;
}	t_list;

typedef struct s_pta
{
	int	count_for_first;
	int	count_for_last;
	t_list	*last;
	t_list	*first;
}	t_pta;

typedef struct s_stack_els
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	e;
}	t_stack_els;

typedef struct s_data
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*massiv;
	int		res;
	int		flag;
	int		next;
	int		argc;
	int		mid_order;
	int		max_order;
}	t_data;

// massiv_and_list
t_list		*create_list(int argc, char **argv, int *massiv);
int			*create_massiv(int argc, char **argv);
int			is_norm_args(int argc, char **argv);
int			ft_atoi(const char *string);
char		*ft_strdup(const char *str);
t_list		*init_list(char *str);
t_list		*addelem(t_list **stack, char *new_chislo);

// инструкции
void		sa(t_list **stack, int is_ss);
void		sb(t_list **stack, int is_ss);
void		ss(t_list **stack_a, t_list **stack_b);
//
void		pa(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
//
void		ra(t_list **stack, int is_rr);
void		rb(t_list **stack, int is_rr);
void		rr(t_list **stack_a, t_list **stack_b);
//
void		rra(t_list **stack, int is_rrr);
void		rrb(t_list **stack, int is_rrr);
void		rrr(t_list **stack_a, t_list **stack_b);

// check
void test(t_list **stack_a, t_list **stack_b);

// sort
void		sort_two_el(t_list	**stack_a, t_list	**stack_b);
void		sort_three_el(t_list	**stack_a, t_list	**stack_b);
void		sort_four_el(t_list	**stack_a, t_list	**stack_b);
void		sort_five_el(t_list	**stack_a, t_list	**stack_b);

// algoritm
void		algoritm(t_list **stack_a, t_list **stack_b, t_data *data);
void		alg_brazh(t_list **stack_a, int argc);
int			put_in_a(t_list **stack_a, t_list **stack_b, t_data *data);
int			back_to_b(t_list **stack_a, t_list **stack_b, t_data *data);
int			find_max_order(t_list **stack_a);
void		sort_second_half(t_list **stack_a, t_list **stack_b, t_data *data);
void 		top_down(t_list **stack_a, t_list **stack_b, t_data *data);
void 		less_six (t_list **stack_a, t_list **stack_b, t_data *data);
void		put_in_b(t_list **stack_a, t_list **stack_b, t_data *data);
int			is_sorted(t_list **stack_a);

//utils functions
// pta
t_pta 	*init_pta(t_list **stack_b, t_pta *pta);
void 	first_last_pta(t_list **stack_a, t_list **stack_b, t_data *data, t_pta *pta, int i);
void	first_last_prev_pta(t_list **stack_a, t_list **stack_b, t_data *data, t_pta *pta, int i);
void	paste_flags(t_list *iterator, t_data *data);
//
void 	move_next_pta(t_pta *pta, int mid_order);
int		find_max_order_again(t_list **stack);
t_list 	*find_last(t_list **stack_b);
int		qnty_els_in_stack(t_list **stack);

//ptb
void 	first_last_ptb(t_list **stack_a, t_list **stack_b, t_pta *pta, int i);
void	move_next_ptb(t_pta *ptb, t_data *data);
void	first_last_prev_ptb(t_list **stack_a, t_list **stack_b, t_pta *ptb, int i);
#endif