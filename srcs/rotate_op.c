#include "push_swap.h"

void	ft_rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	tmp = 0;
	i = 0;
	i = stack->size - 1;
	tmp = stack->tab[i];
	while (i > 0)
	{
		stack->tab[i] = stack->tab[i - 1];
		i--;
	}
	stack->tab[0] = tmp;
}

void	ft_do_ra(t_stack *a)
{
	if (a->size < 2 )
		return ;
	ft_rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	ft_do_rb(t_stack *b)
{
	if (b->size < 2 )
		return ;
	ft_rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	ft_rotate_ab(t_stack *a, t_stack *b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_putstr_fd("rr\n", 1);
}