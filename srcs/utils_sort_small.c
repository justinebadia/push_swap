/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_small.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 09:46:39 by jbadia            #+#    #+#             */
/*   Updated: 2021/08/30 09:47:24 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(int *stack, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (stack[i] < stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_lowest_small(t_stack *stack)
{
	int	i;
	int	*arr;
	int	low;

	i = 1;
	arr = in_order(stack->tab, stack->size);
	low = arr[0];
	while (i < stack->size - 1)
	{
		if (arr[i] < low)
			low = arr[i];
		i++;
	}
	free(arr);
	return (low);
}

int	is_highest_small(t_stack *stack)
{
	int	i;
	int	*arr;
	int	high;

	i = 1;
	arr = in_order(stack->tab, stack->size);
	high = arr[0];
	while (i < stack->size)
	{
		if (arr[i] > high)
			high = arr[i];
		i++;
	}
	free(arr);
	return (high);
}

int	*in_order(int *stack, int len)
{
	int	*arr;
	int	i;
	int	tmp;

	i = 0;
	arr = copy_tab(stack, len);
	while (i < len - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
		}
		i++;
	}
	return (arr);
}

int	*copy_tab(int *stack, int len)
{
	int	i;
	int	*arr;

	i = 0;
	arr = ft_calloc((size_t)len + 1, sizeof (int));
	if (!arr)
		return (NULL);
	while (i < len)
	{
		arr[i] = stack[i];
		i++;
	}
	return (arr);
}
