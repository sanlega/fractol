# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 19:57:25 by slegaris          #+#    #+#              #
#    Updated: 2024/03/04 16:33:28 by slegaris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_DIR = src

SRCS = $(SRC_DIR)/main.c\
       $(SRC_DIR)/colors.c\
	   
OBJS = $(SRCS:.c=.o)

LIBFT = libft
LIBFT_LIB = $(LIBFT)/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Imlx
LDFLAGS = -fsanitize=address
MINILIBX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "	  ██████  ██▓    ▓█████   ▄████  ▄▄▄       ██▀███   ██▓  ██████ "
	@echo "	▒██    ▒ ▓██▒    ▓█   ▀  ██▒ ▀█▒▒████▄    ▓██ ▒ ██▒▓██▒▒██    ▒ "
	@echo "	░ ▓██▄   ▒██░    ▒███   ▒██░▄▄▄░▒██  ▀█▄  ▓██ ░▄█ ▒▒██▒░ ▓██▄   "
	@echo "	  ▒   ██▒▒██░    ▒▓█  ▄ ░▓█  ██▓░██▄▄▄▄██ ▒██▀▀█▄  ░██░  ▒   ██▒"
	@echo "	▒██████▒▒░██████▒░▒████▒░▒▓███▀▒ ▓█   ▓██▒░██▓ ▒██▒░██░▒██████▒▒"
	@echo "	▒ ▒▓▒ ▒ ░░ ▒░▓  ░░░ ▒░ ░ ░▒   ▒  ▒▒   ▓▒█░░ ▒▓ ░▒▓░░▓  ▒ ▒▓▒ ▒ ░"
	@echo "	░ ░▒  ░ ░░ ░ ▒  ░ ░ ░  ░  ░   ░   ▒   ▒▒ ░  ░▒ ░ ▒░ ▒ ░░ ░▒  ░ ░"
	@echo "	░  ░  ░    ░ ░      ░   ░ ░   ░   ░   ▒     ░░   ░  ▒ ░░  ░  ░  "
	@echo "		  ░      ░  ░   ░  ░      ░       ░  ░   ░      ░        ░  "
	@echo "			\033[0;36mCompilation of $(NAME) completed!\033[0m"

$(LIBFT_LIB):
	@ make -C $(LIBFT)

.c.o:
	@ $(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all

asan: CC += $(LDFLAGS)
asan: CFLAGS += -fsanitize=address
asan: CFLAGS += -g3
asan: re

.PHONY: all clean fclean re asan
