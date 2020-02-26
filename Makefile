SRC = $(wildcard srcs/*.c)
LIBFT = $(wildcard libft/*.c)
LIBFT_A = libft/libft.a
FLAGS = -Werror -Wextra -Wall
LIBMLX = -lmlx -framework OpenGL -framework AppKit
OBJ = $(SRC:%.c=%.o)
LIBFT_OBJ = $(LIBFT:%.c=%.o)
NAME = cub.out

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A)
	gcc -o $(NAME) -g -O3 $(LIBMLX) -L./libft -lft $(OBJ)

$(LIBFT_A):
	cd libft/ && make

bonus: $(NAME)

%.o: %.c
	gcc -c $(FLAGS) $^ -o $@

clean:
	rm -f $(OBJ) $(LIBFT_OBJ)

fclean: clean
	rm -f $(NAME) $(LIBFT_A)

re: fclean
	make

.PHONY: all clean fclean re bonus
