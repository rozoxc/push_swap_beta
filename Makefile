# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 14:29:06 by ababdoul          #+#    #+#              #
#    Updated: 2025/01/24 21:19:52 by ababdoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Werror -Wextra -fsanitize=address
NAME = push_swap
HEADER = includes/push_swap.h
SRCS = src/cost.c \
	   src/do_move.c \
	   src/initialization.c \
	   src/input_check.c \
	   src/main.c \
	   src/position.c \
	   src/push.c \
	   src/reverse_rotate.c \
	   src/rotate.c \
	   src/sort.c \
	   src/sort_tiny.c \
	   src/stack.c \
	   src/swap.c\
	   utils/utils.c \
	   utils/input_check_utils.c \
	   utils/ft_split.c \
	   utils/ft_count_number.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

src/%.o: src/%.c $(HEADER)
	$(CC) $(FLAGS) -I./src -c $< -o $@

utils/%.o: utils/%.c $(HEADER)
	$(CC) $(FLAGS) -I./utils -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: clean
