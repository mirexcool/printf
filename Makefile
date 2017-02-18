# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/18 16:09:48 by yyefimov          #+#    #+#              #
#    Updated: 2017/02/18 16:34:22 by yyefimov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c

SRC =	*.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
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
