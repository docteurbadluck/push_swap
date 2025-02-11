/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:14:17 by tdeliot           #+#    #+#             */
/*   Updated: 2025/01/14 16:42:58 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_list **a, t_list **b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_printf("rr\n");
}

void	rra(t_list **a)
{
	ft_reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_list **b)
{
	ft_reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_list **a, t_list **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	ft_printf("rrr\n");
}

void	pb(t_list **a, t_list **b)
{
	ft_push(a, b);
	ft_printf("pb\n");
}
