/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:28:31 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/18 16:18:54 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *a)
{
	t_stack	*current;
	t_stack	*iterator;
	int		value;
	int		comparator;

	current = a;
	iterator = current->next;
	while (current->next != NULL)
	{
		while (iterator != NULL)
		{
			value = current->value;
			comparator = iterator->value;
			if (value > comparator)
				return (0);
			iterator = iterator->next;
		}
		current = current->next;
		iterator = current->next;
	}
	return (1);
}

void	ft_sort_2(t_stack **a)
{
	t_stack	*first;

	first = *a;
	if (first->value > first->next->value)
		sa(a);
	return ;
}

void	ft_sort_3(t_stack **a)
{
	int		pos1 = ((*a)->value);
	int		pos2 = (*a)->next->value;
	int		pos3 = (*a)->next->next->value;

	if (ft_is_sorted(*a))
		return ;
	if ((pos1 < pos2))
	{
		if (pos1 < pos3)
		{
			rra(a);
			sa(a);
		}
		else
			rra(a);
		return ;
	}
	ft_sort_3_2(a, pos1, pos2, pos3);
	return ;
}

void	ft_sort_3_2(t_stack **a, int pos1, int pos2, int pos3)
{
	if (pos1 > pos2 && pos1 < pos3)
	{
		sa(a);
		return ;
	}
	if ((pos1 > pos2) && (pos1 > pos3))
	{
		ra(a);
		if (pos2 > pos3)
			sa(a);
		return ;
	}
	return ;
}


