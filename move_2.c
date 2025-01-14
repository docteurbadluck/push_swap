#include "push_swap.h"

void sa(t_list **a)
{
    ft_swap(a);
    ft_printf("sa\t");
}

void sb(t_list **b)
{
    ft_swap(b);
    ft_printf("sb\t");
}

void ra(t_list **a)         //optionnell print ? 
{
    ft_rotate(a);
    ft_printf("ra\t");
}

void rb(t_list **b)
{
    ft_rotate(b);
    ft_printf("rb\t");
}

void ss(t_list **a, t_list **b)
{
   ft_swap(a); 
   ft_swap(b);
   ft_printf("ss\t");
}