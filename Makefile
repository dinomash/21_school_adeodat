# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adeodat <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 18:33:31 by adeodat           #+#    #+#              #
#    Updated: 2021/11/17 18:33:34 by adeodat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER = ft_printf.h

NAME = libftprintf.a

SRCS = ft_printf.c ft_putnbr_10.c ft_putchar.c\
	ft_putstr.c ft_putnbr_u.c ft_putpointer_base.c

OBJS = $(SRCS:.c=.o)

CC = gcc

RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I$(HEADER)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean $(NAME)

.PHONY: all clean fclean re

