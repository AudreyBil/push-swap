/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:49:34 by abillote          #+#    #+#             */
/*   Updated: 2024/10/09 13:29:37 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*tmp;

	if (!stack_2 || !*stack_2)
		return ;
	tmp = *stack_2;
	ft_lstadd_front_stack(stack_1, ft_lstnew_stack((*stack_2)->content));
	*stack_2 = tmp->next;
	free(tmp);
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	push_b(t_stack **stack_b, t_stack **stack_a)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
}
