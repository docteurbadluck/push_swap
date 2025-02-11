/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:13:56 by tdeliot           #+#    #+#             */
/*   Updated: 2025/01/14 16:42:43 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a)
{
	ft_swap(a);
	ft_printf("sa\n");
}

void	sb(t_list **b)
{
	ft_swap(b);
	ft_printf("sb\n");
}

void	ra(t_list **a)
{
	ft_rotate(a);
	ft_printf("ra\n");
}

void	rb(t_list **b)
{
	ft_rotate(b);
	ft_printf("rb\n");
}

void	ss(t_list **a, t_list **b)
{
	ft_swap(a);
	ft_swap(b);
	ft_printf("ss\n");
}
