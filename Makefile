# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduchi <vduchi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/22 22:11:19 by vduchi            #+#    #+#              #
#    Updated: 2022/11/16 12:26:33 by vduchi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
DEL_LINE	=	\033[2K
ITALIC		=	\033[3m
BOLD		=	\033[1m
DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m
BLACK		=	\033[0;99m
ORANGE		=	\033[38;5;209m
BROWN		=	\033[38;2;184;143;29m
DARK_GRAY	=	\033[38;5;234m
MID_GRAY	=	\033[38;5;245m
DARK_GREEN	=	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m

NAME 		=	fractol

SRCS_DIR	=	src
OBJ_DIR		=	obj
DEPS_DIR	=	dep
LIBS_DIR	=	libs
INC_DIR		=	include/ libft/ mlx/ ft_printf/include/ libs/

LIBFT		=	libft.a
MLX			=	libmlx.a
PRINTF		=	libftprintf.a

SRCS		=	src/main.c src/window.c src/mandelbrot.c src/zoom.c src/colour.c \
				src/julia.c src/atof_julia.c src/utils.c src/hooks.c src/burning_ship.c
OBJS		=	$(patsubst $(SRCS_DIR)/%, $(OBJ_DIR)/%, $(SRCS:.c=.o))
DEPS		=	$(patsubst $(SRCS_DIR)/%, $(DEPS_DIR)/%, $(SRCS:.c=.d))

CFLAGS		+= 	-Wall -Werror -Wextra -O3 $(addprefix -I , $(INC_DIR))
LDFLAGS		= 	-L libs -lft -lmlx -lftprintf -framework OpenGL -framework AppKit
DEPFLAGS	=	-MMD -MP -MF $(DEPS_DIR)/$*.d

RM			=	rm -rf
CC			=	gcc
MKDIR		=	mkdir -p

$(OBJ_DIR)/%.o :	$(SRCS_DIR)/%.c
	@echo "\n$(YELLOW)$(patsubst $(SRCS_DIR)/%,%, $<) \tcompiled!$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

all			:	$(LIBS_DIR) $(LIBFT) $(MLX) $(PRINTF) $(NAME)

$(NAME)		::
	@echo "$(ORANGE)\nCompiling fractol...$(DEF_COLOR)"

$(NAME)		::	$(OBJ_DIR) $(DEPS_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $@

$(NAME)		::
	@echo "$(GREEN)\nFractol executable ready!$(DEF_COLOR)"

$(LIBFT)	:
	@$(MAKE) -C libft
	@cp libft/$(LIBFT) $(LIBS_DIR)

$(MLX)		:
	@$(MAKE) -C mlx
	@cp mlx/$(MLX) $(LIBS_DIR)

$(PRINTF)	:
	@$(MAKE) -C ft_printf
	@cp ft_printf/$(PRINTF) $(LIBS_DIR)

$(OBJ_DIR)	:
	@$(MKDIR) $@

$(DEPS_DIR)	:
	@$(MKDIR) $@

$(LIBS_DIR)	:
	@$(MKDIR) $@

clean		:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(DEPS_DIR)

fclean		:	clean
	@$(RM) $(NAME) $(LIBS_DIR)
	@$(MAKE) -C libft fclean
	@$(MAKE) -C mlx clean
	@$(MAKE) -C ft_printf fclean
	@echo "\n$(BLUE)Fractol cleaned!$(DEF_COLOR)"

re			:	fclean all

-include $(DEPS)

.PHONY: all clean fclean re

#
#valgrind:
#	valgrind --leak-check=yes --show-leak-kinds=all "nombre del executable" "nombre de argumentos"
#	valgrind --leak-check=yes --track-origins=yes "nombre del executable" "nombre de argumentos"
#
#	gcc $(CFLAGS) -fsanitize=address -g -O3 -fno-omit-frame-pointer $(LDFLAGS) $(SRCS) -o $@