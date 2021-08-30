/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:03:08 by jbadia            #+#    #+#             */
/*   Updated: 2021/08/30 09:45:37 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_a(t_stack *stack)
{
	int	i;

	i = stack->size - 1;
	if (stack->tab[i] > stack->tab[i - 1])
		ft_do_sa(stack);
}

void	sort_3_a(t_stack *stack)
{
	int	i;

	i = stack->size - 1;
	if ((stack->tab[0] > stack->tab[1]) && (stack->tab[0] < stack->tab[i])
		&& (stack->tab[i] > stack->tab[1]))
		ft_do_ra(stack);
	else if ((stack->tab[0] > stack->tab[i]) && (stack->tab[0] > stack->tab[1])
		&& (stack->tab[i] > stack->tab[1]))
		ft_do_sa(stack);
	else if ((stack->tab[0] < stack->tab[i]) && (stack->tab[0] < stack->tab[1])
		&& (stack->tab[i] > stack->tab[1]))
	{
		ft_do_sa(stack);
		ft_do_rra(stack);
	}
	else if ((stack->tab[0] < stack->tab[1]) && (stack->tab[0] < stack->tab[i])
		&& (stack->tab[1] > stack->tab[i]))
		ft_do_rra(stack);
	else if ((stack->tab[0] < stack->tab[1]) && (stack->tab[0] > stack->tab[i])
		&& (stack->tab[i] < stack->tab[1]))
	{
		ft_do_sa(stack);
		ft_do_ra(stack);
	}
}

void	sort_5(t_stack *a, t_stack *b)
{
	if (a->size == 4)
		ft_do_pb(a, b);
	if (a->size == 5)
	{
		ft_do_pb(a, b);
		ft_do_pb(a, b);
	}
	sort_3_a(a);
	while (b->size != 0)
	{
		if (go_to_a(a, b) == 1)
			ft_do_pa(a, b);
		else
			ft_do_ra(a);
	}
	while (!(is_sorted(a)))
		ra_or_rra(a);
	if (is_sorted(a))
		return ;
}

void	ra_or_rra(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->tab[i] == is_lowest(stack))
			break ;
		i++;
	}
	if (i <= 2)
		ft_do_rra(stack);
	else if (i > 2)
		ft_do_ra(stack);
}
