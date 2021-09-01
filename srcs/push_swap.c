/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:47:06 by jbadia            #+#    #+#             */
/*   Updated: 2021/09/01 12:12:39 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*calloc_stack(int size)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->tab = ft_calloc((size_t)size, sizeof(int));
	if (!stack->tab)
	{
		free(stack);
		return (NULL);
	}
	return (stack);
}

int	get_stack_size(int argc, char **argv)
{
	int		size;

	size = 0;
	if (argc > 2)
		return (argc - 1);
	while (argv[size])
		size++;
	return (size);
}

int	*copy_stack(char **argv, t_stack *stack, int size)
{
	int	i;
	int	j;

	i = size - 1;
	j = 0;
	while (i >= 0)
	{
		stack->tab[j] = ft_atoi(argv[i]);
		i--;
		j++;
	}
	stack->tab[i] = '\0';
	return (stack->tab);
}

t_ps	*init_struct(t_ps *stack, int argc, char **argv)
{
	stack->a->size = get_stack_size(argc, argv);
	stack->b->size = 0;
	stack->c->size = get_stack_size(argc, argv);
	return (stack);
}

int	main(int argc, char **argv)
{
	t_ps	stack;
	int		size;

	argv++;
	if (argc < 2)
		exit(EXIT_FAILURE);
	if (argc == 2)
		argv = ft_split(argv[0], ' ');
	size = get_stack_size(argc, argv);
	alloc_stack(&stack, size, argv, argc);
	init_struct(&stack, argc, argv);
	stack.a->tab = copy_stack(argv, stack.a, size);
	stack.c->tab = copy_stack(argv, stack.c, size);
	if (!check_duplicate(&stack) || !ft_check_args(argv))
	{
		ft_free_all(&stack, argv, argc);
		exit (EXIT_FAILURE);
	}
	if (size < 6)
		resolve_small(stack.a, stack.b);
	else
		resolve_big(stack.a, stack.b, stack.c);
	ft_free_all(&stack, argv, argc);
	return (0);
}
