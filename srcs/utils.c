/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:22:10 by jbadia            #+#    #+#             */
/*   Updated: 2021/08/27 09:56:03 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	top(t_stack *stack)
{
	return(stack->tab[stack->size - 1]);
}

int	zero(t_stack *stack)
{
	return (stack->tab[0]);
}