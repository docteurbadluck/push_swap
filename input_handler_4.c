/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:11:33 by tdeliot           #+#    #+#             */
/*   Updated: 2025/01/14 16:12:56 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

int	ft_only_num(void *content)
{
	int		i;
	char	*str;

	i = 0;
	str = content;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && str[i] != ' '
			&& str[i] != '-' && str[i] != '+')
			return (1);
		i++;
	}
	return (0);
}

int	ft_lstcheck(t_list *lst, int (*f)(void *))
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (f(tmp->content))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_count_chunk(void *s)
{
	int		count;
	int		flag;
	char	*ptr;

	flag = 0;
	count = 0;
	ptr = s;
	while (*ptr)
	{
		if (*ptr == ' ')
			flag = 0;
		if (*ptr != ' ' && flag == 0)
		{
			count++;
			flag = 1;
			if (count > 1)
				return (1);
		}
		ptr++;
	}
	return (0);
}

int	ft_check_sign(char *ptr, int flag_sign)
{
	if (ft_atol(ptr) > INT_MAX || ft_atol(ptr) < INT_MIN)
		return (1);
	if (flag_sign == 1)
	{
		if (ptr[0] == '-' || ptr[0] == '+')
			return (0);
		else
			return (1);
	}
	return (0);
}
