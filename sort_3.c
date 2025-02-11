/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:34:46 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/11 14:54:06 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_full_packet(t_list **a, t_list **b, t_compare **comparator)
{
	*comparator = ft_init_stack(a, b);
	ft_maj_comparator(*a, *b, comparator);
	while ((*comparator)->size_a_stack > 1)
	{
		ft_send_correct_card(a, b, comparator);
		ft_order_b_stack(comparator, b);
		ft_maj_comparator(*a, *b, comparator);
	}
	ft_order_last_card(a, b, comparator);
	ft_push_back_everything(a, b);
	return ;
}

t_compare	*ft_init_stack(t_list **a, t_list **b)
{
	t_compare	*new;
	int			value_first;
	int			value_second;

	new = ft_new_comparator(*a);
	value_first = *(int *)new->first_a_card->content;
	value_second = *(int *)new->second_a_card->content;
	if (value_first < value_second)
	{
		pb(a, b);
		pb(a, b);
	}
	else
	{
		sa(a);
		pb(a, b);
		pb(a, b);
	}
	ft_maj_comparator(*a, *b, &new);
	return (new);
}

t_compare	*ft_new_comparator(t_list *a)
{
	t_compare	*new;

	new = malloc(sizeof(t_compare));
	if (!new)
		return (NULL);
	new->first_a_card = a;
	new->second_a_card = a->next;
	new->last_a_card = ft_lstlast(a);
	new->size_a_stack = ft_lstsize(a);
	return (new);
}

void	ft_maj_comparator(t_list *a, t_list *b, t_compare **comparator)
{
	(*comparator)->first_a_card = a;
	(*comparator)->second_a_card = a->next;
	(*comparator)->last_a_card = ft_lstlast(a);
	(*comparator)->first_b_card = b;
	(*comparator)->second_b_card = b->next;
	(*comparator)->last_b_card = ft_lstlast(b);
	(*comparator)->size_a_stack = ft_lstsize(a);
	(*comparator)->size_b_stack = ft_lstsize(b);
	if ((*comparator)->size_a_stack)
		ft_handle_compare_matrice(comparator);
}

void	ft_send_correct_card(t_list **a, t_list **b, t_compare **comparator)
{
	if (ft_which_card(*comparator) == 0)
	{
		pb(a, b);
		ft_maj_comparator(*a, *b, comparator);
		return ;
	}
	if (ft_which_card(*comparator) == 1)
	{
		sa(a);
		pb(a, b);
		ft_maj_comparator(*a, *b, comparator);
		return ;
	}
	if (ft_which_card(*comparator) == 2)
	{
		rra(a);
		pb(a, b);
		ft_maj_comparator(*a, *b, comparator);
		return ;
	}
}
