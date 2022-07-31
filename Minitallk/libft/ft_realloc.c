/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:51:30 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 15:51:31 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t newsize)
{
	void	*new;

	new = ft_memalloc(newsize);
	if (ptr)
	{
		if (ft_strlen((char*)ptr) > newsize)
			ft_memcpy(new, ptr, newsize);
		else
			ft_memcpy(new, ptr, ft_strlen((char*)ptr));
		free(ptr);
	}
	return (new);
}
