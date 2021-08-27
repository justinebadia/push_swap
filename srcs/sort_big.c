/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:03:30 by jbadia            #+#    #+#             */
/*   Updated: 2021/08/27 15:58:51 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_stack *a, t_stack *b)
{
	int	pivot;

	if (is_sorted(a))
		return ;
	pivot = find_pivot(a);
	sort_a_remove_smaller(a, b, pivot);
	sort_b(a, b);
	sort_a(a, b, is_highest(a));
}

void	sort_a_remove_smaller(t_stack *a, t_stack *b, int pivot)
{
	while (is_smaller(a, pivot))
	{
		while (a->tab[a->size - 1] > pivot)
			ft_do_ra(a);
		ft_do_pb(a, b);
	}
}

void	sort_b(t_stack *a, t_stack *b)
{
	int	higher;
	if (b->size == 0)
		return ;
	higher = is_highest(b);
	sort_b_remove_higher(a, b, find_pivot(b));
	while (top(a) == zero(a) + 1)
		ft_do_ra(a);
	sort_b(a, b);
	sort_a(a, b, higher);
	
}

void	sort_a(t_stack *a, t_stack *b, int highest)
{
	while (top(a) <= highest && top(a) != 0)
	{
		if (a->tab[a->size - 1] == a->tab[0] + 1)
				ft_do_ra(a);
		else
			ft_do_pb(a, b);
		
	}
	if (is_lowest(b) == zero(a) + 1)
		sort_b(a, b);
}

void	sort_b_remove_higher(t_stack *a, t_stack *b, int pivot)
{
	int	i;
	int	highest;

	highest = is_highest(b);
	i = b->size;
	while (i-- > 0)
	{
		if (top(b) == 0 || top(b) == (zero(a) + 1))
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
