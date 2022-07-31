# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 11:25:31 by hmkrtchy          #+#    #+#              #
#    Updated: 2021/10/06 11:58:29 by hmkrtchy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
SRCS		= main.c init.c error.c utils.c launch_philos.c
OBJS		= $(SRCS:.c=.o)
CLANG		= clang
FLAGS		= -Wall -Wextra -Werror
INCLUDE		= -lpthread
HEADER		= philo.h


all:		$(NAME)

$(NAME):	$(OBJS)
	$(CLANG) $(INCLUDE) $(FLAGS) -o $(NAME) $(OBJS)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		clean fclean re

%.o: %.c $(HEADER)
	$(CLANG) $(FLAGS) -c $<  -o $(<:.c=.o)