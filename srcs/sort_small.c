/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 12:03:08 by jbadia            #+#    #+#             */
/*   Updated: 2021/08/25 15:44:58 by jbadia           ###   ########.fr       */
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
	if ((stack->tab[0] > stack->tab[1]) && (stack->tab[0] < stack->tab[2])
		&& (stack->tab[2] > stack->tab[1]))
		ft_do_ra(stack);
	else if ((stack->tab[0] > stack->tab[i]) && (stack->tab[0] > stack->tab[i - 1])
	&& (stack->tab[i] > stack->tab[i - 1]))
		ft_do_sa(stack); 
	else if ((stack->tab[0] < stack->tab[i]) && (stack->tab[0] < stack->tab[i - 1])
	&& (stack->tab[i] > stack->tab[i - 1]))
	{
		ft_do_sa(stack);
		ft_do_rra(stack); 
	}
	else if ((stack->tab[0] < stack->tab[i - 1]) && (stack->tab[0] < stack->tab[i])
	&& (stack->tab[i - 1] > stack->tab[i]))
		ft_do_rra(stack); 
	else if ((stack->tab[0] < stack->tab[i - 1]) && (stack->tab[0] > stack->tab[i])
	&& (stack->tab[i] < stack->tab[i - 1]))
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
		 if (go_to_A(a, b) == 1)
		 	ft_do_pa(a, b);
		else
			ft_do_ra(a);
	 }
	 while (!(check_order(a->tab, a->size)))
	 	ra_or_rra(a);
	if (check_order(a->tab, a->size))
		return ;
 }

void ra_or_rra(t_stack *stack)
{
	int	*arr;
	int	i;

	i = 0;
	arr = copy_tab(stack->tab, stack->size);
	while (i < stack->size)
	{
		if (arr[i] == is_lowest(stack))
			break ;
		i++;
	}
	if (i <= 2)
		ft_do_rra(stack);
	else if (i > 2)
		ft_do_ra(stack);
	free(arr);
}