NAME		= fdf

FLAGS		= -Wall -Wextra -Werror

INC			= -I$(HD_DIR) -I$(LIB_HD_DIR) -I$(MLX_DIR)

SRC			= fdf.c readfile.c drawmap.c utilities.c

OBJ_NAME	= $(SRC:.c=.o)

OBJ			= $(addprefix $(OBJ_DIR), $(OBJ_NAME))

HDS			= fdf.h
HD_DIR		= ./includes/
HD			= $(addprefix $(HD_DIR), $(HDS))

LIB_DIR		= ./libft/
LIB_HD_DIR	= $(LIB_DIR)includes/

SRC_DIR		= srcs/
OBJ_DIR		= objs/
UNAME_S		:= $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MFLAGS:=  -Lmlx-linux -L$(LIB_DIR) -L/usr/lib -lmlx -lXext -lX11 -lm -lz -lft
	MLX_DIR:= mlx-linux
else
	MFLAGS:=  -Lmlx -lmlx -framework OpenGL -framework AppKit -L$(LIB_DIR) -lft
	MLX_DIR:= mlx
endif

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HD)
	@mkdir -p $(OBJ_DIR)
	@echo "\033[36m##### Creating" [ $@ ] " #####"
	gcc $(FLAGS) $(INC) -o $@ -c $<

$(NAME): $(OBJ)
	@make -C $(LIB_DIR) --silent
	gcc -o $(NAME) $(OBJ) $(INC) $(MFLAGS)
	@echo "\033[32m##### FDF has been compiled #####"

clean:
	@make -C $(LIB_DIR) clean  --silent
	@rm -f $(OBJ)
	@rm -r $(OBJ_DIR)
	@echo "\033[33m##### Removed object files #####"

fclean: clean
	@make -C $(LIB_DIR) fclean  --silent
	@rm -f $(NAME)
	@echo "\033[33m##### Removed binary and object files #####"

re: fclean all

.PHONY: all clean fclean re
