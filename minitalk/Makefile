# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 20:14:45 by dwarlock          #+#    #+#              #
#    Updated: 2022/03/08 20:14:46 by dwarlock         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME		=	server

CLIENT_NAME		=	client

FLAGS			=	-Wall -Wextra -Werror

INC				=	-Iincludes/ -I$(LIB_DIR)/includes

SERVER_SRC_NAME	=	server.c

SERVER_OBJ_NAME	=	$(SERVER_SRC_NAME:.c=.o)

SERVER_OBJ		=	$(addprefix $(OBJ_DIR),$(SERVER_OBJ_NAME))

CLIENT_SRC_NAME	=	client.c

CLIENT_OBJ_NAME	=	$(CLIENT_SRC_NAME:.c=.o)

CLIENT_OBJ		=	$(addprefix $(OBJ_DIR),$(CLIENT_OBJ_NAME))

LIB_DIR			=	libft/
SRC_DIR			=	srcs/
OBJ_DIR			=	objs/

all: $(SERVER_NAME) $(CLIENT_NAME)

bonus: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJ)
	@make -C $(LIB_DIR) --silent
	@gcc -o $(SERVER_NAME) $(SERVER_OBJ) -L $(LIB_DIR) -lft
	@echo "\033[32m##### Server has been compiled #####"

$(CLIENT_NAME): $(CLIENT_OBJ)
	@make -C $(LIB_DIR) --silent
	@gcc -o $(CLIENT_NAME) $(CLIENT_OBJ) -L $(LIB_DIR) -lft
	@echo "\033[32m##### Client has been compiled #####"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "\033[36m##### Creating" [ $@ ] " #####"
	@gcc $(FLAGS) -o $@ -c $< $(INC)

clean:
	@make -C $(LIB_DIR) clean  --silent
	@rm -f $(SERVER_OBJ) $(CLIENT_OBJ)
	@echo "\033[33m##### Removed object files #####"

fclean: clean
	@make -C $(LIB_DIR) fclean  --silent
	@rm -f $(SERVER_NAME) $(CLIENT_NAME)
	@echo "\033[33m##### Removed binary files #####"

re: fclean all

.PHONY: all clean fclean re
