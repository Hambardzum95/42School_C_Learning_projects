/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:35:59 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/06/02 15:36:00 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swapi(int *c1, int *c2)
{
	int n;

	n = *c1;
	*c1 = *c2;
	*c2 = n;
}