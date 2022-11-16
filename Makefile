# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduchi <vduchi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/22 22:11:19 by vduchi            #+#    #+#              #
#    Updated: 2022/11/16 16:02:53 by vduchi           ###   ########.fr        #
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
INC_DIR		=	include/ libft/ mlx/ ft_printf/include/

LIBFT		=	libft
MLX			=	mlx
PRINTF		=	ft_printf
ALL_LIBS	=	libft/libft.a ft_printf/libftprintf.a mlx/libmlx.a

SRCS		=	src/main.c src/window.c src/mandelbrot.c src/zoom.c src/colour.c \
				src/julia.c src/atof_julia.c src/utils.c src/hooks.c src/burning_ship.c
OBJS		=	$(patsubst $(SRCS_DIR)/%, $(OBJ_DIR)/%, $(SRCS:.c=.o))
DEPS		=	$(patsubst $(SRCS_DIR)/%, $(DEPS_DIR)/%, $(SRCS:.c=.d))

CFLAGS		+= 	-Wall -Werror -Wextra -O3 $(addprefix -I , $(INC_DIR))
LDFLAGS		= 	-L libft -L ft_printf -L mlx -lft -lmlx -lftprintf -framework OpenGL -framework AppKit
DEPFLAGS	=	-MMD -MP -MF $(DEPS_DIR)/$*.d

RM			=	rm -rf
CC			=	gcc
MKDIR		=	mkdir -p

$(OBJ_DIR)/%.o :	$(SRCS_DIR)/%.c
	@echo "$(YELLOW)$(patsubst $(SRCS_DIR)/%,%, $<) \tcompiled!$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

all			:
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(PRINTF)
	@$(MAKE) -C $(MLX)
	@$(MAKE) $(NAME)

$(NAME)		::
	@echo "$(MAGENTA)\nChecking fractol...$(DEF_COLOR)"

$(NAME)		::	$(OBJ_DIR) $(DEPS_DIR) $(OBJS) $(ALL_LIBS)
	@echo "$(ORANGE)Compiling fractol exec...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $@

$(NAME)		::
	@echo "$(GREEN)Fractol executable ready!$(DEF_COLOR)"

$(OBJ_DIR)	:
	@$(MKDIR) $@

$(DEPS_DIR)	:
	@$(MKDIR) $@

clean		:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(DEPS_DIR)

fclean		:	clean
	@$(RM) $(NAME) $(LIBS_DIR)
	@$(MAKE) -C libft fclean
	@$(MAKE) -C mlx clean
	@$(MAKE) -C ft_printf fclean
	@echo "$(BLUE)\nFractol cleaned!$(DEF_COLOR)"

re			:	fclean all

-include $(DEPS)

.PHONY: all clean fclean re

#
#valgrind:
#	valgrind --leak-check=yes --show-leak-kinds=all "nombre del executable" "nombre de argumentos"
#	valgrind --leak-check=yes --track-origins=yes "nombre del executable" "nombre de argumentos"
#
#	gcc $(CFLAGS) -fsanitize=address -g -O3 -fno-omit-frame-pointer $(LDFLAGS) $(SRCS) -o $@