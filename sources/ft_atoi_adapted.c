/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_adapted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:29:15 by abillote          #+#    #+#             */
/*   Updated: 2024/10/09 13:29:32 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atoi_adapted(const char *nptr)
{
	size_t	i;
	long	number;
	int		sign;

	i = 0;
	number = 0;
	sign = 1;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		number = number * 10 + (nptr[i] - '0');
		i++;
	}
	number *= sign;
	return (number);
}
