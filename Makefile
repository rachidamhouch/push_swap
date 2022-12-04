# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 00:43:06 by ramhouch          #+#    #+#              #
#    Updated: 2022/12/02 17:58:26 by ramhouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
BONUS_NAME = checker
CFLAGS=-Wall -Wextra -Werror
SRC = ft_atoi.c last_node.c lstadd_back.c lstadd_front.c lstsize.c main.c new_node.c push.c shiftup.c ss.c swap.c rr.c shiftdown.c rrr.c error.c sort3_5.c sort.c help.c split.c
OBJ = $(SRC:.c=.o)
BONUS_SRC = checker.c ft_atoi.c last_node.c lstadd_back.c lstadd_front.c lstsize.c new_node.c push.c shiftup.c ss.c swap.c rr.c shiftdown.c rrr.c error.c get_next_line_utils.c get_next_line.c help.c split.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		cc -o $(NAME) $(OBJ)

bonus: $(BONUS_OBJ)
		cc -o $(BONUS_NAME) $(BONUS_OBJ)

clean:
		rm -f $(OBJ) $(BONUS_OBJ)
fclean: clean
		rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: clean all fclean re bonus