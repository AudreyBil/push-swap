/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:30:23 by abillote          #+#    #+#             */
/*   Updated: 2024/10/09 13:29:55 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsize_stack(t_stack *lst)
{
	int		n;
	t_stack	*lsttemp;

	n = 0;
	lsttemp = lst;
	while (lsttemp != NULL)
	{
		n++;
		lsttemp = lsttemp->next;
	}
	return (n);
}

void	ft_lstadd_back_stack(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	last = ft_lstlast_stack(*lst);
	if (!last)
		*lst = new;
	else
		last->next = new;
}

t_stack	*ft_lstnew_stack(int content)
{
	t_stack	*lstnew;

	lstnew = malloc(sizeof(t_stack));
	if (!lstnew)
		return (NULL);
	lstnew->content = content;
	lstnew->next = NULL;
	return (lstnew);
}

void	ft_lstadd_front_stack(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

t_stack	*ft_lstlast_stack(t_stack *lst)
{
	t_stack	*lsttemp;

	if (!lst)
		return (NULL);
	lsttemp = lst;
	while (lsttemp->next != NULL)
	{
		lsttemp = lsttemp->next;
	}
	return (lsttemp);
}
