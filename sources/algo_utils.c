/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:28:08 by abillote          #+#    #+#             */
/*   Updated: 2024/10/09 13:29:28 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_check_sorted(t_stack *stack)
{
	int	nb;

	nb = stack->content;
	while (stack)
	{
		if (nb > stack->content)
			return (0);
		nb = stack->content;
		stack = stack->next;
	}
	return (1);
}

t_stack	*lst_min(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (stack->content < min->content)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_stack	*lst_max(t_stack *stack)
{
	t_stack	*max;

	max = stack;
	while (stack)
	{
		if (stack->content > max->content)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

void	move_min_to_top(t_stack **stack_a, t_stack *min)
{
	int		index;
	int		size;
	t_stack	*tmp;

	index = 0;
	size = ft_lstsize_stack(*stack_a);
	tmp = *stack_a;
	while (tmp && tmp->content != min->content)
	{
		index++;
		tmp = tmp->next;
	}
	if (index < size / 2)
	{
		while ((*stack_a)->content != min->content)
			rotate_a(stack_a);
	}
	else
	{
		while ((*stack_a)->content != min->content)
			reverse_rotate_a(stack_a);
	}
}

int	calculate_average(t_stack *stack)
{
	int	avg;
	int	sum;
	int	size;

	avg = 0;
	sum = 0;
	size = ft_lstsize_stack(stack);
	while (stack)
	{
		sum = sum + stack->content;
		stack = stack->next;
	}
	avg = sum / size;
	return (avg);
}
