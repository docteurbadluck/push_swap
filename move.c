/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:15:49 by tdeliot           #+#    #+#             */
/*   Updated: 2025/01/14 16:42:28 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_list **top)
{
	t_list	*second;

	if (*top == NULL || (*top)->next == NULL)
		return (-1);
	second = (*top)->next;
	(*top)->next = second->next;
	second->next = *top;
	*top = second;
	return (0);
}

int	ft_rotate(t_list **top)
{
	t_list	*second;

	if (*top == NULL || (*top)->next == NULL)
		return (-1);
	second = (*top)->next;
	ft_lstlast(*top)->next = (*top);
	(*top)->next = NULL;
	*top = second;
	return (0);
}

int	ft_reverse_rotate(t_list **top)
{
	t_list	*bottom;
	t_list	*new_bottom;

	if (*top == NULL || (*top)->next == NULL)
		return (-1);
	bottom = ft_lstlast(*top);
	new_bottom = (*top);
	while (new_bottom->next != bottom)
		new_bottom = new_bottom->next;
	new_bottom->next = NULL;
	bottom->next = (*top);
	(*top) = bottom;
	return (0);
}

int	ft_push(t_list **src, t_list **dest)
{
	t_list	*second;

	if (*src == NULL)
		return (-1);
	second = (*src)->next;
	(*src)->next = (*dest);
	(*dest) = (*src);
	(*src) = second;
	return (0);
}

void	pa(t_list **b, t_list **a)
{
	ft_push(b, a);
	ft_printf("pa\n");
}
