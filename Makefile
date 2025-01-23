# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 14:29:06 by ababdoul          #+#    #+#              #
#    Updated: 2025/01/22 14:29:10 by ababdoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Werror -Wextra
NAME = push_swap
HEADER = push_swap.h
SRCS = src/cost.c \
	   src/do_move.c \
	   src/initialization.c \
	   src/input_check.c \
	   src/input_check_utils.c \
	   src/main.c \
	   src/position.c \
	   src/push.c \
	   src/reverse_rotate.c \
	   src/rotate.c \
	   src/sort.c \
	   src/sort_tiny.c \
	   src/stack.c \
	   src/swap.c\
	   src/utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

mandatory/%.o: mandatory/%.c $(HEADER)
	$(CC) $(FLAGS) -I./mandatory -c $< -o $@


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: clean
