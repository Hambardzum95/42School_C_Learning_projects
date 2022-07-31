/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:05:18 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/30 20:05:22 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>

typedef	struct	s_convert
{
	int		minwidthbefore;
	int		minwidth;
	bool	leftalign;
	bool	zeropad;
	bool	mindigits;
	int		precisionbefore;
	int		precision;
	bool	zeroforhex;
}				t_convert;
typedef	struct	s_check
{
	bool		first;
	bool		second;
	int			preccount;
	bool		isdigitexist;
}				t_check;
typedef	struct	s_hex_params
{
	long	n;
	int		w1;
	int		w2;
	int		ret;
	bool	isupper;
}				t_hex_params;

void			ft_get_flags_helper1(va_list args, const char **format,
t_convert *flags, t_check *checkers);
void			ft_get_flags_helper2(va_list args, const char **format,
t_convert *flags, t_check *checkers);
void			ft_print_to_percent(const char **format, int *printed);
void			ft_check_format_end(const char **format);
void			ft_helper1_helper(va_list args, t_convert *flags,
t_check *checkers);
void			ft_final_util(const char **format, t_convert *flags,
t_check *checkers, int *printed);
void			ft_initialize_lists(t_convert *flags, t_check *checkers);
void			ft_specify_flags(t_convert *flags, t_check *checkers);
int				ft_printf(const char *format, ...);
void			ft_putchar(char c);
void			ft_make_unsigned(bool isunsigned, long *n);
void			ft_checkalign(t_convert *flags, int *w1);
void			ft_putspace(int n);
void			ft_putzeros(int n);
int				ft_count_str_max(char *s, int w2);
int				ft_str_max(char *s, int w2);
int				ft_leftalign_str(char *s, int w1);
int				ft_rightalign_str(char *s, int w1);
void			ft_mindigits_leftalign_str(char *s, int *ret, int w1, int w2);
void			ft_mindigits_rightalign_str(char *s, int *ret, int w1, int w2);
int				ft_rightalign_int(long n, int w1, int l);
int				ft_leftalign_int(long n, int w1, int l);
int				ft_mindigits_senseless(long n, int digits, int w2, int l);
int				ft_mindigits_alllogic(long n, t_convert *flags, int w1, int w2);
int				ft_zeropad(long n, int w1, int l);
int				ft_count_len(long n, int w2);
int				ft_mindigits(long n, int w2);
void			ft_putnbr(long nb);
void			ft_putstr(char *s);
size_t			ft_strlen(const char *str);
int				check_base(char *str);
void			ft_putnbr_base(int nbr, char *base);
void			ft_hex(unsigned long long n, bool isupper);
int				ft_get_flags(va_list args, const char *format, int *printed);
int				ft_get_specifiers(va_list args, const char *format,
t_convert *flags);
int				ft_print_char(va_list args, t_convert *flags);
int				ft_print_str(va_list args, t_convert *flags);
int				ft_intlen(long n);
int				ft_print_int(va_list n, t_convert *flags, bool isunsigned);
int				ft_print_pointer(va_list args, t_convert *flags);
int				ft_print_hex(va_list args, t_convert *flags, bool isupper);
int				ft_mindigits_alllogic_hex(t_convert *flags,
t_hex_params *params);
long			ft_initialize_forhex(va_list args, t_convert *flags,
int *w1, int *w2);
void			ft_mindigits_hex_helper_senseless(t_hex_params *params);
int				ft_print_percent(va_list args, t_convert *flags);
void			ft_print_address(size_t addr, bool isupper);
int				ft_count_hex_digits(size_t addr);

#endif
