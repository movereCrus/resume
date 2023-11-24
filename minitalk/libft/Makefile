NAME		=	libft.a

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -I./includes

SRCS 		=	ft_abs.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
				ft_isascii.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c \
				ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
				ft_strdup.c ft_strequ.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
				ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
				ft_strrchr.c ft_strtrim.c ft_substr.c ft_strchr.c \
				ft_isalpha.c ft_isdigit.c ft_swap.c ft_toupper.c ft_tolower.c \
				get_next_line.c get_next_line_utils.c ft_printf.c \
				ft_printf_utils.c ft_printf_putnbrs.c \

BONUS_SRCS	=	ft_lstadd_back_bonus.c ft_lstclear_bonus.c ft_lstsize_bonus.c \
				ft_lstadd_front_bonus.c ft_lstdelone_bonus.c \
				ft_lstlast_bonus.c ft_lstmap_bonus.c \
				ft_lstiter_bonus.c ft_lstnew_bonus.c \

HEADER		=	includes/libft.h

OBJS		=	$(addprefix $(OBJ_DIR),$(patsubst %.c,%.o,$(SRCS)))

BONUS_OBJS	=	$(addprefix $(OBJ_DIR),$(patsubst %.c,%.o,$(BONUS_SRCS)))

SRC_DIR		=	srcs/

OBJ_DIR		=	objs/

all: $(NAME)

$(NAME): $(OBJS) $(if $(findstring bonus, $(MAKECMDGOALS)), $(BONUS_OBJS))
	ar rcs $(NAME) $?

bonus: $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
