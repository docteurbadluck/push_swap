#include "push_swap.h"

void    ft_compare_matrice_sum(t_compare **comparator)
{
    int i;

    (*comparator)->sum_matrice[0] = (*comparator)->compare_matrice[0][0] +
     (*comparator)->compare_matrice[1][0];
    (*comparator)->sum_matrice[1] = (*comparator)->compare_matrice[0][1] +
     (*comparator)->compare_matrice[1][1];
    (*comparator)->sum_matrice[2] = (*comparator)->compare_matrice[0][2] +
     (*comparator)->compare_matrice[1][2];
    i = 0;
    while (i < 3)
    {
        if ((*comparator)->sum_matrice[i] < 0)
            (*comparator)->sum_matrice[i] *= (-1);
        i++;
    }
}

int ft_which_card(t_compare *comparator)
{
    int i;
    long result;

    result = INT64_MAX;
    i = 0;
    while(i < 3)
    {
         if (result > comparator->sum_matrice[i])
            result = comparator->sum_matrice[i];
        i++;
    }
    i = 0;
     while(i < 3)
    {
         if (result == comparator->sum_matrice[i])
            return i;
        i++;
    }
    return -1;
}

void ft_order_b_stack(t_compare **comparator, t_list **b)
{
    int nb_carte;
    int direction;
    int stamp;

    nb_carte = 0;
    direction = 0;
    nb_carte = ft_count_card(*comparator);
    direction = ft_best_way(*comparator);
    stamp = nb_carte;
    if (!nb_carte)
        return ;
    if (nb_carte == 1)
    {
        sb(b);
        return;
    }
    if (nb_carte == ((*comparator)->size_b_stack-1))
    {
        rb(b);
        return;
    }
    if (direction == 1)
        ft_ascend_sort(nb_carte, stamp, b);
    if (direction == 2)
        ft_reverse_sort(nb_carte, b, comparator);
}

int    ft_count_card( t_compare *comparator)
{
    int value;
    t_list *ptr;
    int compteur;

    compteur = 0;
    value = *(int *)comparator->first_b_card->content;
    ptr = comparator -> first_b_card->next;
    while (ptr)
    {  
        if(*(int *)ptr->content > value)
        {
        compteur++;
        ptr = ptr->next;
        }
        else 
            break;
    }
    return compteur;
}

int    ft_best_way( t_compare *comparator)
{
    int value;
    t_list *ptr;
    int compteur;
    int compteur_top;

    compteur = 0;
    value = *(int *)comparator->first_b_card->content;
    ptr = comparator -> first_b_card->next;
     while (ptr)
    {  
        if(*(int *)ptr->content > value)
        {
        compteur++;
        ptr = ptr->next;
        }
        else 
            break;
    }
    compteur_top = comparator->size_b_stack - (compteur);
    if(compteur_top <= (compteur -2))
        return 2;
    else 
    {
        return 1;
    }
}