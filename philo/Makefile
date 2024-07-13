# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-amin <ael-amin@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 18:22:23 by ael-amin          #+#    #+#              #
#    Updated: 2023/05/13 09:53:17 by ael-amin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = main.c initParams.c utils.c  life_of_philosophers.c helper_for_routine.c funcs_for_timings.c

OBJ = $(SRC:.c=.o)

CC = gcc

flags = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) philo.h
	@CC $(flags) $(OBJ) -o $(NAME)
	@echo -----Compiled Mandatory part-----

%.o: %.c
	@cc -c $< -o $@
	@echo -----Compiling Objects fils-----
clean:
	@rm -rf $(OBJ)
	@echo -----Deleting Objects files-----

fclean: clean
	@rm -rf $(NAME)
	@echo -----Deleting Output files-----

re:	fclean all
