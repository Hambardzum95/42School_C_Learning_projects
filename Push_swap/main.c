/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:05:27 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 16:05:29 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./srcs/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		a;

	a.error = 0;
	a.print = 1;
	int_array(argc, argv, &a);
	duplicates(&a);
	if (a.error == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (a.count > 0)
		algoritms(&a);
	return (0);
}
