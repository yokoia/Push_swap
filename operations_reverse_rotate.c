#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return ;
	tmp = stack->array[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[stack->size - 1] = tmp;
}

void	rra(t_stack *a, int print)
{
	reverse_rotate(a);
	if (print)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *b, int print)
{
	reverse_rotate(b);
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *a, t_stack *b, int print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print)
		ft_putstr_fd("rrr\n", 1);
}
