/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:48:59 by abillote          #+#    #+#             */
/*   Updated: 2024/10/09 13:29:49 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **stack)
{
	int	swap;

	if (!stack || !*stack)
		return ;
	swap = 0;
	swap = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = swap;
}

void	swap_a(t_stack **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	swap_b(t_stack **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	swap_both(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
