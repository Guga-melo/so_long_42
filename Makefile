NAME	= so_long


OFLAGS	= -Wall -Werror -Wextra -L ./minilibx -lmlx -framework OpenGL -framework AppKit
CFLAGS	= -Wall -Werror -Wextra 
RM		= rm -f

SRCS	= ./GNL/get_next_line.c ./GNL/get_next_line_utils.c \
		  ./src/window.c

OBJS	= $(SRCS:.c=.o)

$(NAME):	$(OBJS)
			make -C ./libft
			make -C ./minilibx
			cp ./libft/libft.a $(NAME)
			cc $(OFLAGS) $(OBJS) -o $(NAME)

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

