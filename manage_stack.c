/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:40:31 by abillote          #+#    #+#             */
/*   Updated: 2024/10/03 14:47:29 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//used to check for errors
void	print_stack(t_stack *stack_a)
{
	t_stack	*current;

	current = stack_a;
	while (current)
	{
		ft_printf("%d\n", current->content);
		current = current->next;
	}
}

void	free_stack(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (stack)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
	free(stack);
}

void	error_input(void)
{
	write(2, "Error\n", 6);
	exit (EXIT_FAILURE);
}
