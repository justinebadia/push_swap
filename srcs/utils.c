/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:22:10 by jbadia            #+#    #+#             */
/*   Updated: 2021/08/25 16:32:07 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	b_is_next(t_stack *a, t_stack *b)
{
	return (top(b) == 0 || top(b) == (zero(a) + 1));
}

bool	a_is_next(t_stack *a)
{
	return (top(a) == 0 || top(a) == zero(a) + 1);
}

int	top(t_stack *stack)
{
	return(stack->tab[stack->size - 1]);
}

int	zero(t_stack *stack)
{
	return (stack->tab[0]);
}