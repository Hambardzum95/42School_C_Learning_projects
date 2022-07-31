/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:31:57 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/06/02 15:31:58 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr(char const *s)
{
	size_t i;

	i = 0;
	if (s != NULL)
		while (s[i] != '\0')
			ft_putchar(s[i++]);
	return (i);
}