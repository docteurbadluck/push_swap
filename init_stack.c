/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:48:39 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/19 11:12:23 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_how_many_superior_stack(t_stack *a, t_stack *start);

t_stack	*init_a(t_list *arg)
{
	t_stack	*new;
	t_list	*ptr;
	int		*content;
	int		i = 0;
	
	new = NULL; 
	ptr = arg;
	while (ptr)
	{
		content = ptr->content;
		lst_push_back_double(&new, *content);
		lstlast_double(new)->index = 0;
		lstlast_double(new)->pos = i;
		lstlast_double(new)->dest = 0;
		lstlast_double(new)->nbr_move = 0;
		lstlast_double(new)->invert_pos = 0;
		lstlast_double(new)->type_of_way_a = 0;
		lstlast_double(new)->type_of_way_b = 0;
		lstlast_double(new)->nbr_move_c = 0;

		i++;
		ptr = ptr->next;
	}
	init_index(new);

	return new;
}

void init_index(t_stack *a)
{
	t_stack *ptr;
	int size;

	if (!a)
		return;
	size = lstsize_double(a);

	ptr = a;
	while(ptr)
	{
		ptr->index = size - ft_how_many_superior_stack(ptr, a); 
		ptr = ptr->next;
	}

}



int	ft_how_many_superior_stack(t_stack *a, t_stack *start)
	{
		int	value;
		int	compteur;
		t_stack *ptr_start;

		ptr_start = start;
		compteur = 0;
		value = a->value;
		while (ptr_start)
		{
			if (value < ptr_start->value)
				compteur++;
			ptr_start = ptr_start->next;
		}
		return (compteur);
	}

	void refresh_pos(t_stack *a)
	{
		t_stack	*ptr;
		int		i;
	
		ptr = a;
		i = 0;
		if (!a)
			return ;
		while (ptr)
		{
			ptr->pos = i;
			i++;
			ptr = ptr->next;
		}
	}
	
	void refresh_invert_pos(t_stack *a)
	{
		t_stack	*ptr;
		int		i;
	
		ptr = a;
		i = lstlast_double(a)->pos;
		if (!a)
			return ;
		while (ptr)
		{
			ptr->invert_pos = i;
			i--;
			ptr = ptr->next;
		}
	}