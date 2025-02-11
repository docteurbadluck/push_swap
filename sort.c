/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:28:31 by tdeliot           #+#    #+#             */
/*   Updated: 2025/01/15 09:58:35 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_list *a)
{
	t_list	*current;
	t_list	*iterator;
	int		*value;
	int		*comparator;

	current = a;
	iterator = current->next;
	while (current->next != NULL)
	{
		while (iterator != NULL)
		{
			value = current->content;
			comparator = iterator->content;
			if (*value > *comparator)
				return (0);
			iterator = iterator->next;
		}
		current = current->next;
		iterator = current->next;
	}
	return (1);
}

void	ft_sort_2(t_list **a)
{
	t_list	*first;
	int		*value;
	int		*comparator;

	first = *a;
	value = first->content;
	comparator = first->next->content;
	if (*value > *comparator)
		sa(a);
	return ;
}

void	ft_attribute(t_list **a, int **pos1,
				int **pos2, int **pos3)
{
	*pos1 = ((*a)->content);
	*pos2 = (*a)->next->content;
	*pos3 = (*a)->next->next->content;
}

void	ft_sort_3(t_list **a)
{
	int		*pos1;
	int		*pos2;
	int		*pos3;

	ft_attribute(a, &pos1, &pos2, &pos3);
	if (ft_is_sorted(*a))
		return ;
	if ((*pos1 < *pos2))
	{
		if (*pos1 < *pos3)
		{
			ra(a);
			sa(a);
			rra(a);
		}
		else
			rra(a);
		return ;
	}
	ft_sort_3_2(a, pos1, pos2, pos3);
	return ;
}

void	ft_sort_3_2(t_list **a, int *pos1, int *pos2, int *pos3)
{
	if (*pos1 > *pos2 && *pos1 < *pos3)
	{
		sa(a);
		return ;
	}
	if ((*pos1 > *pos2) && (*pos1 > *pos3))
	{
		ra(a);
		if (*pos2 > *pos3)
			sa(a);
		return ;
	}
	return ;
}
