/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:03:30 by jbadia            #+#    #+#             */
/*   Updated: 2021/08/26 14:25:38 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack);


void	sort_big(t_stack *a, t_stack *b)
{
	int	pivot;

	if (is_sorted(a))
		return ;
	pivot = find_pivot(a);
	sort_a_remove_smaller(a, b, pivot);
	sort_b(a, b);
	sort_a_final(a, b, is_highest(a));
	//printf("\nfin du sort BIG\n");
	
}

void	sort_a_final(t_stack *a, t_stack *b, int highest_a)
{
	// if (is_sorted(a))
	// 	return ;
	while (top(a) <= highest_a && top(a) != 0)
	{
		//printf("je suis dans le final A\n");
		if (a->tab[a->size - 1] == a->tab[0] + 1)
		{
			//printf("RA DU SORT FINAL \n");
			ft_do_ra(a);
		}
		else 
			ft_do_pb(a, b);
	}
	if (is_lowest(b) == zero(a) + 1)
		sort_b_final(a, b);

}

void	sort_b_final(t_stack *a, t_stack *b)
{
	int	higher;
	
	if (b->size == 0)
		return ;
	higher = is_highest(b);
	sort_b_remove_higher(a, b, find_pivot(b));
	while (top(a) == zero(a) + 1)
	{
		//printf("RA MARCHE PAS");
		ft_do_ra(a);
	}
	sort_b_final(a, b);
	sort_a_final(a, b, higher);
}

int	is_sorted(t_stack *stack)
{
	int	i;
	int	prev;

	i = 1;
	prev = stack->tab[0];
	while (i < stack->size)
	{
		if (stack->tab[i] > prev)
			return (0);
		prev = stack->tab[i];
		i++;
	}
	return (1);
}
/*
	Tant stack->s_a > pivot 	
		do_ra(stack)
	push_b(stack)*/
void	sort_a_remove_smaller(t_stack *a, t_stack *b, int pivot)
{
	//printf("PIVOT =%d", pivot);
	while (is_smaller(a, pivot))
	{
		while (a->tab[a->size - 1] > pivot)
			ft_do_ra(a);
		ft_do_pb(a, b);
	}
}

/*sort b tant que size_b != 0*/
void	sort_b(t_stack *a, t_stack *b)
{
	int	higher;
	//printf("je suis dans sort b\n");
	if (b->size == 0)
		return ;
	higher = is_highest(b);
	//printf("PLUS GRAND %d\n", higher);
	sort_b_remove_higher(a, b, find_pivot(b));
	while (a_is_next(a))
		ft_do_ra(a);
	sort_b(a, b);
	sort_a(a, b, higher);
	
}
/* sort_a qui renvoit tout ce qui est plus petit dans B
si c'est le chiffre suivant on fait pa et ra
Puis s'il est plus petit on le push dans B*/
void	sort_a(t_stack *a, t_stack *b, int highest)
{
	//printf("je suis dans sort A mais je fais rien\n");
	while (top(a) <= highest && top(a) != 0)
	{
		if (a_is_next(a))
			{
				ft_do_ra(a);
				//printf("DANS SORT A test ra \n");
			}
		else
		{
			ft_do_pb(a, b);
			//printf("DANS SORT A test pb \n");
		}
	}
	if (is_lowest(b) == zero(a) + 1)
		sort_b(a, b);
}

// int	bigger_pivot(t_stack *stack, int pivot)
// {
// 	int	i;

// 	i = 0;
// 	while (i < stack->size_b)
// 	{
// 		if (stack->s_b[i] > pivot)
// 			return (1);
// 		i++;
// 	}
// 	return(0);
// }

void	sort_b_remove_higher(t_stack *a, t_stack *b, int pivot)
{
	int	i;
	int	highest;

//printf("PIVOT DE B : %d\n", pivot);
	highest = is_highest(b);
	i = b->size;
	while (i-- > 0)
	{
		if (b_is_next(a, b))
		{
			ft_do_pa(a, b);
			ft_do_ra(a);
		}
		else if (b->size < 13)
			rb_or_rrb_big(a, b, highest);
		else if (pivot <= b->tab[b->size - 1])
			ft_do_pa(a, b);
		else
			ft_do_rb(b);
	}
}
