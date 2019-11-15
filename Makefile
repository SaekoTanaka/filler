NAME = stanaka.filler

SRC = algo.c main.c map.c piece.c read_info.c

FLAG = -Wall -Wextra -Werror

HEAD = -I filler.h

$(NAME): $(SRC)
	make -C libft
	gcc $(FLAG) $(HEAD) $(SRC) -Llibft -lft -o $(NAME)

clean:
	make -C libft/ clean

fclean:
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all fclean re