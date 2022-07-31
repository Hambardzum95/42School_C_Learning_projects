/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:31:44 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/02/12 17:31:48 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *elem;

	if (!(elem = (t_list *)malloc(sizeof(*elem))))
	{
		return (NULL);
	}
	elem->content = content;
	elem->next = NULL;
	return (elem);
}
