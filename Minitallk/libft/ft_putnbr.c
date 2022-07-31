/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:50:44 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 15:50:45 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	myputchar(char c)
{
	write(1, &c, 1);
}

void		ft_putnbr(int c)
{
	unsigned int	i;

	i = c;
	if (c < 0)
	{
		myputchar('-');
		i = c * -1;
	}
	if (i / 10 != 0)
		ft_putnbr(i / 10);
	myputchar(i % 10 + 48);
}
