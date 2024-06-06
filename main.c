/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:32:20 by abillote          #+#    #+#             */
/*   Updated: 2024/06/05 14:36:25 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//to check for mistakes
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
}

void	error_input(void)
{
	ft_printf("Error\n");
	exit (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
		return (0);
	if (argc > 2)
	{
		check_input_and_store_stack(&stack_a, argv, 1);
		if (ft_check_sorted(stack_a) == 0)
		{
			if (ft_lstsize_stack(stack_a) > 1 && ft_lstsize_stack(stack_a) < 6)
				sort_small(&stack_a, &stack_b);
			else
				sort_big(&stack_a, &stack_b);
		}
		free_stack(stack_a);
		free_stack(stack_b);
	}
	else
		return (0);
}
