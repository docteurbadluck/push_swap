/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:36:35 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/12 18:26:32 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_sort_4(t_stack **a, t_stack **b)
{
	int	i;

	i = lstsize_double(*a);
	while (i)
	{
		if (ft_how_many_superior_stack(*a, *a) < 2)
			ra(a);
		else
		{
			pb(a, b);
			break ;
		}
	}
	ft_sort_3(a);
	pa(b, a);
	if (!ft_is_sorted(*a))
		sa(a);
	return (0);
}

int	ft_sort_5(t_stack **a, t_stack **b)
{
	int	i;
	int	flag;

	flag = 0;
	i = lstsize_double(*a);
	while (i)
	{
		if (ft_how_many_superior_stack(*a, *a) < 3)
			ra(a);
		else
		{
			pb(a, b);
			if (flag == 1)
				break ;
			flag = 1;
		}
	}
	ft_sort_3(a);
	if ((*b)->value < (*b)->next->value)
		sb(b);
	pa(b, a);
	pa(b, a);
	return (1);
}
