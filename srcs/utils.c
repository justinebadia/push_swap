/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:22:10 by jbadia            #+#    #+#             */
/*   Updated: 2021/08/30 09:48:07 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	top(t_stack *stack)
{
	return (stack->tab[stack->size - 1]);
}

int	zero(t_stack *stack)
{
	return (stack->tab[0]);
}
