/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_stack_moove.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:48:50 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/17 12:22:58 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	refresh_stack_moove(t_stack *a, t_stack *b)
{
	t_stack *ptr;

	ptr = a;

	while (ptr)
	{	
		calcule_destination(ptr, b);
		ptr->type_of_way_b = choose_sens(ptr, b);
		ptr->type_of_way_a = choose_sens_a(ptr, a);
		ptr ->nbr_move = nbr_moove(ptr, b);
		ptr = ptr->next;
	}
}