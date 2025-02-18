/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:15:17 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/18 15:56:45 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted_rev(t_stack *a);
void	ft_sort_3_2_rev(t_stack **a, int pos1, int pos2, int pos3);


void	ft_sort_3_rev(t_stack **b)
{
	int		pos1 = ((*b)->value);
	int		pos2 = (*b)->next->value;
	int		pos3 = (*b)->next->next->value;

	if (pos1 > pos2 && pos2 > pos3)
		{
			return ;
		}
	if ((pos1 > pos2))
	{
		if (pos1 > pos3)
		{
			rb(b);
			sb(b);
			rrb(b);
		}
		else
			rrb(b);
		return ;
	}
	ft_sort_3_2_rev(b, pos1, pos2, pos3);
	return ;
}

void	ft_sort_3_2_rev(t_stack **b, int pos1, int pos2, int pos3)
{
	if (pos1 < pos2 && pos1 > pos3)
	{
		sb(b);
		return ;
	}
	if ((pos1 < pos2) && (pos1 < pos3))
	{
		rb(b);
		if (pos2 < pos3)
			sb(b);
		return ;
	}
	return ;
}


int ft_is_sorted_rev(t_stack *b)
{
	t_stack *current = b;

	while (current && current->next)
	{
		if (current->value < current->next->value)
			return (0);
		current = current->next;
	}

	return (1);
}