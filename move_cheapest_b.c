/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cheapest_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:36:28 by abillote          #+#    #+#             */
/*   Updated: 2024/06/05 14:28:17 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prepare_stacks(t_stack **stack_a, t_stack **stack_b, \
								t_stack *target, t_stack *cheapest)
{
	move_both(stack_a, stack_b, target, cheapest);
	move_target_to_top(stack_a, target);
	move_cheapest_to_top(stack_b, cheapest);
}

void	move_both(t_stack **stack_a, t_stack **stack_b, \
					t_stack *target, t_stack *cheapest)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize_stack(*stack_a);
	size_b = ft_lstsize_stack(*stack_b);
	while ((target->index > 0 && cheapest->index > 0) && \
				((target->index <= size_a / 2 && cheapest->index <= size_b / 2) \
				|| (target->index > size_a / 2 && \
					cheapest->index > size_b / 2)))
	{
		bring_both_to_top(stack_a, stack_b, target, cheapest);
		set_index(*stack_a);
		set_index(*stack_b);
	}
}

void	bring_both_to_top(t_stack **stack_a, t_stack **stack_b, \
							t_stack *target, t_stack *cheapest)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize_stack(*stack_a);
	size_b = ft_lstsize_stack(*stack_b);
	if (target->index <= size_a / 2 && cheapest->index <= size_b / 2)
		rotate_both(stack_a, stack_b);
	else if (target->index > size_a / 2 && cheapest->index > size_b / 2)
		reverse_rotate_both(stack_a, stack_b);
}

void	move_target_to_top(t_stack **stack_a, t_stack *target)
{
	int	size_a;

	size_a = ft_lstsize_stack(*stack_a);
	while (target->index > 0)
	{
		if (target->index <= size_a / 2)
			rotate_a(stack_a);
		else if (target->index > size_a / 2)
			reverse_rotate_a(stack_a);
		set_index(*stack_a);
	}
}

void	move_cheapest_to_top(t_stack **stack_b, t_stack *cheapest)
{
	int	size_b;

	size_b = ft_lstsize_stack(*stack_b);
	while (cheapest->index > 0)
	{
		if (cheapest->index <= size_b / 2)
			rotate_b(stack_b);
		else if (cheapest->index > size_b / 2)
			reverse_rotate_b(stack_b);
		set_index(*stack_b);
	}
}
