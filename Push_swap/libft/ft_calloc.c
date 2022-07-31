/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:22:10 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/02/03 13:08:56 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t b)
{
	void *q;

	q = malloc(n * b);
	if (q == 0)
	{
		return (q);
	}
	ft_bzero(q, n * b);
	return (q);
}
