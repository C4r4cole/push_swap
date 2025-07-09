# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/25 17:49:40 by fmoulin           #+#    #+#              #
#    Updated: 2025/07/09 13:33:11 by fmoulin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom des exécutables
NAME = push_swap
BONUS_NAME = checker

# Sources communes
SRCS = src/errors.c src/free.c src/init_b_to_a.c src/push.c src/reverse_rotate.c \
	   src/rotate.c src/sort_stacks.c src/sort_three.c src/stack_init.c src/swap.c \
	   src/utils.c src/index.c

# Mains
MAIN = src/main_push_swap.c
BONUS_MAIN = src/main_checker.c

# Objets
OBJS_DIR = obj
OBJS = $(OBJS_DIR)/main_push_swap.o \
	   $(OBJS_DIR)/errors.o $(OBJS_DIR)/free.o $(OBJS_DIR)/init_b_to_a.o \
	   $(OBJS_DIR)/push.o $(OBJS_DIR)/reverse_rotate.o $(OBJS_DIR)/rotate.o \
	   $(OBJS_DIR)/sort_stacks.o $(OBJS_DIR)/sort_three.o $(OBJS_DIR)/stack_init.o \
	   $(OBJS_DIR)/swap.o $(OBJS_DIR)/utils.o $(OBJS_DIR)/index.o

BONUS_OBJS = $(OBJS_DIR)/main_checker.o \
	   $(OBJS_DIR)/errors.o $(OBJS_DIR)/free.o $(OBJS_DIR)/init_b_to_a.o \
	   $(OBJS_DIR)/push.o $(OBJS_DIR)/reverse_rotate.o $(OBJS_DIR)/rotate.o \
	   $(OBJS_DIR)/sort_stacks.o $(OBJS_DIR)/sort_three.o $(OBJS_DIR)/stack_init.o \
	   $(OBJS_DIR)/swap.o $(OBJS_DIR)/utils.o $(OBJS_DIR)/index.o

# Compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

# Libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Règle par défaut
all: $(LIBFT) $(NAME)

# Libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Exécutable principal
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

# Exécutable bonus (checker)
bonus: $(LIBFT) $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

# Compilation des objets
$(OBJS_DIR)/%.o: src/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
