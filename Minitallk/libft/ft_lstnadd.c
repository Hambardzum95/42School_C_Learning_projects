/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:48:16 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 15:48:17 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

t_list		*ft_lstnadd(t_list *lst, t_list *new, size_t n)
{
	t_list	*tmp;

	if (!lst)
		return ((void*)0);
	if (n > 2)
		ft_lstnadd(lst->next, new, n - 1);
	if (n == 2)
	{
		tmp = lst->next;
		lst->next = new;
		new->next = tmp;
	}
	return (new);
}
