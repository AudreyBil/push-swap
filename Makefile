NAME = push_swap
NAME_BONUS = checker
LIBFTNAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFTPATH = ./libft

SRCS = sources/main.c					\
	sources/ft_atoi_adapted.c			\
	sources/store_input.c				\
	sources/instructions_push.c			\
	sources/instructions_swap.c			\
	sources/instructions_rotate.c		\
	sources/instructions_reverserot.c	\
	sources/algo_small.c				\
	sources/algo_utils.c				\
	sources/algo_utils_2.c				\
	sources/list_utils.c				\
	sources/algo_big.c					\
	sources/move_cheapest_b.c			\
	sources/manage_stack.c				\
	sources/store_input_string.c		\

SRCS_BONUS = bonus/checker_main.c		\
		bonus/operations_both_bonus.c	\
		sources/instructions_push.c				\
		sources/instructions_swap.c				\
		sources/instructions_rotate.c			\
		sources/instructions_reverserot.c		\
		sources/store_input.c					\
		sources/ft_atoi_adapted.c				\
		sources/manage_stack.c					\
		sources/list_utils.c					\
		sources/algo_utils.c					\
		sources/algo_utils_2.c					\


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

