/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:34:37 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/12 15:46:45 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack* ft_create_elem_double_linked(int data)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = data;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}


void push_front_double_linked(t_stack **start, int data)
{
	t_stack *new;

	new = ft_create_elem_double_linked(data);
	if (new == NULL)
	{
		ft_printf("error create_elem");
		return ;
	}  
	if (*start != NULL)
		(*start)->previous = new;
	new->next = *start;
	*start = new;
}


int	lstsize_double(t_stack *lst)
{
	int		i;
	t_stack	*tmp;

	tmp = lst;
	i = 0;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_stack	*lstlast_double(t_stack *lst)
{
	t_stack	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while ((tmp->next))
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void lst_push_back_double(t_stack **start, int data)
{
	t_stack *new;
	t_stack *last;
	new = ft_create_elem_double_linked(data);
	if (!new)
		return ;
	if (!(*start))
	{
		*start = new;
		return ;
	}
	last = lstlast_double(*start);
	last->next = new;
	new ->previous = last;
}


void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!del || !lst || !*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone((*lst), del);
		*lst = temp;
	}
	*lst = NULL;
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}


void list_clear_double(t_stack *start)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = start;
	if (!start)
		return;
	while (temp)
	{
		temp2 = temp->next;
		free(temp);
		temp = temp2;
	}
}

