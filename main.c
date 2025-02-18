/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:58:21 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/18 15:56:21 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_a(t_list *arg);
void print_any_list(void *list, int type);

int	main(int argc, char **argv)
{
	t_list	*arg;
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	arg = NULL;
	if (ft_check_input(argc, argv, &arg))
		return (-1);
	a = init_a(arg);
	ft_which_sort( &a, &b);
	list_clear_double(a);
	if (b)
		list_clear_double(b);
	ft_lstclear(&arg, &ft_lstdel);
	return (0);
}

void	ft_which_sort(t_stack **a, t_stack **b)
{
	if (ft_is_sorted(*a))
		return ;
	if (lstsize_double(*a) == 2)
		ft_sort_2(a);
	if (lstsize_double(*a) == 3)
		ft_sort_3(a);
	if (lstsize_double(*a) == 4)
		ft_sort_4(a, b);
	if (lstsize_double(*a) == 5)
		ft_sort_5(a, b);
	if (lstsize_double(*a) > 5)
		sort_full_packet(a, b);

}





void sort_full_packet(t_stack **a, t_stack **b)
{
	int list_size; 
	list_size = lstlast_double(*a)->pos;
	pb(a, b);
	pb(a,b);
	pb(a, b);
	ft_sort_3_rev(b);
	while (list_size > 2)
	{
	refresh_stack_moove(*a, *b);
	send_correct_number(a, b);

	list_size = lstlast_double(*a)->pos;
	}
	rotate_b(b);
	ft_sort_3(a);
	push_back(b ,a);
	//print_les_stack(*a, *b);
}

void rotate_b(t_stack **b)
{
	t_stack *ptr;
	int i = 0;

	ptr = higher_index_node(*b);
	if (ptr->pos < ptr->invert_pos)
		{
			while (ptr->pos != 0 && i < 50 )
				rb(b);
		}
	else 
	{
		while (ptr->pos != 0 && i < 50 )
				rrb(b);
	}
	
}

t_stack *higher_index_node(t_stack *a)
{
	t_stack *ptr;
	int higher;
	t_stack *ptr_higher_node;

	ptr_higher_node = NULL;

	higher = INT_MIN;
	ptr = a;
	while(ptr)
	{
		if (ptr->index > higher)
		{
			higher = ptr->index;
			ptr_higher_node = ptr;
		}
		ptr = ptr->next;
	}
	return ptr_higher_node;
}