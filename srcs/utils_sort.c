/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:06:58 by jbadia            #+#    #+#             */
/*   Updated: 2021/08/30 09:47:39 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pivot(t_stack *stack)
{
	int	pivot;
	int	i;

	pivot = 0;
	i = 0;
	while (i < stack->size)
	{
		pivot += stack->tab[i];
		i++;
	}
	pivot = pivot / stack->size;
	return (pivot);
}

int	is_highest(t_stack *stack)
{
	int	i;
	int	high;

	high = stack->tab[0];
	i = 0;
	while (i <= stack->size - 1)
	{
		if (stack->tab[i] > high)
			high = stack->tab[i];
		i++;
	}
	return (high);
}

int	is_lowest(t_stack *stack)
{
	int	i;
	int	low;

	low = stack->tab[0];
	i = 0;
	while (i <= stack->size - 1)
	{
		if (stack->tab[i] < low)
			low = stack->tab[i];
		i++;
	}
	return (low);
}

void	rb_or_rrb_big(t_stack *a, t_stack *b, int highest)
{
	int	i;

	i = 0;
	if (b->tab[b->size - 1] == highest)
	{
		ft_do_pa(a, b);
		return ;
	}
	while (i < b->size)
	{
		if (b->tab[i] == highest)
			break ;
		i++;
	}
	if (i < b->size / 2)
		ft_do_rrb(b);
	else
		ft_do_rb(b);
}

int	is_smaller(t_stack *stack, int pivot)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->tab[i] <= pivot)
			return (1);
		i++;
	}
	return (0);
}
