# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/18 15:52:06 by yyefimov          #+#    #+#              #
#    Updated: 2017/02/18 15:52:47 by yyefimov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRC = *.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
		@echo "Doing magic!!!"
		@gcc $(FLAGS) -c $(SRC)
		@ar rc $(NAME) $(OBJ)
		@echo "Vzhuh!!! Printf is ready!!"

		
clean:
		@rm -f $(OBJ)
		@echo "Objects removed"	
fclean:
		@make clean
		@rm -f $(NAME)
		@echo "Executable removed"		
re:
		@make fclean
		@make all
		@ar rc $(NAME) $(OBJ)
