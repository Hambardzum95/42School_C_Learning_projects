# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/28 16:05:20 by hmkrtchy          #+#    #+#              #
#    Updated: 2021/07/28 16:05:22 by hmkrtchy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= $(shell find "." -maxdepth 2 -name "*.c")
OBJS		= ${SRCS:.c=.o}
NAME		= libpush_swap.a
CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
AR			= ar csr

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) : ${OBJS}
	${AR} $(NAME) ${OBJS}
	gcc main.c -L. -lpush_swap -o push_swap

all : ${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME} ./libft/libft.a push_swap

re : fclean all

.PHONY: all clean fclean re .c.o
