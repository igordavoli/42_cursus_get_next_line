.PHONY: all tests_run clean fclean re

NAME = get_next_line.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=500

SRC = ./get_next_line.c \
	./get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

tests_run: $(NAME) main.c
	@$(CC) $(CFLAGS) -fsanitize=address main.c $(NAME) -o test.out
	@./test.out
	@make fclean
	@rm test.out
test: $(NAME) main.c
	@$(CC) $(CFLAGS) main.c $(NAME) -o test.out
	@./test.out
	@make clean

clean:
	@rm -rf *.o

fclean:
	@rm -rf *.o $(NAME) *.out

re:
	@make fclean && make all
