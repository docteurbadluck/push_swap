/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:13:56 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/17 11:02:42 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	ft_swap(a);
	refresh_pos(*a);
	refresh_invert_pos(*a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	ft_swap(b);
	refresh_pos(*b);
	refresh_invert_pos(*b);
	ft_printf("sb\n");
}

void	ra(t_stack **a)
{
	ft_rotate(a);
	refresh_pos(*a);
	refresh_invert_pos(*a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	ft_rotate(b);
	refresh_pos(*b);
	refresh_invert_pos(*b);
	ft_printf("rb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	ft_swap(a);
	refresh_pos(*a);
	ft_swap(b);
	refresh_pos(*b);
	refresh_invert_pos(*a);
	refresh_invert_pos(*b);
	ft_printf("ss\n");
}
