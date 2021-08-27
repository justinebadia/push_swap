/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:05:04 by jbadia            #+#    #+#             */
/*   Updated: 2021/08/27 09:38:13 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	resolve_big(t_stack *a, t_stack *b, t_stack *c)
{
	quicksort(c);
	stack_to_index(a, c);
	sort_big(a, b);
}

void	resolve_small(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
	 	return ;
	if (a->size == 2)
		sort_2_a(a);
	if (a->size == 3)
		sort_3_a(a);
	if (a->size == 5 || a->size == 4)
		sort_5(a, b);
}

int	go_to_a(t_stack *a, t_stack *b)
{
	if ((b->tab[b->size - 1] < a->tab[a->size - 1]) &&
		(a->tab[a->size - 1] == is_lowest(a)))
		return (1);
	if ((b->tab[b->size - 1] < a->tab[a->size - 1]) &&
		(b->tab[b->size - 1] > a->tab[0]))
		return (1);
	if ((b->tab[b->size - 1] > is_highest(a)) && (a->tab[a->size - 1] == is_lowest(a)))
		return (1);
	return (0);
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