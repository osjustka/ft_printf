# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 11:04:32 by marvin            #+#    #+#              #
#    Updated: 2023/03/08 11:04:32 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	ft_printf.c \
			ft_putchar_pf.c \
			ft_putstr_pf.c \
			ft_putnbr_pf.c \
			ft_putuint_pf.c \
			ft_puthex_pf.c \
			ft_putptr_pf.c \
			ft_transition_pf.c

NAME		=	libftprintf.a

CC		=	gcc

CFLAGS		=	-Wall -Wextra -Werror

INCLUDES = -I./

OBJS		=	$(SRC:.c=.o)

LINK		=	ar rcs
RM			= 	rm -rf

$(NAME):	$(OBJS)
		$(LINK) $(NAME) $(OBJS)

ft_printf.o: ft_printf.c ft_printf.h

all:	$(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
