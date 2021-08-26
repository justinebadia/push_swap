/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:40:46 by jbadia            #+#    #+#             */
/*   Updated: 2021/08/26 15:39:39 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *stack, int nb)
{
	stack->tab[stack->size] = nb;
	stack->size++;
}

int	out(t_stack *stack)
{
	int	nb;

	nb = stack->tab[stack->size - 1];
	stack->size--;
	return (nb);
}

void	ft_do_pa(t_stack *a, t_stack *b)
{
	if (b->size < 1)
		return ;
	ft_push(a, out(b));
	ft_putstr_fd("pa\n", 1);
}

void	ft_do_pb(t_stack *a, t_stack *b)
{
	if (a->size < 1)
		return ;
	ft_push(b, out(a));
	ft_putstr_fd("pb\n", 1);
}
