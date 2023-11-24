NAME	= libftprintf.a

HEADER	= ft_printf.h

SRC		= ft_printf.c ft_printf_utils.c ft_printf_putnbrs.c

OBJ		= ${patsubst %.c,%.o,${SRC}}

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

all:		${NAME}

${NAME}:	${OBJ} ${HEADER}
			ar rcs ${NAME} $?

%.o : %.c	${HEADER}
			${CC} ${CFLAGS} -c $< -o $@

clean:
			${RM} ${OBJ}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
