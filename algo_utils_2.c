/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:31:37 by abillote          #+#    #+#             */
/*   Updated: 2024/06/05 14:25:10 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		stack->index = count;
		stack = stack->next;
		count++;
	}
}

t_stack	*find_target(t_stack *stack_a, int nb)
{
	t_stack	*target;
	t_stack	*tmp;

	target = NULL;
	tmp = stack_a;
	while (tmp)
	{
		if (tmp->content > nb && (!target || tmp->content < target->content))
			target = tmp;
		tmp = tmp->next;
	}
	if (!target)
		target = lst_min(stack_a);
	return (target);
}

int	calculate_cost(t_stack *stack, t_stack *node)
{
	int	cost;
	int	size;

	cost = 0;
	size = ft_lstsize_stack(stack);
	if (node->index <= size / 2)
	{
		cost = node->index;
	}
	else
	{
		cost = size - node->index;
	}
	return (cost);
}
