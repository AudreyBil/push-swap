/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:00:46 by abillote          #+#    #+#             */
/*   Updated: 2024/06/05 14:41:15 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	sort_a(stack_a, stack_b);
	set_index(*stack_a);
	set_index(*stack_b);
	sort_all(stack_a, stack_b);
}

void	sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int		avg;

	avg = 0;
	while (ft_lstsize_stack(*stack_a) > 3)
	{
		avg = calculate_average(*stack_a);
		if ((*stack_a)->content >= avg)
			push_b(stack_b, stack_a);
		else
			rotate_a(stack_a);
	}
	sort_three_numb(stack_a);
}

void	sort_all(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*target;
	t_stack	*cheapest;

	target = NULL;
	cheapest = NULL;
	while (*stack_b)
	{
		calculate_cheapest_move(*stack_a, *stack_b, &target, &cheapest);
		prepare_stacks(stack_a, stack_b, target, cheapest);
		push_a(stack_a, stack_b);
		set_index(*stack_a);
		set_index(*stack_b);
	}
	move_min_to_top(stack_a, lst_min(*stack_a));
}

void	calculate_cheapest_move(t_stack *stack_a, t_stack *stack_b, \
									t_stack **target, t_stack **cheapest)
{
	t_stack	*cheapest_tmp;
	t_stack	*target_tmp;
	int		cost;
	int		cost_tmp;

	cost = INT_MAX;
	cost_tmp = 0;
	cheapest_tmp = stack_b;
	*cheapest = stack_b;
	while (cheapest_tmp)
	{
		target_tmp = find_target(stack_a, cheapest_tmp->content);
		cost_tmp = calculate_cost(stack_a, target_tmp) \
								+ calculate_cost(stack_b, cheapest_tmp);
		if (cost_tmp < cost)
		{
			*cheapest = cheapest_tmp;
			*target = target_tmp;
			cost = cost_tmp;
		}
		cheapest_tmp = cheapest_tmp->next;
	}
}
