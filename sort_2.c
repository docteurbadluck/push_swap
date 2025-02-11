/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:17:34 by tdeliot           #+#    #+#             */
/*   Updated: 2025/01/14 16:34:36 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_back_everything(t_list **a, t_list **b)
{
	int	nbr;

	nbr = ft_lstsize(*b);
	while (nbr > 0)
	{
		pa(b, a);
		nbr--;
	}
}

void	ft_order_last_card(t_list **a, t_list **b, t_compare **comparator)
{
	pb(a, b);
	(*comparator)->first_b_card = *b;
	(*comparator)->second_b_card = (*b)->next;
	(*comparator)->size_b_stack = ft_lstsize(*b);
	ft_order_b_stack(comparator, b);
	*a = NULL;
}

void	ft_handle_compare_matrice(t_compare **comparator)
{
	ft_handle_compare_matrice_part_1(comparator);
	ft_handle_compare_matrice_part_2(comparator);
	ft_compare_matrice_sum(comparator);
}

void	ft_handle_compare_matrice_part_1(t_compare **comparator)
{
	if ((*comparator)->first_a_card && (*comparator)->first_b_card)
	{
		(*comparator)->compare_matrice[0][0] = *(int *)(*comparator)
			->first_a_card->content - *(int *)(*comparator)
			->first_b_card->content;
	}
	else
		(*comparator)->compare_matrice[0][0] = INT_MAX;
	if ((*comparator)->second_a_card && (*comparator)->first_b_card)
	{
		(*comparator)->compare_matrice[0][1] = *(int *)(*comparator)
			->second_a_card->content - *(int *)(*comparator)
			->first_b_card->content;
	}
	else
		(*comparator)->compare_matrice[0][1] = INT_MAX;
	if ((*comparator)->last_a_card && (*comparator)->first_b_card)
	{
		(*comparator)->compare_matrice[0][2] = *(int *)(*comparator)
			->last_a_card->content - *(int *)(*comparator)
			->first_b_card->content;
	}
	else
		(*comparator)->compare_matrice[0][1] = INT_MAX;
}

void	ft_handle_compare_matrice_part_2(t_compare **comparator)
{
	if (((*comparator)->first_a_card && (*comparator)->last_b_card))
	{
		(*comparator)->compare_matrice[1][0] = *(int *)(*comparator)
			->first_a_card->content - *(int *)(*comparator)
			->last_b_card->content;
	}
	else
		(*comparator)->compare_matrice[1][0] = INT_MAX;
	if (((*comparator)->second_a_card && (*comparator)->last_b_card))
	{
		(*comparator)->compare_matrice[1][1] = *(int *)(*comparator)
			->second_a_card->content - *(int *)(*comparator)
			->last_b_card->content;
	}
	else
		(*comparator)->compare_matrice[1][1] = INT_MAX;
	if ((*comparator)->second_a_card && (*comparator)->last_b_card)
	{
		(*comparator)->compare_matrice[1][2] = *(int *)(*comparator)
			->last_a_card->content - *(int *)(*comparator)
			->last_b_card->content;
	}
	else
		(*comparator)->compare_matrice[1][2] = INT_MAX;
}
