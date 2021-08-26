/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:47:54 by jbadia            #+#    #+#             */
/*   Updated: 2021/08/26 15:47:22 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>
# include "../Libft/libft.h"


typedef struct s_stack
{
	int	*tab;
	int	size;
}		t_stack;

typedef struct s_ps
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*c;
}		t_ps;

void	ft_putstr_error(char *str);
void	ft_check_args(char **argv);
int		ft_atoi_err(const char *str);
bool 	is_not_digit(char c);
void	check_duplicate(t_ps *stack);

t_ps	*init_struct(t_ps *stack, int argc, char **argv);
int		get_stack_size(int argc, char **argv);
int		tab_size(int *tab);
int		*copy_stack(char **argv, t_stack *stack, int size);

void	ft_swap(t_stack *stack);
void	ft_do_sa(t_stack *a);
void	ft_do_sb(t_stack *b);
void	ft_swap_ab(t_stack *a, t_stack *b);

void	ft_push(t_stack *stack, int nb);
int		out(t_stack *stack);
void	ft_do_pa(t_stack *a, t_stack *b);
void	ft_do_pb(t_stack *a, t_stack *b);

void	ft_rotate(t_stack *stack);
void	ft_do_ra(t_stack *a);
void	ft_do_rb(t_stack *b);
void	ft_rotate_ab(t_stack *a, t_stack *b);

void	ft_reverse(t_stack *stack);
void	ft_do_rra(t_stack *a);
void	ft_do_rrb(t_stack *b);
void	ft_do_rrr(t_stack *a, t_stack *b);

void	sort_2_a(t_stack *stack);
void	sort_3_a(t_stack *stack);
void	sort_5(t_stack *a, t_stack *b);
void 	ra_or_rra(t_stack *stack);

int		*in_order(int *stack, int len);
int		*copy_tab(int *stack, int len);
int		check_order(int *stack, int len);
int		is_highest_small(t_stack *stack);
int		is_lowest_small(t_stack *stack);

void	swap(int *stack, int up, int down);
void	recursive_quicksort(t_stack *stack, int down, int up);
void	quicksort(t_stack *stack);
int		partition(t_stack *stack, int up, int down, int pivot);
void	stack_to_index(t_stack *a, t_stack *b);

void	resolve_small(t_stack *a, t_stack *b);
void	resolve_big(t_stack *a, t_stack *b, t_stack *c);
int		go_to_A(t_stack *a, t_stack *b);

void	sort_big(t_stack *a, t_stack *b);
void	sort_a_remove_smaller(t_stack *a, t_stack *b, int pivot);
void	sort_b_remove_higher(t_stack *a, t_stack *b, int pivot);
void	sort_b(t_stack *a, t_stack *b);
void	sort_a(t_stack *a, t_stack *b, int highest);

void	sort_a_final(t_stack *a, t_stack *b, int highest_a);
void	sort_b_final(t_stack *a, t_stack *b);
int		is_sorted(t_stack *stack);

int		find_pivot(t_stack *stack);
void	rb_or_rrb_big(t_stack *a, t_stack *b, int highest);
int		is_highest(t_stack *stack);
int		is_lowest(t_stack *stack);
int		is_smaller(t_stack *stack, int pivot);

bool	b_is_next(t_stack *a, t_stack *b);
bool	a_is_next(t_stack *a);
int		top(t_stack *stack);
int		zero(t_stack *stack);

void	ft_free_struct(t_stack *stack);
void	ft_free_all(t_ps *stack);
void	free_arr(char **arr);




void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_putstr_fd(char *s, int fd);
int	ft_atoi(const char *str);
int	ft_isdigit(int c);
char	**ft_split(char const *s, char c);
 char	*ft_copyword(char const *s, char c);
 char const	*ft_go_toc(char const *s, char c);
 char const	*ft_skip_c (char const *s, char c);
 int	ft_countwords(char const *s, char c);
 char	*ft_substr(char const *s, unsigned int start, size_t len);
 char	*ft_strdup (const char *s1);

#endif
