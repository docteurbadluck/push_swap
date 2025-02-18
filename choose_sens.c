/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:31:51 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/17 12:22:18 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	choose_sens(t_stack *a, t_stack *b)
{
	int middle;
	
	middle = lstlast_double(b)->pos / 2 + 1;

	if (a->dest < middle)
	{
		return NORMAL_WAY;
	}
	else 
	{
		return INVERT_WAY;
	}

}

int	choose_sens_a(t_stack *a, t_stack *b)
{
	int middle;
	
	middle = lstlast_double(b)->pos / 2 + 1;

	if (a->pos < middle)
	{
		return NORMAL_WAY;
	}
	else 
	{
		return INVERT_WAY;
	}

}
