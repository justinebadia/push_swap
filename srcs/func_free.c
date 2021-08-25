/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 09:49:07 by jbadia            #+#    #+#             */
/*   Updated: 2021/08/25 14:22:57 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_struct(t_stack *stack)
{
	if (stack)
		free(stack->tab);
	free(stack);
}

void	ft_free_all(t_ps *stack)
{
	ft_free_struct(stack->a);
	ft_free_struct(stack->b);
	ft_free_struct(stack->c);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}