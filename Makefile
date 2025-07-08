# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/25 17:49:40 by fmoulin           #+#    #+#              #
#    Updated: 2025/07/08 18:28:21 by fmoulin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PUSH_SWAP = push_swap
NAME_CHECKER = checker

# Common source files
SRCS = src/errors.c src/free.c src/init_b_to_a.c src/push.c src/reverse_rotate.c \
	   src/rotate.c src/sort_stacks.c src/sort_three.c src/stack_init.c src/swap.c \
	   src/utils.c src/index.c

# Mains
PUSH_SWAP_MAIN = src/main_push_swap.c
CHECKER_MAIN = src/main_checker.c

# Object files
PUSH_SWAP_OBJS = obj_push_swap/main_push_swap.o \
				 obj_push_swap/errors.o obj_push_swap/free.o obj_push_swap/init_b_to_a.o \
				 obj_push_swap/push.o obj_push_swap/reverse_rotate.o obj_push_swap/rotate.o \
				 obj_push_swap/sort_stacks.o obj_push_swap/sort_three.o obj_push_swap/stack_init.o \
				 obj_push_swap/swap.o obj_push_swap/utils.o obj_push_swap/index.o

CHECKER_OBJS = obj_checker/main_checker.o \
			   obj_checker/errors.o obj_checker/free.o obj_checker/init_b_to_a.o \
			   obj_checker/push.o obj_checker/reverse_rotate.o obj_checker/rotate.o \
			   obj_checker/sort_stacks.o obj_checker/sort_three.o obj_checker/stack_init.o \
			   obj_checker/swap.o obj_checker/utils.o obj_checker/index.o

# Compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

# Libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Rules
all: $(LIBFT) $(NAME_PUSH_SWAP) $(NAME_CHECKER)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Binaries
$(NAME_PUSH_SWAP): $(PUSH_SWAP_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

$(NAME_CHECKER): $(CHECKER_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

# Compile push_swap objects
obj_push_swap/%.o: src/%.c
	@mkdir -p obj_push_swap
	$(CC) $(CFLAGS) -c $< -o $@

# Compile checker objects
obj_checker/%.o: src/%.c
	@mkdir -p obj_checker
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r obj_push_swap obj_checker
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME_PUSH_SWAP) $(NAME_CHECKER)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
