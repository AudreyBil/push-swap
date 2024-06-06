/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:37:58 by abillote          #+#    #+#             */
/*   Updated: 2024/05/19 17:39:15 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_double(t_stack **stack_a, int value)
{
	t_stack	*current;

	current = *stack_a;
	while (current)
	{
		if (current->content == value)
			error_input();
		current = current->next;
	}
}

void	store_stack(t_stack **stack_a, char **substrg, int i)
{
	int		value;
	long	tmp;

	while (substrg[i])
	{
		tmp = ft_atoi_adapted(substrg[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			error_input();
		value = ft_atoi_adapted(substrg[i]);
		ft_check_double(stack_a, value);
		ft_lstadd_back_stack(stack_a, ft_lstnew_stack(value));
		i++;
	}
}

void	check_input_and_store_stack(t_stack **stack_a, char **substrg, int i)
{
	int	j;
	int	k;

	j = i;
	while (substrg[j])
	{
		k = 0;
		if (!((substrg[j][k] >= '0' && substrg[j][k] <= '9') || \
		substrg[j][k] == '+' || (substrg[j][k] == '-')))
			error_input();
		k++;
		while (substrg[j][k])
		{
			if (!((substrg[j][k] >= '0' && substrg[j][k] <= '9')))
				error_input();
			k++;
		}
		j++;
	}
	store_stack(stack_a, substrg, i);
}

char	**string_to_numbers(char *s)
{
	int		i;
	char	**substrg;

	i = 0;
	while (s[i])
	{
		if (!((s[i] >= '0' && s[i] <= '9') || s[i] == '-' \
		|| s[i] == '+' || s[i] == 32))
			error_input();
		i++;
	}
	substrg = ft_split(s, 32);
	return (substrg);
}
