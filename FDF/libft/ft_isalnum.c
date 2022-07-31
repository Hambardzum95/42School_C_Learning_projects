/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:22:04 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/06/02 15:22:06 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalnum(int i)
{
	if ((i >= '0' && i <= '9') || (i >= 'A' && i <= 'Z') ||
			(i >= 'a' && i <= 'z'))
		return (1);
	return (0);
}