/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 09:49:07 by jbadia            #+#    #+#             */
/*   Updated: 2021/08/27 15:29:07 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_struct(t_stack *stack)
{
	if (stack)
		free(stack->tab);
	free(stack);
}

void	ft_free_all(t_ps *stack, char ** argv, int argc)
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