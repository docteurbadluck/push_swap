/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:12:12 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/18 15:47:34 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_back(t_stack **b ,t_stack **a)
{
	int size = lstsize_double(*b);
	int i = 1;

	while (i < size)
	{
		pa(b, a);
		while((*a)->index == (lstlast_double(*a)->index + 1))
			rra(a);
		i++;
	}
	last_pa(b, a);
	while((*a)->index == ((lstlast_double(*a)->index )+ 1))
		rra(a);
}
