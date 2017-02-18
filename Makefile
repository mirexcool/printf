# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/18 16:09:48 by yyefimov          #+#    #+#              #
#    Updated: 2017/02/18 16:14:06 by yyefimov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c

SRC =	ft_itoa_long.c\
		formatting_cs.c\
		final_print.c\
		formats_spdio.c\
		to_formatting.c\
		ft_bzero.c\
		to_flags.c\
		ft_atoi.c\
		formatting.c\
		ft_printf.c\
		ft_strcat.c\
		get_flags.c\
		ft_itoa_unsigned.c\
		ft_strchr.c\
		ft_strnew.c\
		ft_putstr.c\
		ft_strsub.c\
		ft_strdup.c\
		make_cast.c\
		ft_strcmp.c\
		ft_strjoin.c\
		formats_uxc.c\
		get_s.c\
		ft_strlen.c\
		join_wide.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
		clear
		@$(CC) -c $(SRC) $(CFLAGS) 
		@ar rc $(NAME) $(OBJ)
		
clean:
		@rm -f $(OBJ)
		
fclean:
		@make clean
		@rm -f $(NAME)		
re:
		@make fclean
		@make all
		@ar rc $(NAME) $(OBJ)
