NAME = push_swap
NAME_BONUS = checker
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
	manage_stack.c				\
	store_input_string.c		\

SRCS_BONUS = bonus/checker_main.c		\
		bonus/operations_both_bonus.c	\
		instructions_push.c				\
		instructions_swap.c				\
		instructions_rotate.c			\
		instructions_reverserot.c		\
		store_input.c					\
		ft_atoi_adapted.c				\
		manage_stack.c					\
		list_utils.c					\
		algo_utils.c					\
		algo_utils_2.c					\


OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

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
	@rm -f $(OBJS) $(OBJS_BONUS)
	@cd $(LIBFTPATH) && make clean

fclean: clean
	@rm -f $(NAME) ${NAME_BONUS}
	@cd $(LIBFTPATH) && make fclean

re: fclean all

bonus: $(NAME_BONUS)

$(NAME_BONUS) : makelibft $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) -L./libft -lft -o $(NAME_BONUS)

.PHONY: all clean fclean re libft

