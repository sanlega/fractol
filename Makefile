# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 19:57:25 by slegaris          #+#    #+#              #
#    Updated: 2024/03/06 20:07:39 by slegaris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_DIR = src

SRCS = $(SRC_DIR)/main.c\
       $(SRC_DIR)/colors.c\
       $(SRC_DIR)/defaults.c\
       $(SRC_DIR)/keys.c\
       $(SRC_DIR)/presets.c\
       $(SRC_DIR)/palette.c\
       $(SRC_DIR)/mlx.c\
       $(SRC_DIR)/hooks.c\
       $(SRC_DIR)/mandelbrot.c\
       $(SRC_DIR)/julia.c\
       $(SRC_DIR)/parse.c\
	   
OBJS = $(SRCS:.c=.o)

LIBFT = libft
LIBFT_LIB = $(LIBFT)/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Imlx
MINILIBX = -lmlx -framework OpenGL -framework AppKit

LDFLAGS = -fsanitize=address

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft $(MINILIBX) -o $(NAME)
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
asan: CFLAGS += -g3
asan: re

.PHONY: all clean fclean re asan
