# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/30 20:08:45 by hmkrtchy          #+#    #+#              #
#    Updated: 2021/03/30 20:08:51 by hmkrtchy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= ft_hex.c ft_print_char.c ft_print_hex.c ft_print_int.c ft_print_pointer.c \
				  ft_print_str.c ft_printf.c ft_putnbr.c ft_strlen.c ft_print_percent.c \
				  ft_utils.c ft_str_utils.c ft_int_utils.c ft_hex_utils.c ft_get_flags_utils.c \
				  ft_final_util.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
