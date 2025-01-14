#include "push_swap.h"



int main(int argc, char **argv)
{
    t_list *arg;
    t_list *b;
    t_compare *comparator;
    t_list *a;

    arg = NULL;
    b = NULL;
    comparator = NULL;
    a = NULL;
    if (!ft_check_input(argc, argv, &arg))
        return 1;
    a = ft_allocate_check(&arg);
    if (a)
    {
        ft_which_sort(&a, &b, &comparator);
        ft_lstclear(&a, &ft_lstdel);
        if (b)
            ft_lstclear(&b, &ft_lstdel);
        if (comparator)
            free(comparator);
    }
    return 0;
}


void    ft_which_sort(t_list **a, t_list **b, t_compare **comparator)
{
        if (ft_is_sorted(*a))
            return ;
        if (ft_lstsize(*a) == 2)
            ft_sort_2(a);
        if (ft_lstsize(*a) == 3)
            ft_sort_3(a);
        if (ft_lstsize(*a) == 4)
            ft_sort_4(a, b);
        if (ft_lstsize(*a) == 5)
            ft_sort_5(a, b);
        if (ft_lstsize(*a) >= 6)
            ft_sort_full_packet(a, b, comparator);
}