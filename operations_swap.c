#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->array[stack->size - 1];
	stack->array[stack->size - 1] = stack->array[stack->size - 2];
	stack->array[stack->size - 2] = tmp;
}

void	sa(t_stack *a, int print)
{
	swap(a);
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *b, int print)
{
	swap(b);
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *a, t_stack *b, int print)
{
	swap(a);
	swap(b);
	if (print)
		ft_putstr_fd("ss\n", 1);
}
