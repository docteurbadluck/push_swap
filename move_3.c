#include "push_swap.h"

void rr(t_list **a, t_list **b)
{
    ft_rotate(a);
    ft_rotate(b);
    ft_printf("rr\t");
}

void rra(t_list **a)
{
    ft_reverse_rotate(a);
    ft_printf("rra\t");
}

void rrb(t_list **b)
{
    ft_reverse_rotate(b);
    ft_printf("rrb\t");
}

void rrr(t_list **a, t_list **b)
{
    ft_reverse_rotate(a);
    ft_reverse_rotate(b);
    ft_printf("rrr\t");
}

void pb(t_list **a, t_list **b)
{
    ft_push(a, b);
    ft_printf("pb\t");
}
