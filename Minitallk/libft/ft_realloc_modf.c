/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_modf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:51:36 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 15:51:37 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	*ft_realloc_modf(void *ptr, size_t newsize, size_t oldsize)
{
	void	*new;

	new = ft_memalloc(newsize);
	if (ptr)
	{
		ft_memcpy(new, ptr, oldsize);
		free(ptr);
	}
	return (new);
}
