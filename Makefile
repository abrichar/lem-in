#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/06 14:49:07 by abrichar          #+#    #+#              #
#    Updated: 2018/02/06 15:07:59 by abrichar         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME = lem-in

SRC_DIR = src/
SRC = 	lem_in.c ft_process_read.c ft_process_phase_1.c ft_check_phase_2.c \
		ft_process_phase_2.c ft_find_path.c ft_check_end.c ft_sup_path.c \
		ft_remove_non_end_path.c ft_set_len_path.c ft_set_ant_path.c \
		ft_print_ant.c ft_isint.c ft_freetab.c ft_freedim2.c

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

INC = -Iincludes -Ilibft/includes

LIB_DIR = libft/
LIB = $(addprefix $(LIB_DIR), libft.a)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(LIB) $(OBJ_DIR) $(OBJ)
	@$(CC) $(CFLAGS) $(LIB) $(OBJ) -o $(NAME)

$(LIB):
	@make -C libft

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@make -C libft clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
