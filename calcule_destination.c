/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcule_destination.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:09:33 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/18 15:48:10 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int destination_extrem_value(t_stack *a, t_stack *b)
{
	if (!b)
		return (-1);
	if (a->index > higher_index(b))
	{
		a->dest = get_biggest_node(b)->pos;
		return (0);
	}
	if (a->index < lower_index(b))
	{
		a->dest = (get_biggest_node(b)->pos);
		return (0);
	}
	return (-1);
}



//the order of operation is important ? 
int destination_middle_value(t_stack *a, t_stack *b)
{
	t_stack *ptr;
	t_stack *ptr_before;

	if (!b)
		return (-1);

	ptr = b->next;
	ptr_before = b;

	while (ptr)
	{
		if (a->index < ptr_before->index && a->index > ptr->index)
			return ptr->pos;
		ptr = ptr->next;
		ptr_before = ptr_before ->next;
	}
	ptr = b;
	ptr_before = lstlast_double(b);
	if (a -> index > ptr->index && a->index < ptr_before->index)
		return (0);

	return (-1);
}

int	calcule_destination(t_stack *a, t_stack *b)
{

	if (!destination_extrem_value(a, b))
	{
		return 0;
	}
	a->dest = destination_middle_value(a, b);
	if (a->dest == -1)
	{
		ft_printf("erreur middle_value :value :%d\n", a->value);
		return (-1);
	}
	return 0;
}



