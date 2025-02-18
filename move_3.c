/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:14:17 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/17 11:46:14 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
	refresh_pos(*a);
	refresh_pos(*b);
	refresh_invert_pos(*a);
	refresh_invert_pos(*b);
	ft_printf("rr\n");
}

void	rra(t_stack **a)
{
	ft_reverse_rotate(a);
	refresh_pos(*a);
	refresh_invert_pos(*a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	ft_reverse_rotate(b);
	refresh_pos(*b);
	refresh_invert_pos(*b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	refresh_pos(*a);
	refresh_pos(*b);
	refresh_invert_pos(*a);
	refresh_invert_pos(*b);
	ft_printf("rrr\n");
}

void	pb(t_stack **a, t_stack **b)
{
	ft_push(a, b);
	refresh_pos(*a);
	refresh_pos(*b);
	refresh_invert_pos(*a);
	refresh_invert_pos(*b);
	ft_printf("pb\n");
}
