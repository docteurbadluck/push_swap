/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:10:16 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/12 16:19:21 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_allocate_check(t_list **lst)
{
	t_list	*new;

	new = ft_lstmanip(*lst, &ft_atoi, ft_lstdel);
	ft_lstclear(lst, &ft_lstdel);
	if (ft_check_double(new))
	{
		ft_lstclear(&new, &ft_lstdel);
		ft_print_error();
		new = NULL;
	}
	return (new);
}

t_list	*ft_lstmanip(t_list *lst, int (*f)(const char *content),
		void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_obj;
	void	*content;

	new_list = NULL;
	while (lst)
	{
		content = malloc(sizeof(int));
		if (!content)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		*(int *)content = f(lst->content);
		new_obj = ft_lstnew(content);
		if (!new_obj)
		{
			free(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_obj);
		lst = lst->next;
	}
	return (new_list);
}

int	ft_check_double(t_list *lst)
{
	int		*value;
	int		*comparator;
	t_list	*ptr;
	t_list	*iterator;

	ptr = lst;
	while (ptr->next != NULL)
	{
		value = (int *)(ptr->content);
		iterator = ptr->next;
		while (iterator)
		{
			comparator = (int *)(iterator->content);
			if (*value == *comparator)
			{
				return (1);
			}
			iterator = iterator->next;
		}
		ptr = ptr->next;
	}
	return (0);
}

t_list	*ft_array_to_lst(char **array_str)
{
	t_list	*new;
	int		i;

	new = NULL;
	i = 0;
	while (array_str[i] != NULL)
	{
		ft_lstadd_back(&new, ft_lstnew(ft_strdup(array_str[i])));
		i++;
	}
	return (new);
}
