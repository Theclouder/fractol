# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduchi <vduchi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 17:51:59 by vduchi            #+#    #+#              #
#    Updated: 2022/11/16 15:57:56 by vduchi           ###   ########.fr        #
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

NOM		=	libmlx.a
SRC		=	mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m \
			mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1	=	$(SRC:.c=.o)
OBJ		=	$(OBJ1:.m=.o)

CC		=	gcc
CFLAGS	+=	-O2 -w

%.o		:	%.c
	@echo "$(YELLOW)$<    \tcompiled!$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

%.o		:	%.m
	@echo "$(YELLOW)$<  \tcompiled!$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@ 

all		:	$(NOM)

$(NOM)	::
	@echo "$(MAGENTA)\nChecking mlx...$(DEF_COLOR)" 

$(NOM)	::	$(OBJ)
	@echo "$(ORANGE)Creating mlx library...$(DEF_COLOR)"
	@ar -rcs $(NOM) $(OBJ)

$(NOM)	::
	@echo "$(GREEN)Mlx archive ready!$(DEF_COLOR)"

clean	:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app
	@echo "$(BLUE)\nMlx cleaned!$(DEF_COLOR)"

re		:	clean all
