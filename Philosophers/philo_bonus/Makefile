# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 16:50:58 by dwarlock          #+#    #+#              #
#    Updated: 2022/06/28 17:09:22 by dwarlock         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

OBJECTSDIR = objects
HEADERFILE = philosophers.h

FLAGS = -Wall -Wextra -Werror
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RESET = \033[0m

SRC_FILES = ft_parsing.c philosophers.c ft_actions.c ft_init.c

OBJS := $(addprefix $(OBJECTSDIR)/, $(SRC_FILES:.c=.o))

CC = gcc -pthread -lrt

RM = rm -rf
MKDIR = mkdir -p
MAKE = make -C

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) -I $(HEADERFILE) $(OBJS) -o $@

$(OBJECTSDIR)/%.o: %.c $(HEADERFILE)
	@$(MKDIR) $(dir $@)
	@echo "$(BLUE)█ $(YELLOW)Compiling$(RESET) $<:\r\t\t\t\t$(GREEN){DONE}$(BLUE) █$(RESET)"
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	@echo "$(RED)deleting$(RESET): " $(OBJECTSDIR)
	@$(RM) $(OBJECTSDIR)


fclean: clean
	@echo "$(RED)deleting$(RESET): " $(NAME)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
