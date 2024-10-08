/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:47:31 by abillote          #+#    #+#             */
/*   Updated: 2024/10/08 17:12:58 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	process_instructions(char *instruction, t_stack **a_bonus, \
			t_stack **b_bonus)
{
	if (ft_strncmp(instruction, "sa\n", 3) == 0)
		swap(a_bonus);
	else if (ft_strncmp(instruction, "sb\n", 3) == 0)
		swap(b_bonus);
	else if (ft_strncmp(instruction, "ss\n", 3) == 0)
		swap_both_bonus(a_bonus, b_bonus);
	else if (ft_strncmp(instruction, "pa\n", 3) == 0)
		push(a_bonus, b_bonus);
	else if (ft_strncmp(instruction, "pb\n", 3) == 0)
		push(b_bonus, a_bonus);
	else if (ft_strncmp(instruction, "ra\n", 3) == 0)
		rotate(a_bonus);
	else if (ft_strncmp(instruction, "rb\n", 3) == 0)
		rotate(b_bonus);
	else if (ft_strncmp(instruction, "rr\n", 3) == 0)
		rotate_both_bonus(a_bonus, b_bonus);
	else if (ft_strncmp(instruction, "rra\n", 4) == 0)
		reverse_rotate(a_bonus);
	else if (ft_strncmp(instruction, "rrb\n", 4) == 0)
		reverse_rotate(b_bonus);
	else if (ft_strncmp(instruction, "rrr\n", 4) == 0)
		reverse_rotate_both_bonus(a_bonus, b_bonus);
	else
		error_input();
}

void	read_execute_instructions(t_stack **a_bonus, t_stack **b_bonus)
{
	int		i;
	char	*instruction;

	i = 1;
	while (i)
	{
		instruction = get_next_line(0);
		if (instruction == NULL)
			i = 0;
		else
			process_instructions(instruction, a_bonus, b_bonus);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a_bonus;
	t_stack	*b_bonus;

	a_bonus = NULL;
	b_bonus = NULL;
	if (argc == 2)
		error_input();
	if (argc > 2)
	{
		check_input_and_store_stack(&a_bonus, argv, 1);
		read_execute_instructions(&a_bonus, &b_bonus);
		if (ft_check_sorted(a_bonus) == 1 && b_bonus == NULL)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		free_stack(a_bonus);
		free_stack(b_bonus);
	}
	else
		return (0);
}
