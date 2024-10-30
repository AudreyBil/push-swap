/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:33:56 by abillote          #+#    #+#             */
/*   Updated: 2024/10/28 16:48:44 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}	t_stack;

//Error handling and free
void	error_input(void);
void	free_stack(t_stack *stack);
void	free_string(char **input);

//Utility functions
long	ft_atoi_adapted(const char *nptr);
char	**string_to_numbers(char *s);
int		ft_lstsize_stack(t_stack *lst);
void	ft_lstadd_back_stack(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew_stack(int content);
void	ft_lstadd_front_stack(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast_stack(t_stack *lst);
t_stack	*lst_max(t_stack *stack);
t_stack	*lst_min(t_stack *stack);

//Store input
void	ft_check_double(t_stack **stack_a, int value);
void	store_stack(t_stack **stack_a, char **substrg, int i);
void	create_stack_a(t_stack **stack_a, char **substrg, int i);
void	create_stack_a_string(t_stack **stack_a, \
			char **substrg, int i);
void	store_stack_string(t_stack **stack_a, char **substrg, int i);
void	ft_check_double_string(t_stack **stack_a, int value, char **substrg);

//Operations
void	swap(t_stack **stack);
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_both(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **stack_1, t_stack **stack_2);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_b, t_stack **stack_a);
void	rotate(t_stack **stack);
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_a);
void	rotate_both(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate(t_stack **stack);
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);

//Algorithm - small
int		ft_check_sorted(t_stack *stack);
void	sort_two_numb(t_stack **stack_a);
void	sort_three_numb(t_stack **stack_a);
void	sort_five_numb(t_stack **stack_a, t_stack **stack_b);
void	sort_small(t_stack **stack_a, t_stack **stack_b);
void	move_min_to_top(t_stack **stack_a, t_stack *min);

//Algorithm - big
void	sort_big(t_stack **stack_a, t_stack **stack_b);
void	sort_a(t_stack **stack_a, t_stack **stack_b);
int		calculate_average(t_stack *stack);
void	set_index(t_stack *stack);
void	calculate_cheapest_move(t_stack *stack_a, t_stack *stack_b, \
									t_stack **target, t_stack **cheapest);
t_stack	*find_target(t_stack *stack_a, int nb);
int		calculate_cost(t_stack *stack, t_stack *target);
void	sort_all(t_stack **stack_a, t_stack **stack_b);
void	prepare_stacks(t_stack **stack_a, t_stack **stack_b, \
						t_stack *target, t_stack *cheapest);
void	bring_both_to_top(t_stack **stack_a, t_stack **stack_b, \
							t_stack *target, t_stack *cheapest);
void	move_both(t_stack **stack_a, t_stack **stack_b, \
					t_stack *target, t_stack *cheapest);
void	move_target_to_top(t_stack **stack_a, t_stack *target);
void	move_cheapest_to_top(t_stack **stack_b, t_stack *cheapest);

#endif
