/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:07:20 by tdeliot           #+#    #+#             */
/*   Updated: 2025/01/14 17:35:54 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_input(int argc, char **argv, t_list **arg_list)
{
	int	i;

	i = 1;
	if (argc < 2)
	{
		ft_print_error();
		return (0);
	}
	while (i < argc)
	{
		ft_lstadd_back(arg_list, ft_lstnew(ft_strdup(argv[i])));
		i++;
	}
	if (!ft_lstcheck(*arg_list, &ft_only_num))
	{
		ft_lstclear(arg_list, &ft_lstdel);
		ft_print_error();
		return (0);
	}
	if (!ft_check_input_2(argc, argv, arg_list))
		return (0);
	return (1);
}

int	ft_check_input_2(int argc, char **argv, t_list **arg_list)
{
	if (argc > 2 && (!ft_lstcheck(*arg_list, &ft_check_chunk)
			|| !ft_lstcheck(*arg_list, &ft_count_chunk)))
	{
		ft_lstclear(arg_list, &ft_lstdel);
		ft_print_error();
		return (0);
	}
	if (argc == 2)
	{
		if (*argv[1] == '\0')
		{
			ft_lstclear(arg_list, &ft_lstdel);
			ft_print_error();
			return 0;
		}
		if (ft_handle_unique_arg(argv[1], arg_list))
		{
			ft_lstclear(arg_list, &ft_lstdel);
			ft_print_error();
			return (0);
		}
	}
	return (1);
}

void	ft_print_error(void)
{
	ft_putstr_fd("Error\n", 2);
}

void	ft_print_content(void *content)
{
	int	*ptr;

	ptr = content;
	ft_printf("%d\n", *ptr);
}

void	ft_lstdel(void *content)
{
	free(content);
}
