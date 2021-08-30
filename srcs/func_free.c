/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 09:49:07 by jbadia            #+#    #+#             */
/*   Updated: 2021/08/30 09:32:10 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_struct(t_stack *stack)
{
	if (stack)
		free(stack->tab);
	free(stack);
}

void	ft_free_all(t_ps *stack, char **argv, int argc)
{
	ft_free_struct(stack->a);
	ft_free_struct(stack->b);
	ft_free_struct(stack->c);
	ft_free_tab(argv, argc);
}

void	ft_free_tab(char **tab, int argc)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

void	alloc_stack(t_ps *stack, int size, char **argv, int argc)
{
	stack->a = calloc_stack(size);
	stack->b = calloc_stack(size);
	stack->c = calloc_stack(size);
	if (!stack->a || !stack->b || !stack->c)
		ft_free_all(stack, argv, argc);
}
