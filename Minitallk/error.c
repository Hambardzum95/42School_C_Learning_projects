/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:41:30 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/07/28 15:41:33 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	error(char *str_error)
{
	write(2, str_error, ft_strlen(str_error));
	exit(1);
}
