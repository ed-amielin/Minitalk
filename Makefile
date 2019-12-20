#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/16 22:21:07 by eamielin          #+#    #+#              #
#    Updated: 2019/03/16 22:21:08 by eamielin         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME1 = server
NAME2 = client

SRC_DIR		= ./src/
OBJ_DIR		= ./obj/
LIB_DIR		= ./lib/
SRC_INC_DIR	= $(SRC_DIR)
HEAD_FILE	= $(SRC_INC_DIR)minitalk.h

C_SERVER_FILES		= server.c
C_CLIENT_FILES		= client.c

O_SERVER_FILES		= $(addprefix $(OBJ_DIR), $(C_SERVER_FILES:.c=.o))
O_CLIENT_FILES		= $(addprefix $(OBJ_DIR), $(C_CLIENT_FILES:.c=.o))

LIBFT_DIR	= $(LIB_DIR)libft/
LIBFT_INC_DIR	= $(LIBFT_DIR)
LIBFT		= $(LIBFT_DIR)libft.a
LIBFT_FLAGS	= -lft -L $(LIBFT_DIR)

FLAGS		= -Wall -Werror -Wextra
HEADER_FLAGS	= -I $(SRC_INC_DIR) -I $(LIBFT_INC_DIR)

LINK_FLAGS	= $(LIBFT_FLAGS)


all: $(NAME1) $(NAME2)

$(NAME1): $(LIBFT) $(O_SERVER_FILES)
		gcc $(O_SERVER_FILES) $(LINK_FLAGS) -o $(NAME1)

$(NAME2): $(LIBFT) $(O_CLIENT_FILES)
		gcc $(O_CLIENT_FILES) $(LINK_FLAGS) -o $(NAME2)

$(O_SERVER_FILES): | $(OBJ_DIR)
$(O_CLIENT_FILES): | $(OBJ_DIR)

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEAD_FILE)
		gcc -c $< -o $@ $(FLAGS) $(HEADER_FLAGS)

$(LIBFT):
		make -C $(LIBFT_DIR)

clean:
	rm -f $(O_SERVER_FILES)
	rm -f $(O_CLIENT_FILES)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME1)
	rm -f $(NAME2)
	rm -Rf $(OBJ_DIR)
	make fclean -C $(LIBFT_DIR)

re: fclean all
