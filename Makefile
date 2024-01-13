CC=cc
CFLAGS=-Wall -Wextra -Werror 
HEADER=./common/push_swap.h
HEADER_BONUS=./bonus/get_next_line.h
NAME=push_swap
NAME_BONUS=checker
SRCS= ./pushswap/init_utils.c ./pushswap/main.c ./pushswap/sorts.c ./pushswap/sorts2.c \
	./common/checks.c ./common/ft_split.c ./common/funcs.c ./common/funcs2.c ./common/funcs3.c ./common/utils.c ./common/utils2.c ./common/utils3.c
SRCS_BONUS= ./bonus/get_next_line.c ./bonus/main.c ./common/funcs.c ./common/funcs2.c ./common/funcs3.c ./common/utils.c ./common/ft_split.c ./common/checks.c \
			./bonus/get_next_line_utils.c ./common/utils2.c ./common/utils3.c

OBJS= $(SRCS:.c=.o)
OBJS_BONUS= $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

./pushswap/%.o: ./pushswap/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ -O3

./common/%.o: ./common/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ -O3

./bonus/%.o: bonus/%.c $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@ -O3

bonus: $(NAME_BONUS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: clean fclean all re bonus