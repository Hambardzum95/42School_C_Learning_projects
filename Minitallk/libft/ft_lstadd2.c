/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:46:34 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 15:46:35 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	ft_lstadd2(t_list *lst, t_list *new)
{
	if (!lst)
		return ;
	if (!lst->next)
		lst->next = new;
	else
		ft_lstadd2(lst->next, new);
}
