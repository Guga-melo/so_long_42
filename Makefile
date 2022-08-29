NAME	= so_long

CFLAGS	= -Wall -Werror -Wextra 
RM		= rm -f
LIBFT	= ./libft/libft.a
SRCS	= ./GNL/get_next_line.c ./GNL/get_next_line_utils.c \
		  ./src/main.c ./src/check.c ./src/map.c  ./src/utils_1.c ./src/utils_2.c \
		  ./src/game.c ./src/sprites.c ./src/animation.c ./src/score.c ./src/entity_list.c \
		  ./src/entity.c ./src/load_dir.c ./src/pacman.c ./src/render.c \
		  ./src/utils_math.c ./src/legal.c ./src/animation_dir.c ./src/utils_game.c \

OBJS	= $(SRCS:.c=.o)

OS		= $(shell uname)

ifeq ($(OS), Linux)
	OFLAGS	= $(CFLAGS) -L ./minilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
	MLX		= ./minilibx-linux
else
	OFLAGS	= $(CFLAGS) -L ./minilibx -lmlx -framework OpenGL -framework AppKit
	MLX		= ./minilibx
endif

$(NAME):	$(OBJS)
			make -C ./libft && make -C $(MLX)

			cc $(OBJS) $(OFLAGS) $(LIBFT) -o $(NAME)

all:		$(NAME)

clean:
			make clean -C ./libft && make clean -C $(MLX)
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C ./libft
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re

