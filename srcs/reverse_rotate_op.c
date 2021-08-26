/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 15:40:40 by jbadia            #+#    #+#             */
/*   Updated: 2021/08/26 15:40:42 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse(t_stack *stack)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = 0;
	tmp = stack->tab[i];
	while (i < stack->size - 1)
	{
		stack->tab[i] = stack->tab[i + 1];
		i++;
	}
	stack->tab[stack->size - 1] = tmp;
}

void	ft_do_rra(t_stack *a)
{
	if (a->size < 2 )
		return ;
	ft_reverse(a);
	ft_putstr_fd("rra\n", 1);
}

void	ft_do_rrb(t_stack *b)
{
	if (b->size < 2 )
		return ;
	ft_reverse(b);
	ft_putstr_fd("rrb\n", 1);
}

void	ft_do_rrr(t_stack *a, t_stack *b)
{
	ft_reverse(a);
	ft_reverse(b);
	ft_putstr_fd("rrr\n", 1);
}
