/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 15:43:31 by jbadia            #+#    #+#             */
/*   Updated: 2021/08/26 15:43:58 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_final(t_stack *a, t_stack *b, int highest_a)
{
	while (top(a) <= highest_a && top(a) != 0)
	{
		if (a->tab[a->size - 1] == a->tab[0] + 1)
			ft_do_ra(a);
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
		ft_do_ra(a);
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