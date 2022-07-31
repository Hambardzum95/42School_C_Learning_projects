/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:41:36 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/10/10 16:59:37 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	write_error(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(1, "Error: ", 7);
	write(1, str, len);
	write(1, "\n", 1);
	return (1);
}

int	which_error(int err)
{
	if (err == 1)
		return (write_error("At least one wrong argument"));
	if (err == 2)
		return (write_error("Can't initialize mutex"));
	return (1);
}
