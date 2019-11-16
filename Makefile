NAME = stanaka.filler

SRC = algo.c main.c map.c piece.c read_info.c

FLAG = -Wall -Wextra -Werror

HEAD = -I filler.h

FA = -fsanitize=address

$(NAME): $(SRC)
	make -C libft
	gcc $(FLAG) $(HEAD) $(FA) $(SRC) -Llibft -lft -o $(NAME)

clean:
	make -C libft/ clean

fclean:
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all fclean re