/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:32:20 by abillote          #+#    #+#             */
/*   Updated: 2024/10/09 13:29:59 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_split(char **input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		free(input[i]);
		i++;
	}
	free(input);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**input;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		input = ft_split(argv[1], ' ');
		check_input_and_store_stack_split(&stack_a, input, 0);
		free_split(input);
	}
	if (argc > 2)
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
