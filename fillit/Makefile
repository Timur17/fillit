# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/01 15:11:11 by wtorwold          #+#    #+#              #
#    Updated: 2019/05/01 18:26:28 by wtorwold         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

OUT = *.o
SRC = main.c ft_read.c ft_createlist.c libft/ft_strlen.c libft/ft_memcpy.c libft/ft_lstnew.c libft/ft_memalloc.c libft/ft_bzero.c code.c

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -o fillit $(SRC)

clean:
	/bin/rm -f $(OUT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
