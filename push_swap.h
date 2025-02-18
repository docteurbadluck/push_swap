/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:21:12 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/18 15:24:02 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define T_STACK 1
# define LES_STACKS 2
# define NORMAL_WAY 1
# define INVERT_WAY 0

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				pos;
	int				invert_pos;
	int				index;
	int				dest;
	int				type_of_way_a;
	int				type_of_way_b;
	int				nbr_move;
	int				nbr_move_a;
	int				nbr_move_b;
	struct s_stack	*previous;
	struct s_stack	*next;
}		t_stack;


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

typedef struct s_comparator
{
	t_list		*first_a_card;
	t_list		*first_b_card;
	int			size_a_stack;
	int			size_b_stack;
}	t_comparator;

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
int			ft_swap(t_stack **top);
int			ft_rotate(t_stack **top);
int			ft_reverse_rotate(t_stack **top);
int			ft_push(t_stack **src, t_stack **dest);
void		pa(t_stack **b, t_stack **a);
void	last_pa(t_stack **b, t_stack **a);

//move_2.c
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		ss(t_stack **a, t_stack **b);

//move_3.c
void		rr(t_stack **a, t_stack **b);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);

//sort_1.c
void		ft_which_sort(t_stack **a, t_stack **b);
int			ft_is_sorted(t_stack *a);
void		ft_sort_2(t_stack **a);
void		ft_sort_3(t_stack **a);
void	ft_sort_3_2(t_stack **a, int pos1, int pos2, int pos3);

//sort_2.c
int			ft_sort_4(t_stack **a, t_stack **b);
int			ft_sort_5(t_stack **a, t_stack **b);


// double_linked_list.c

void	lst_push_back_double(t_stack **start, int data);
void list_clear_double(t_stack *start);
t_stack	*lstlast_double(t_stack *lst);
int	lstsize_double(t_stack *lst);
int	ft_how_many_superior_stack(t_stack *a, t_stack *start);

void refresh_pos(t_stack *a);

void sort_full_packet(t_stack **a, t_stack **b);

//	***print_any_list.c***
void	print_any_list(void *list, int type);

//	***init_stack.c
t_stack	*init_a(t_list *arg);
void init_index(t_stack *a);
void refresh_invert_pos(t_stack *a);


//	***algo_utils.c
int higher_index(t_stack *b);
t_stack *get_biggest_node(t_stack *b);
int lower_index(t_stack *b);

//	***calcule_destination.c
int	calcule_destination(t_stack *a, t_stack *b);

//	***choose_sens.c
int	choose_sens(t_stack *a, t_stack *b);
int	choose_sens_a(t_stack *a, t_stack *b);

//	***nbr_moove.c
int	nbr_moove(t_stack *a, t_stack *b);

//	***refresh_stack_moove.c
void	refresh_stack_moove(t_stack *a, t_stack *b);

//	***send_correct_number.c
void send_correct_number(t_stack **a, t_stack **b);

//	***sort_3.c
void	ft_sort_3_rev(t_stack **a);

void	print_les_stack(t_stack *a, t_stack *b );

void rotate_b(t_stack **b);

t_stack *higher_index_node(t_stack *a);

//	***push_back.c
void push_back(t_stack **b ,t_stack **a);






#endif