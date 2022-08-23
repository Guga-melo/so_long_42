NAME	= so_long

ESC = KEY_ESC=53
W = KEY_W=13
A = KEY_A=0
S = KEY_S=1
D = KEY_D=2
UP = KEY_UP=126
DOWN = KEY_DOWN=125
LEFT = KEY_LEFT=123
RIGHT = KEY_RIGHT=124
R = KEY_R=15
Q = KEY_Q=12
GRATE = GAME_RATE=17

KEYCODES =  -D $(ESC) -D $(Q) -D $(R) -D $(W) -D $(A) -D $(S) -D $(D) -D $(UP) -D $(DOWN) -D $(LEFT) -D $(RIGHT)
RATES = -D $(GRATE)
CFLAGS	= -Wall -Werror -Wextra 
RM		= rm -f
LIBFT	= ./libft/libft.a
SRCS	= ./GNL/get_next_line.c ./GNL/get_next_line_utils.c \
		  ./src/main.c ./src/check.c ./src/map.c  ./src/utils_1.c ./src/utils_2.c \
		  ./src/game.c ./src/sprites.c ./src/animation.c ./src/score.c ./src/entity_list.c \
		  ./src/entity.c ./src/ghosts.c ./src/load_dir.c ./src/pacman.c ./src/render.c \
		  ./src/utils_math.c ./src/legal.c ./src/animation_dir.c ./src/utils_game.c \
		  ./src/kill_pac.c

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

			cc $(OBJS) $(OFLAGS) $(LIBFT) $(KEYCODES) $(RATES) -o $(NAME)

all:		$(NAME)

clean:
			make clean -C ./libft && make clean -C $(MLX)
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C ./libft
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re

