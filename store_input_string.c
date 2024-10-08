/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_input_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:47:50 by abillote          #+#    #+#             */
/*   Updated: 2024/10/08 17:11:08 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_input_split(char **substrg)
{
	free_split(substrg);
	error_input();
}

void	check_input_and_store_stack_split(t_stack **stack_a, \
			char **substrg, int i)
{
	int	j;
	int	k;

	j = i;
	while (substrg[j])
	{
		k = 0;
		if (!((substrg[j][k] >= '0' && substrg[j][k] <= '9') || \
		substrg[j][k] == '+' || (substrg[j][k] == '-')))
			error_input_split(substrg);
		k++;
		while (substrg[j][k])
		{
			if (!((substrg[j][k] >= '0' && substrg[j][k] <= '9')))
				error_input_split(substrg);
			k++;
		}
		j++;
	}
	store_stack_split(stack_a, substrg, i);
}

void	store_stack_split(t_stack **stack_a, char **substrg, int i)
{
	int		value;
	long	tmp;

	while (substrg[i])
	{
		tmp = ft_atoi_adapted(substrg[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
		{
			free_split(substrg);
			error_input();
		}
		value = ft_atoi_adapted(substrg[i]);
		ft_check_double_split(stack_a, value, substrg);
		ft_lstadd_back_stack(stack_a, ft_lstnew_stack(value));
		i++;
	}
}

void	ft_check_double_split(t_stack **stack_a, int value, char **substrg)
{
	t_stack	*current;

	current = *stack_a;
	while (current)
	{
		if (current->content == value)
		{
			free_stack(*stack_a);
			free_split(substrg);
			error_input();
		}
		current = current->next;
	}
}
