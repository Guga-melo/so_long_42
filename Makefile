NAME	= so_long


OFLAGS	= -Wall -Werror -Wextra -L ./minilibx -lmlx -framework OpenGL -framework AppKit
CFLAGS	= -Wall -Werror -Wextra 
RM		= rm -f
LIBFT	= ./libft/libft.a

SRCS	= ./GNL/get_next_line.c ./GNL/get_next_line_utils.c \
		  ./src/check.c ./src/map.c ./src/main.c ./src/utils_1.c ./src/utils_2.c \
		  ./src/game.c ./src/sprites.c ./src/animation.c ./src/score.c

OBJS	= $(SRCS:.c=.o)

$(NAME):	$(OBJS)
			make -C ./libft
			make -C ./minilibx

			cc $(OFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

all:		$(NAME)

clean:
			make clean -C ./libft
			make clean -C ./minilibx
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C ./libft
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re

