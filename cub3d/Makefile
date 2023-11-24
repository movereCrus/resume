NAME= cub3d

AR= ar rc
RM= rm -rf

CC= clang
CFLAGS= -Wall -Werror -Wextra -Ilibft -g3 -c 
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MFLAGS:=  -Lmlx-linux  -L/usr/lib -Imlx-linux -lmlx -lXext -lX11 -lm -lz
	MLX:= mlx-linux
else
	MFLAGS:=  -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -framework OpenGL -framework AppKit
	MLX:= mlx
endif
INC=	config.h

ODIR= obj

SRCS= init.c main.c parse.c parse_graphics.c parse_map.c to_rgb.c utils.c utils2.c valid_edges.c \
	valid_inners.c valid_map.c parse_state.c game_handle.c draw.c draw2.c raycast.c raycast2.c \
	key_handler.c

OBJS= $(SRCS:.c=.o)

SFIX= $(addprefix $(SDIR)/, $(SRCS))
OFIX= $(addprefix $(ODIR)/, $(OBJS)) 

$(ODIR)/%.o: %.c $(INC)
	$(CC) $(CFLAGS)  -I/usr/include -I$(MLX) $< -o $@

$(NAME): $(ODIR) $(OFIX)
	$(MAKE) -C ./libft
	$(MAKE) -C ./$(MLX)
	$(CC) $(OFIX) $(MFLAGS) -lft -L./libft -o $(NAME)

all:	$(NAME)

$(ODIR):
		mkdir -p $(ODIR)

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./$(MLX)
	$(RM) $(ODIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C ./libft
	$(MAKE) clean -C ./$(MLX)
	
re:	clean all

.PHONY: all clean flcean re
