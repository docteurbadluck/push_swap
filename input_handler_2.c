/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:04:16 by tdeliot           #+#    #+#             */
/*   Updated: 2025/01/14 17:51:24 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_handle_unique_arg(char *str, t_list **arg)
{
	char	**array_of_str;
	int		i;

	array_of_str = ft_split(str, ' ');
	i = 0;
	while (array_of_str[i] != NULL)
	{
		if (ft_check_chunk(array_of_str[i]))
		{
			ft_free_array(array_of_str);
			return (1);
		}
		i++;
	}
	ft_lstclear(arg, &ft_lstdel);
	*arg = NULL;
	*arg = ft_array_to_lst(array_of_str);
	ft_free_array(array_of_str);
	return (0);
}

int	ft_check_chunk(void *str)
{
	int		flag_sign;
	int		flag_number;
	char	*ptr;

	ptr = str;
	flag_sign = 0;
	flag_number = 0;
	while (*ptr)
	{
		if (*ptr == '+' || *ptr == '-')
		{
			flag_sign++;
			if (flag_sign > 1)
				return (1);
		}
		if (ft_isdigit(*ptr))
			flag_number++;
		ptr++;
	}
	if (flag_number == 0)
		return (1);
	ptr = str;
	return (ft_check_sign(ptr, flag_sign));
}

static int	ft_isspace(int c)
{
	if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32)
		return (1);
	return (0);
}

void	ft_give_value(long *result, int *sign, int *i)
{
	*result = 0;
	*sign = 1;
	*i = 0;
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	ft_give_value(&result, &sign, &i);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		if (result > 2147483648)
			break ;
		i++;
	}
	result *= sign;
	return (result);
}
