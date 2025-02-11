/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:36:35 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/11 14:58:56 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_how_many_superior(t_list *a)
{
	int	value;
	int	compteur;

	compteur = 0;
	value = *(int *)a->content;
	while (a)
	{
		if (value < *(int *)a->content)
			compteur++;
		a = a->next;
	}
	return (compteur);
}

int	ft_sort_4(t_list **a, t_list **b)
{
	int	i;

	i = ft_lstsize(*a);
	while (i)
	{
		if (ft_how_many_superior(*a) < 2)
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

int	ft_sort_5(t_list **a, t_list **b)
{
	int	i;
	int	flag;

	flag = 0;
	i = ft_lstsize(*a);
	while (i)
	{
		if (ft_how_many_superior(*a) < 3)
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
	if (*(int *)(*b)->content < *(int *)(*b)->next->content)
		sb(b);
	pa(b, a);
	pa(b, a);
	return (1);
}

void	ft_ascend_sort(int nb_carte, int stamp, t_list **b)
{
	while (nb_carte > 1)
	{
		sb(b);
		rb(b);
		nb_carte--;
	}
	sb(b);
	while (stamp > 1)
	{
		rrb(b);
		stamp--;
	}
}

void	ft_reverse_sort(int nb_carte_old, t_list **b, t_compare **comparator)
{
	int	nb_carte;
	int	stamp;

	nb_carte = (*comparator)->size_b_stack - nb_carte_old;
	stamp = nb_carte;
	while (nb_carte > 1)
	{
		rrb(b);
		sb(b);
		nb_carte--;
	}
	while (stamp > 0)
	{
		rb(b);
		stamp--;
	}
}
