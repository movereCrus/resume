# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/06 15:00:51 by dwarlock          #+#    #+#              #
#    Updated: 2022/03/06 15:00:53 by dwarlock         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECK_NAME		=	checker

PUSH_NAME		=	push_swap

FLAGS			=	-Wall -Wextra -Werror

INC				=	-Iincludes/ -I$(LIB_DIR)/includes

CHECK_SRC_NAME	=	checker.c stack_formation.c operations_a.c operations_b.c \
					utility.c \

CHECK_OBJ_NAME	=	$(CHECK_SRC_NAME:.c=.o)

CHECK_OBJ		=	$(addprefix $(OBJ_DIR),$(CHECK_OBJ_NAME))

PUSH_SRC_NAME	=	push_swap.c stack_formation.c quicksort.c operations_a.c\
					operations_b.c utility.c score_evaluation.c sort_utilities.c \
					moves.c make_moves.c stdout.c stdout_proc.c \

PUSH_OBJ_NAME	=	$(PUSH_SRC_NAME:.c=.o)

PUSH_OBJ		=	$(addprefix $(OBJ_DIR),$(PUSH_OBJ_NAME))

LIB_DIR			=	libft/
SRC_DIR			=	srcs/
OBJ_DIR			=	objs/

all: $(PUSH_NAME) $(CHECK_NAME)

bonus: $(CHECK_NAME)

$(CHECK_NAME): $(CHECK_OBJ)
	@make -C $(LIB_DIR) --silent
	@gcc -o $(CHECK_NAME) $(CHECK_OBJ) -L $(LIB_DIR) -lft
	@echo "\033[32m##### Checker has been compiled #####"

$(PUSH_NAME): $(PUSH_OBJ)
	@make -C $(LIB_DIR) --silent
	@gcc -o $(PUSH_NAME) $(PUSH_OBJ) -L $(LIB_DIR) -lft
	@echo "\033[32m##### Push_Swap has been compiled #####"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "\033[36m##### Creating" [ $@ ] " #####"
	@gcc $(FLAGS) -o $@ -c $< $(INC)

clean:
	@make -C $(LIB_DIR) clean  --silent
	@rm -f $(CHECK_OBJ) $(PUSH_OBJ)
	@echo "\033[33m##### Removed object files #####"

fclean: clean
	@make -C $(LIB_DIR) fclean  --silent
	@rm -f $(CHECK_NAME) $(PUSH_NAME)
	@echo "\033[33m##### Removed binary files #####"

re: fclean all

.PHONY: all bonus clean fclean re
