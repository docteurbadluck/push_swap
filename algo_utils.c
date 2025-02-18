/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:13:42 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/14 12:23:03 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int higher_index(t_stack *b)
{
	t_stack *ptr;
	int higher;

	higher = INT_MIN;
	ptr = b;
	while(ptr)
	{
		if (ptr->index > higher)
			higher = ptr->index;
		ptr = ptr->next;
	}
	return higher;
}

int lower_index(t_stack *b)
{
	t_stack *ptr;
	int lower;

	lower = INT_MAX;
	ptr = b;
	while(ptr)
	{
		if (ptr->index < lower)
			lower = ptr->index;
		ptr = ptr->next;
	}
	return lower;
}

t_stack *get_biggest_node(t_stack *b)
{
	t_stack *ptr;
	int higher;

	if (!b)
		return NULL;
	higher =  higher_index(b);
	ptr = b;

	while (ptr)
	{
		if (ptr->index == higher)
			return ptr;
		ptr = ptr->next; 
	}
	return NULL;
}