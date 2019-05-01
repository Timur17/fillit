# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/01 15:11:11 by wtorwold          #+#    #+#              #
#    Updated: 2019/02/11 13:25:58 by wtorwold         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

OUT = *.o
SRC = ft_*.c main.c

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -o fillit $(SRC)

clean:
	/bin/rm -f $(OUT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
