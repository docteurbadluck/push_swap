/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:15:49 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/18 15:35:00 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_stack **top)
{
	t_stack	*second;

	if (*top == NULL || (*top)->next == NULL)
		return (-1);
	second = (*top)->next;
	(*top)->next = second->next;
	second->next = *top;
	*top = second;
	return (0);
}

int	ft_rotate(t_stack **top)
{
	t_stack	*second;

	if (*top == NULL || (*top)->next == NULL)
		return (-1);
	second = (*top)->next;
	lstlast_double(*top)->next = (*top);
	(*top)->next = NULL;
	*top = second;
	return (0);
}

int	ft_reverse_rotate(t_stack **top)
{
	t_stack	*bottom;
	t_stack	*new_bottom;

	if (*top == NULL || (*top)->next == NULL)
		return (-1);
	bottom = lstlast_double(*top);
	new_bottom = (*top);
	while (new_bottom->next != bottom)
		new_bottom = new_bottom->next;
	new_bottom->next = NULL;
	bottom->next = (*top);
	(*top) = bottom;
	return (0);
}

int	ft_push(t_stack **src, t_stack **dest)
{
	t_stack	*second;

	if (*src == NULL)
		return (-1);
	second = (*src)->next;
	(*src)->next = (*dest);
	(*dest) = (*src);
	(*src) = second;
	return (0);
}

void	pa(t_stack **b, t_stack **a)
{
	ft_push(b, a);
	refresh_pos(*a);
	refresh_pos(*b);
	refresh_invert_pos(*a);
	refresh_invert_pos(*b);
	ft_printf("pa\n");
}

void	last_pa(t_stack **b, t_stack **a)
{
	ft_push(b, a);
	refresh_pos(*a);
	refresh_invert_pos(*a);
	ft_printf("pa\n");
}
