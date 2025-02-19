/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_moove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:38:56 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/19 11:57:24 by tdeliot          ###   ########.fr       */
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

int nbr_moove_c(t_stack *a)
{
	int nbr_move_c;

	nbr_move_c = 0;
	
	if (a->type_of_way_a == a->type_of_way_b && a->nbr_move_b>0 && a->nbr_move_a > 0)
	{
		//printf("double rotate possible\n");
		if (a->nbr_move_a <= a->nbr_move_b)
			nbr_move_c= a->nbr_move_a;
		else 
			nbr_move_c = a->nbr_move_b;
		//printf(" avant Ma %d Mb %d Mc %d \n\n\n", a->nbr_move_a, a->nbr_move_b, nbr_move_c);
		a->nbr_move_a -= nbr_move_c;
		a->nbr_move_b -= nbr_move_c;
	}
	return (nbr_move_c);
}


int nbr_moove(t_stack *a, t_stack *b)
{
	int	total_nbr_move;

	a->nbr_move_a = nbr_moove_a(a);
	a->nbr_move_b = nbr_moove_b(a, b);
	a->nbr_move_c = nbr_moove_c(a);

	total_nbr_move = a->nbr_move_a + a->nbr_move_b + a->nbr_move_c;
	//printf("Ma %d Mb %d Mc %d ,type of way a %d type of way b %d total : %d\n\n\n", a->nbr_move_a, a->nbr_move_b, a->nbr_move_c, a->type_of_way_a, a->type_of_way_b, total_nbr_move);
	return (total_nbr_move);
}

