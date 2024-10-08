/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:50:30 by abillote          #+#    #+#             */
/*   Updated: 2024/10/02 16:10:02 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

void	process_instructions(char *instruction, t_stack **a_bonus, \
		t_stack **b_bonus);
void	read_execute_instructions(t_stack **a_bonus, t_stack **b_bonus);
void	swap_both_bonus(t_stack **stack_a, t_stack **stack_b);
void	rotate_both_bonus(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_both_bonus(t_stack **stack_a, t_stack **stack_b);

#endif
