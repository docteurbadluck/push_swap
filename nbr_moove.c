/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_moove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:38:56 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/18 15:29:35 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nbr_moove_a(t_stack *a)
{

	int middle;
	
	middle = lstlast_double(a)->pos / 2 + 1;

	if (a->pos < middle)
		return a->pos; 
	else 
		return a->invert_pos + 1; 
}

int	nbr_moove_b(t_stack *a, t_stack *b)
{	
	if (a->type_of_way_b == NORMAL_WAY)
		return a->dest;
	if (a->type_of_way_b == INVERT_WAY)
	{
		return (lstsize_double(b)- a->dest);
	}
	return -1;
}

int nbr_moove(t_stack *a, t_stack *b)
{
	int	total_nbr_move;

	a->nbr_move_a = nbr_moove_a(a);
	a->nbr_move_b = nbr_moove_b(a, b);
	total_nbr_move = a->nbr_move_a + a->nbr_move_b;
	return (total_nbr_move);
}

