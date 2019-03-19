# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/03/12 12:18:57 by angauber     #+#   ##    ##    #+#        #
#    Updated: 2019/03/19 18:12:34 by angauber    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = FdF

SRC =	src/parser.c \
		src/render.c \
		src/xiaolin_wu.c \
		src/xiaolin_wu_2.c \
		src/hsv_to_rgb.c \
		src/rotation_matrix.c \
		src/matrix_maths.c \
		src/key_map.c \
		src/projection.c

LIB =	minilibx_macos/libmlx.a \
		ft_printf/libftprintf.a

OBJ =	$(patsubst src/%.c,./%.o,$(SRC))

INCLUDE	=	include/fdf.h \

$(NAME): $(OBJ)
	gcc -g -Wall -Werror -Wextra -framework OpenGL -framework AppKit $(LIB) $(OBJ) -o $(NAME)

./%.o: src/%.c
	gcc -g -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

all: $(NAME)

.PHONY: clean fclean re all
