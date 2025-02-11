/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:21:12 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/11 14:55:36 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_compare
{
	t_list		*first_a_card;
	t_list		*second_a_card;
	t_list		*last_a_card;
	t_list		*first_b_card;
	t_list		*second_b_card;
	t_list		*last_b_card;
	int			size_a_stack;
	int			size_b_stack;
	int			compare_matrice[2][3];
	long long	sum_matrice[3];
}	t_compare;

//input_handler.c
int			ft_check_input(int argc, char **argv, t_list **arg_list);
int			ft_check_input_2(int argc, char **argv, t_list **arg_list);
void		ft_print_error(void);
void		ft_print_content(void *content);
void		ft_lstdel(void *content);

//input_handler_2.c
int			ft_handle_unique_arg(char *str, t_list **arg_list);
int			ft_check_chunk(void *str);
int			ft_flag_sign(char *ptr, int *flag_sign, int *flag_number);
long		ft_atol(const char *str);
void		ft_give_value(long *result, int *sign, int *i);

//input_handler_3.c
t_list		*ft_allocate_check(t_list **lst);
t_list		*ft_lstmanip(t_list *lst, 
				int (*f)(const char *content), void (*del)(void *));
int			ft_check_double(t_list *lst);
t_list		*ft_array_to_lst(char **array_str);

//input_handler_4.c
void		ft_free_array(char **array);
int			ft_only_num(void *content);
int			ft_lstcheck(t_list *lst, int (*f)(void *));
int			ft_count_chunk(void *s);
int			ft_check_sign(char *ptr, int flag_sign);

//move.c
int			ft_swap(t_list **top);
int			ft_rotate(t_list **top);
int			ft_reverse_rotate(t_list **top);
int			ft_push(t_list **src, t_list **dest);
void		pa(t_list **b, t_list **a);

//move_2.c
void		sa(t_list **a);
void		sb(t_list **b);
void		ra(t_list **a);
void		rb(t_list **b);
void		ss(t_list **a, t_list **b);

//move_3.c
void		rr(t_list **a, t_list **b);
void		rra(t_list **a);
void		rrb(t_list **b);
void		rrr(t_list **a, t_list **b);
void		pb(t_list **a, t_list **b);

//sort.c
void		ft_which_sort(t_list **a, t_list **b, t_compare **comparator);
int			ft_is_sorted(t_list *a);
void		ft_sort_2(t_list **a);
void		ft_sort_3(t_list **a);
void		ft_sort_3_2(t_list **a, int *pos1, int *pos2, int *pos3);

//sort_2.c
void		ft_push_back_everything(t_list **a, t_list **b);
void		ft_order_last_card(t_list **a, t_list **b, t_compare **comparator);
void		ft_handle_compare_matrice(t_compare **comparator);
void		ft_handle_compare_matrice_part_1(t_compare **comparator);
void		ft_handle_compare_matrice_part_2(t_compare **comparator);

//sort_3.c
void		ft_sort_full_packet(t_list **a, t_list **b, t_compare **comparator);
t_compare	*ft_init_stack(t_list **a, t_list **b);
t_compare	*ft_new_comparator(t_list *a);
void		ft_maj_comparator(t_list *a, t_list *b,
				t_compare **comparator);
void		ft_send_correct_card(t_list **a, t_list **b,
				t_compare **comparator);

//sort_4.c
void		ft_compare_matrice_sum(t_compare **comparator);
int			ft_which_card(t_compare *comparator);
void		ft_order_b_stack(t_compare **comparator, t_list **b);
int			ft_count_card(t_compare *comparator);
int			ft_best_way(t_compare *comparator);

//sort_5.c
int			ft_sort_4(t_list **a, t_list **b);
int			ft_sort_5(t_list **a, t_list **b);
void		ft_ascend_sort(int nb_carte, int stamp, t_list **b);
void		ft_reverse_sort(int nb_carte_old, t_list **b,
				t_compare **comparator);

#endif