# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduchi <vduchi@student.42barcelon>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/22 22:11:19 by vduchi            #+#    #+#              #
#    Updated: 2022/06/07 16:41:45 by vduchi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = ./include/ft_printf.h
SRCS = 	./src/ft_printf.c ./src/ft_utils.c ./src/ft_funcs.c \
		./src/ft_utoa_itoa.c ./src/ft_hex.c

OBJS = $(SRCS:.c=.o)
#OBJS_LIB = ./libft/*.o

CFLAGS = -Wall -Wextra -Werror

%.o: %.c $(HEADER)
	cc $(CFLAGS) -c $< -o $@
#	@make -C libft
#	@mv libft/libft.a include

all:	$(NAME)

$(NAME): $(OBJS) $(HEADER)
	@ar -rcs $@ $^ 
	@echo "Library created!"
#	@make -C libft bonus

clean:
	@rm -f $(OBJS)
#	@rm -f $(OBJS:.o=.d)

fclean: clean
	@rm -f $(NAME)
	@echo "All files cleaned"
#	@make fclean -C libft

re: fclean all

#leaks:
#	leaks -atExit -- "nombre del executable" "nombre de argumentos"

.PHONY: all clean fclean re
