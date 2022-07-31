/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:37:36 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/06/02 15:37:36 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_sprintf(const char *format, ...)
{
	va_list	ap;
	t_flag	flags;
	char	*s;
	char	*res;

	res = ft_strnew(1);
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%' && *format)
		{
			res = ft_stradd(res, *format++);
			continue ;
		}
		flags = (*format) ? flag_analazer(++format) : flag_analazer(format);
		if (!(s = specifier(&flags, &ap)))
			continue ;
		format += flags.steps;
		res = ft_strjoin_free(res, s, 3);
	}
	va_end(ap);
	return (res);
}
