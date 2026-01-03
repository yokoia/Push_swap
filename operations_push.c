#include "push_swap.h"

static void	push(t_stack *dst, t_stack *src)
{
	if (is_empty(src) || is_full(dst))
		return ;
	dst->array[dst->size] = src->array[src->size - 1];
	dst->size++;
	src->size--;
}

void	pa(t_stack *a, t_stack *b, int print)
{
	push(a, b);
	if (print)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *a, t_stack *b, int print)
{
	push(b, a);
	if (print)
		ft_putstr_fd("pb\n", 1);
}
