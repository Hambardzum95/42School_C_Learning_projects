/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:08:15 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 16:08:16 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int	*stack;
	int	count;
	int	error;
	int	print;
	int	place;
}				t_stack;

typedef struct s_index
{
	int	i;
	int	j;
	int	k;
	int	n;
	int	flag;
}				t_index;

int		sa(t_stack *a, char *print);
int		pa(t_stack *a, t_stack *b, char *print);
int		ra(t_stack *a, char *print);
int		rra(t_stack *a, char *print);
int		algoritms(t_stack *a);
int		alg_3(t_stack *a);
int		alg_5_1(t_stack *a, t_stack *b);
int		alg_5_2(t_stack *a, t_stack *b);
int		sorted(t_stack *a);
int		alg_100(t_stack *a, t_stack *b);
int		duplicates(t_stack *a);
int		find_number(t_stack *b, int number);
int		final_sort(t_stack *b);
int		b_min(t_stack *b);
int		b_max(t_stack *b);
int		rr(t_stack *a, t_stack *b);
int		rrr(t_stack *a, t_stack *b);
int		a_b_together(t_stack *a, t_stack *b);
int		rr_rrr(t_stack *a, char *print1, char *print2);
int		find_place(t_stack *a, t_stack *b);
int		pb_sorted(t_stack *a, t_stack *b);
int		make_c(t_stack *a, t_stack *c, int sorted);
void	ft_swap(int *a, int *b);
void	print_step(t_stack *a, char *print);
void	int_array(int argc, char **argv, t_stack *a);
t_stack	*c_stack(t_stack *a, t_stack *c);

#endif
