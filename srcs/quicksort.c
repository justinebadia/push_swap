/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:06:26 by jbadia            #+#    #+#             */
/*   Updated: 2021/08/25 15:53:50 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *stack, int up, int down)
{
	int	tmp;

	tmp = stack[up];
	stack[up] = stack[down];
	stack[down] = tmp;
}

void	recursive_quicksort(t_stack *stack, int down, int up)
{
	int	index;
	int	pivot;
	pivot = stack->tab[(up + down)/2];
	if (down < up)
	{
		index = partition(stack, down, up, pivot);
		recursive_quicksort(stack, down, index - 1);
		recursive_quicksort(stack, index, up);
	}
}

void	quicksort(t_stack *stack)
{
	int	up;
	int	down;

	up = stack->size - 1;
	down = 0;
	recursive_quicksort(stack, down, up);
}

int	partition(t_stack *stack, int down, int up, int pivot)
{
	// up part d'en bas, donc tout ce qui est plus grand que le pivot doit etre swap
	while (down <= up)
	{
		while (stack->tab[down] < pivot)
			down++;
		while (stack->tab[up] > pivot)
			up--;
		if (down <= up)
		{
			swap(stack->tab, up, down);
			up--;
			down++;
		}
	}
	return (down);
}


void	stack_to_index(t_stack *a, t_stack *c)
{
	int	i;
	int	j;

	i = 0;
	while (i < c->size)
	{
		j = 0;
		while (a->tab[i] != c->tab[j])
			j++;
		if (a->tab[i] == c->tab[j])
			a->tab[i] = j;
		i++;
	}
}