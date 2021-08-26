/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:05:04 by jbadia            #+#    #+#             */
/*   Updated: 2021/08/26 15:40:28 by jbadia           ###   ########.fr       */
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
	if (check_order(a->tab, a->size))
	 	return ;
	if (a->size == 2)
		sort_2_a(a);
	if (a->size == 3)
		sort_3_a(a);
	if (a->size == 5 || a->size == 4)
		sort_5(a, b);
}

int	go_to_A(t_stack *a, t_stack *b)
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