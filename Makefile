NAME = push_swap
LIBFTNAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFTPATH = ./libft

SRCS = main.c					\
	ft_atoi_adapted.c			\
	store_input.c				\
	instructions_push.c			\
	instructions_swap.c			\
	instructions_rotate.c		\
	instructions_reverserot.c	\
	algo_small.c				\
	algo_utils.c				\
	algo_utils_2.c				\
	list_utils.c				\
	algo_big.c					\
	move_cheapest_b.c			\


OBJS = $(SRCS:.c=.o)

all: $(NAME)

makelibft:
	@make bonus -C $(LIBFTPATH)
	@cp $(LIBFTPATH)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft $(OBJS)
	$(CC) $(OBJS) -L./libft -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -f $(OBJS)
	@cd $(LIBFTPATH) && make clean

fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTPATH) && make fclean

re: fclean all

.PHONY: all clean fclean re libft

