/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:03:37 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/30 20:03:42 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_leftalign_str(char *s, int w1)
{
	ft_putstr(s);
	ft_putspace(w1 - (int)ft_strlen(s));
	return (w1 - (int)ft_strlen(s) >= 0 ? w1 : (int)ft_strlen(s));
}

int		ft_rightalign_str(char *s, int w1)
{
	ft_putspace(w1 - (int)ft_strlen(s));
	ft_putstr(s);
	return (w1 - (int)ft_strlen(s) >= 0 ? w1 : (int)ft_strlen(s));
}

void	ft_mindigits_leftalign_str(char *s, int *ret, int w1, int w2)
{
	*ret = ft_str_max(s, w2);
	ft_putspace(w1 - *ret);
}

void	ft_mindigits_rightalign_str(char *s, int *ret, int w1, int w2)
{
	*ret = ft_count_str_max(s, w2);
	ft_putspace(w1 - *ret);
	ft_str_max(s, w2);
}

int		ft_print_str(va_list args, t_convert *flags)
{
	char	*s;
	int		w1;
	int		w2;
	int		ret;

	s = va_arg(args, char *);
	s = (s == NULL) ? "(null)" : s;
	w1 = flags->minwidthbefore != 0 ? flags->minwidthbefore
	: flags->precisionbefore;
	w2 = flags->minwidth != 0 ? flags->minwidth : flags->precision;
	ft_checkalign(flags, &w1);
	if (flags->mindigits)
	{
		if (flags->leftalign)
			ft_mindigits_leftalign_str(s, &ret, w1, w2);
		else
			ft_mindigits_rightalign_str(s, &ret, w1, w2);
		return ((w1 >= ret) ? w1 : ret);
	}
	else if (flags->leftalign)
		return (ft_leftalign_str(s, w1));
	else
		return (ft_rightalign_str(s, w1));
}
