# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbritni <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/17 13:14:25 by lbritni           #+#    #+#              #
#    Updated: 2019/02/20 18:04:21 by lbritni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
DIR_SOURCE = ./srcs/
DIR_INCLUDES = ./includes/
DIR_OBJECTS = ./obj/
SOURCE = $(wildcard $(DIR_SOURCE)*.c)
OBJECTS = $(SOURCE:.c=.o)
FLAGS = -Wall -Wextra -Werror -I$(DIR_INCLUDES)
NAME = fillit

.PHONY: all clean fclean compile objdir re

all: $(NAME)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -rf $(DIR_OBJECTS)
	/bin/rm -f $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)


%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

re: fclean $(NAME)
