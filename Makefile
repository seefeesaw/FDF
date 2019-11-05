# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashongwe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/03 16:52:06 by ashongwe          #+#    #+#              #
#    Updated: 2019/09/15 11:28:41 by ashongwe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c \
	  map_data_info.c \
	  set_constant_values.c \
	  draw.c

OBJPATH = obj/
OBJ = $(addprefix $(OBJPATH),$(SRC:.c=.o))

CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = libmlx.a -framework OpenGL -framework AppKit

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PURPLE = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m
UNDERLINE = \033[0;4m
TEXT_RESET = \033[0;0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(TEXT_RESET)"
	@echo "libft:"
	@echo "$(BLUE)"
	@make -C libft
	@echo "$(TEXT_RESET)"
	@echo "Generating executable file:\n$(WHITE)$@\n$(TEXT_RESET)"
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME) libft/libft.a $(MLXFLAGS)
	@echo "$(GREEN)Success$(TEXT_RESET)"

$(OBJPATH)%.o: %.c
	@test -d $(OBJPATH) || mkdir $(OBJPATH)
	@echo "$(CYAN)Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C libft
	@rm -rf $(OBJPATH)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
