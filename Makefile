# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/25 17:49:40 by fmoulin           #+#    #+#              #
#    Updated: 2025/06/25 18:23:12 by fmoulin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom du programme
NAME = push_swap

# Liste des .c
SRCS = src/push_swap.c src/parser.c src/sort.c src/utils.c

# Liste des .o correspondants
OBJS = obj/push_swap.o obj/parser.o obj/sort.o obj/utils.o

# Compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror
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
