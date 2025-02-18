/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_any_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:44:57 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/17 15:52:24 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"



void	print_t_stack( t_stack *start)
{
	t_stack *ptr;

	ptr = start;
	while (ptr)
	{
		ft_printf(" value : %d, pos : %d, index : %d\n", ptr->value, ptr->pos, ptr->index);
		ft_printf(" dest : %d, invert_pos : %d, nbr_move : %d type of way b: %d type of way a :%d\n", ptr->dest, ptr->invert_pos, ptr->nbr_move, ptr->type_of_way_b, ptr->type_of_way_a);
		ft_printf(" nbr moove a : %d, nbr moove b : %d,\n\n", ptr->nbr_move_a, ptr->nbr_move_b);

		ptr = ptr->next;
	}
	ft_printf("\n");
}

void	print_any_list(void *list, int type)
{
	t_stack *ptr;

	if (type == T_STACK)
	{
		ptr = list;
		print_t_stack(ptr);
	}


}

void	print_les_stack(t_stack *a, t_stack *b )
{
	t_stack *ptr;
	t_stack *ptr_b;;

	ptr = a;
	ptr_b = b;
	while (ptr || ptr_b)
	{
		if (ptr)
		{
			ft_printf("a : %d		",ptr->value);
			ptr = ptr->next;
		}
		if (ptr_b)
		{
			ft_printf("b : %d", ptr_b->value);
			ptr_b = ptr_b->next;
		}
		ft_printf("\n");
	}
}
