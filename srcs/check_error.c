/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:56:37 by jbadia            #+#    #+#             */
/*   Updated: 2021/08/26 15:39:20 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(-1);
}

void	ft_check_args(char **argv)
{
	int	i;
	
	i = 0;
		while (argv[i])
		{
			if (ft_atoi_err(argv[i]))
				ft_putstr_error("not digit\n");
				i++;
		}
}

int	ft_atoi_err(const char *str)
{
	int			i;
	long long	nb;
	long long	is_negative;

	is_negative = 1;
	i = 0;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_negative *= -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if (str[i] != 0)
		return (1);
	if ((nb * is_negative) > INT32_MAX || (nb * is_negative) < INT32_MIN)
	{
		ft_putstr_error("Error\n");
		return (1);
	}
	return (0);
}


void	check_duplicate(t_ps *stack)
{
	int	i;
	int j;

	i = 0;
	while (i < stack->a->size)
	{
		j = i + 1;
		while (j <= stack->a->size - 1)
		{
			if (stack->a->tab[i] == stack->a->tab[j])
				ft_putstr_error("Error\n");
			j++;
		}
		i++;
	}
}
