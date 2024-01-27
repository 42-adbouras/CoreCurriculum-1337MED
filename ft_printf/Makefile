# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 11:23:34 by adbouras          #+#    #+#              #
#    Updated: 2024/01/14 15:28:59 by adbouras         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

HEADER = ft_printf.h

SOURCE =	ft_printf.c \
			ft_putchar.c \
			ft_putnbr.c \
			ft_putstr.c \
			ft_hex_addr.c \

OBJECT = $(SOURCE:.c=.o)

$(NAME): $(OBJECT) $(HEADER) 
	ar -rc $(NAME) $(OBJECT)
	
all: $(NAME)

clean:
	rm -f $(OBJECT)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
