.PHONY: all tests_run clean fclean re

NAME = get_next_line.a

CC = clang

CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=xx

SRC = ./get_next_line.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

tests_run: $(NAME) main.c
	@$(CC) $(CFLAGS) -fsanitize=address main.c $(NAME) -o test.out
	@./test.out
	@make fclean
	@rm test.out

clean:
	@rm -rf *.o

fclean:
	@rm -rf *.o $(NAME) .tests.out

re:
	make fclean && make all
