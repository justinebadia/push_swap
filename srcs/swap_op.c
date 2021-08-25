/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:50:18 by jbadia            #+#    #+#             */
/*   Updated: 2021/08/06 10:54:41 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	int	tmp;

	tmp = 0;
	tmp = stack->tab[stack->size - 1];
	stack->tab[stack->size - 1] = stack->tab[stack->size - 2];
	stack->tab[stack->size - 2] = tmp;
}

void	ft_do_sa(t_stack *a)
{
	if (a->size < 2 )
		return ;
	ft_swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	ft_do_sb(t_stack *b)
{
	if (b->size < 2 )
		return ;
	ft_swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	ft_swap_ab(t_stack *a, t_stack *b)
{
	ft_swap(a);
	ft_swap(b);
	ft_putstr_fd("ss\n", 1);
}
