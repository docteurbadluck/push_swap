/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_correct_number.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:40:07 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/19 12:02:51 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *lower_moove_node(t_stack *a);

void send_correct_number(t_stack **a, t_stack **b)
{
	t_stack *ptr;
	ptr = lower_moove_node(*a);
	//printf("value : %d\n", ptr->value);
	//printf("Ma %d Mb %d Mc %d ,type of way a %d type of way b %d total : %d\n\n\n", ptr->nbr_move_a, ptr->nbr_move_b, ptr->nbr_move_c, ptr->type_of_way_a, ptr->type_of_way_b, ptr->nbr_move);
	if (ptr->nbr_move_c)
	{
		if (ptr->type_of_way_a == NORMAL_WAY)
		{
			while (ptr->nbr_move_c)
			{
				rr(a, b);
				ptr->nbr_move_c--;
			}
		}
		else 
			while (ptr->nbr_move_c)
			{
				rrr(a,b);
				ptr->nbr_move_c--;
			}
	}
	if (ptr->nbr_move_a)
	{
		if (ptr->type_of_way_a == NORMAL_WAY)
		{
			while (ptr->nbr_move_a)
			{
				ra(a);
				ptr->nbr_move_a--;
			}
		}
		else 
			while (ptr->nbr_move_a)
			{
				rra(a);
				ptr->nbr_move_a--;
			}
	}
	if (ptr->nbr_move_b)
	{
		if (ptr->type_of_way_b == NORMAL_WAY)
		{
			while (ptr->nbr_move_b > 0)
			{
				rb(b);
				ptr->nbr_move_b--;
			}
		}
		else 
			while (ptr->nbr_move_b > 0)
			{
				rrb(b);
				ptr->nbr_move_b--;
			}
	}
	pb(a, b);
}

t_stack *lower_moove_node(t_stack *a)
{
	t_stack *ptr;
	int lower;
	t_stack *ptr_lower_node;

	ptr_lower_node = NULL;

	lower = INT_MAX;
	ptr = a;
	while(ptr)
	{
		if (ptr->nbr_move < lower)
		{
			lower = ptr->nbr_move;
			ptr_lower_node = ptr;
		}
		ptr = ptr->next;
	}
	return ptr_lower_node;
}