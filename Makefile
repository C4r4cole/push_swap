# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/25 17:49:40 by fmoulin           #+#    #+#              #
#    Updated: 2025/07/03 13:19:52 by fmoulin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom du programme
NAME = push_swap

# Liste des .c
SRCS = 	src/errors.c src/free.c src/init_a_to_b.c src/init_b_to_a.c src/main.c src/push.c \
		src/reverse_rotate.c src/rotate.c src/sort_stacks.c src/sort_three.c src/stack_init.c \
		src/swap.c src/utils.c

# Liste des .o correspondants
OBJS = 	obj/errors.o obj/free.o obj/init_a_to_b.o obj/init_b_to_a.o obj/main.o obj/push.o \
		obj/reverse_rotate.o obj/rotate.o obj/sort_stacks.o obj/sort_three.o obj/stack_init.o \
		obj/swap.o obj/utils.o

# Compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

# Compilation des .o dans obj/
obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

# Inclusion de la libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Compilation principale
all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

clean:
	$(RM) -rf obj
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
