/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:47:56 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 15:47:57 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	if (!lst || !f)
		return ((void*)0);
	if (lst->next != 0)
	{
		if ((new = f(lst)))
			new->next = ft_lstmap(lst->next, f);
		else
			return (0);
	}
	else
	{
		if ((new = f(lst)))
			new->next = 0;
		else
			return (0);
	}
	return (new);
}
