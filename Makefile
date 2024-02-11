NAME = so_long

SRC = so_long.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		map_parsing.c \
		map_parsing2.c \
		draw.c \
		utils/ft_memset.c \
		utils/ft_strclen.c \
		utils/ft_putstr.c \
		map_filling.c \
		draw_elements.c \
		flood_exit.c \
		flood_colec.c \
		play.c \
		play_utils.c \

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all