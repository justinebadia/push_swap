/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:47:06 by jbadia            #+#    #+#             */
/*   Updated: 2021/08/26 15:40:08 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//ARG=`ruby -e "puts (0..22).to_a.shuffle.join(' ')"`; ./push_swap $ARG
// python3 pyviz.py `ruby -e "puts (0..100).to_a.shuffle.join(' ')"` 

void ft_print_stack(t_stack *s)
{
	int i;

	i = 0;
	printf("-------------\n\n");
	while (i < s->size)	
	{
		printf("stack[%i]:", i);
		printf("%i\n", s->tab[i]);
		i++;
	}
	printf("\n\n-------------");
}


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
	
	int	size;
	argv++;
	if (argc < 2)
		ft_putstr_error("missing arguments");
	if (argc == 2)
		argv = ft_split(argv[0], ' ');
	size = get_stack_size(argc, argv);
	stack.a = calloc_stack(size);
	stack.b = calloc_stack(size);
	stack.c = calloc_stack(size);
	init_struct(&stack, argc, argv);
	if (!stack.a || !stack.b || !stack.c)
		ft_free_all(&stack);
	stack.a->tab = copy_stack(argv, stack.a, size);
	stack.c->tab = copy_stack(argv, stack.c, size);
	check_duplicate(&stack);
	ft_check_args(argv);
	if (size < 6)
		resolve_small(stack.a, stack.b);
	else
		resolve_big(stack.a, stack.b, stack.c);
	ft_free_all(&stack);
	return (0);

}