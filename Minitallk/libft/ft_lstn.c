/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:48:10 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 15:48:11 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstn(t_list *lst, size_t n)
{
	if (!lst)
		return (0);
	if (n > 1 && lst->next)
		return (ft_lstn(lst->next, n - 1));
	else if (n <= 1)
		return (lst);
	else
		return (0);
}
