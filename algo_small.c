/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:24:29 by abillote          #+#    #+#             */
/*   Updated: 2024/06/04 15:49:56 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize_stack(*stack_a) == 2)
		sort_two_numb(stack_a);
	if (ft_lstsize_stack(*stack_a) == 3)
		sort_three_numb(stack_a);
	if (ft_lstsize_stack(*stack_a) > 3)
		sort_five_numb(stack_a, stack_b);
}

void	sort_two_numb(t_stack **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		swap_a(stack_a);
}

void	sort_three_numb(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	if ((a > b && a < c) || \
	(b > a && b > c && a < c) \
	|| (a > b && b > c))
		swap_a(stack_a);
	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	if (ft_check_sorted(*stack_a) == 0 && a > b)
		rotate_a(stack_a);
	if (ft_check_sorted(*stack_a) == 0)
		reverse_rotate_a(stack_a);
}

void	sort_five_numb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;

	min = lst_min(*stack_a);
	move_min_to_top(stack_a, min);
	push_b(stack_b, stack_a);
	min = lst_min(*stack_a);
	move_min_to_top(stack_a, min);
	push_b(stack_b, stack_a);
	if (ft_lstsize_stack(*stack_a) == 2)
		sort_two_numb(stack_a);
	if (ft_lstsize_stack(*stack_a) == 3)
		sort_three_numb(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}
