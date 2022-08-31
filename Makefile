NAME	= so_long

MLX		= ./minilibx
CFLAGS	= -Wall -Werror -Wextra 
RM		= rm -f
LIBFT	= ./libft/libft.a
SRCS	= ./GNL/get_next_line.c ./GNL/get_next_line_utils.c \
		  ./src/main.c ./src/check.c ./src/map.c  ./src/utils_1.c ./src/utils_2.c \
		  ./src/game.c ./src/sprites.c ./src/animation.c ./src/score.c ./src/entity_list.c \
		  ./src/entity.c ./src/load_dir.c ./src/pacman.c ./src/render.c \
		   ./src/legal.c ./src/animation_dir.c ./src/utils_game.c \

OBJS	= $(SRCS:.c=.o)

OFLAGS	= $(CFLAGS) -L ./minilibx -lmlx -framework OpenGL -framework AppKit

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

