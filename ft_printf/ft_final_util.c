/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:00:20 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/30 20:00:26 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_final_util(const char **format,
		t_convert *flags, t_check *checkers, int *printed)
{
	ft_initialize_lists(flags, checkers);
	ft_print_to_percent(format, printed);
	ft_check_format_end(format);
}
