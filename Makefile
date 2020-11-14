# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/11 21:22:13 by aeclipso          #+#    #+#              #
#    Updated: 2020/11/11 21:57:30 by aeclipso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -O3

SRC_DIR = ./src
OBJ_DIR = ./obj

INCLUDES = -I libft/include -I include
LIBS = -L libft -lft -lmlx -framework OpenGL -framework AppKit

SRC = main
INC = include/fdf.h

SRC_C = $(patsubst %, %.c, $(SRC))

RED 	:= \033[31;1m
GREEN 	:= \033[32;1m
DBLUE 	:= \033[34m
WHITE	:= \033[39;1m
EOC		:= \033[00m

OBJS = $(addprefix $(OBJ_DIR)/, $(patsubst %, %.o, $(SRC)))

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_DIR):
	@mkdir -vp obj

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile $(INC)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<
	@printf "\n$(GREEN)compiled: $(WHITE) $< $(EOC)\n"

$(NAME): $(OBJ_DIR) $(OBJS)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@printf "\n$(GREEN)compiled: $(WHITE) $@ $(EOC)\n"

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C libft/
	@printf "\n$(RED)Deleted: $(WHITE) $(OBJ_DIR) $(EOC)\n"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft/
	@printf "\n$(RED)Deleted: $(WHITE) $(NAME) $(EOC)\n"

re: fclean all