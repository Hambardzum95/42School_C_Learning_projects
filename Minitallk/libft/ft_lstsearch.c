/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:48:42 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 15:48:44 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstsearch(t_list *lst, const void *content, size_t size)
{
	if (!ft_memcmp(lst->content, content, size))
		return (lst);
	else if (!(lst->next))
		return (0);
	else
		return (ft_lstsearch(lst->next, content, size));
}
