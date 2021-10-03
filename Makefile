.PHONY: all tests_run clean fclean re

NAME = get_next_line.a

CC = clang

CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=4

SRC = ./get_next_line.c \
	./get_next_line_utils.c

SRC_B = ./get_next_line_bonus.c \
	./get_next_line_utils_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_B = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

tests_run: $(NAME) main.c
	@$(CC) $(CFLAGS) -fsanitize=address main.c $(NAME) -o test.out
	@./test.out
	@make fclean
	@rm test.out

val: $(NAME) main.c
	@$(CC) $(CFLAGS) main.c $(NAME) -o test.out
	@valgrind --leak-check=full --show-leak-kinds=all -s ./test.out
	@make clean

debug: $(NAME) main.c
	@$(CC) $(CFLAGS) -g main.c $(NAME)
	@make clean

bonus: $(OBJ_B)
	@ar rcs get_next_line_bonus.a $(OBJ_B)
	@$(CC) $(CFLAGS) -fsanitize=address main_b.c get_next_line_bonus.a  -o test_b.out
	@./test_b.out

clean:
	@rm -rf *.o

fclean:
	@rm -rf *.o $(NAME) *.out

re:
	@make fclean && make all
#