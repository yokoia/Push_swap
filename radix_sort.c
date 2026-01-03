#include "push_swap.h"

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	i;
	int	j;
	int	size;

	normalize_stack(a);
	max_bits = get_max_bits(a);
	i = 0;
	while (i < max_bits)
	{
		size = a->size;
		j = 0;
		while (j < size)
		{
			if (((a->array[a->size - 1] >> i) & 1) == 0)
				pb(a, b, 1);
			else
				ra(a, 1);
			j++;
		}
		while (b->size > 0)
			pa(a, b, 1);
		i++;
	}
}
