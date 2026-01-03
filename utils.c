#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = stack->size - 1;
	while (i > 0)
	{
		if (stack->array[i] > stack->array[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int	find_min_index(t_stack *stack)
{
	int	i;
	int	min_index;
	int	min_value;

	min_index = stack->size - 1;
	min_value = stack->array[min_index];
	i = stack->size - 2;
	while (i >= 0)
	{
		if (stack->array[i] < min_value)
		{
			min_value = stack->array[i];
			min_index = i;
		}
		i--;
	}
	return (min_index);
}

int	get_max_bits(t_stack *stack)
{
	int	max;
	int	bits;
	int	i;

	max = stack->array[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->array[i] > max)
			max = stack->array[i];
		i++;
	}
	bits = 0;
	while (max > 0)
	{
		max >>= 1;
		bits++;
	}
	return (bits);
}

void	normalize_stack(t_stack *stack)
{
	int	*sorted;
	int	i;
	int	j;

	sorted = (int *)malloc(sizeof(int) * stack->size);
	if (!sorted)
	{
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	i = 0;
	while (i < stack->size)
	{
		sorted[i] = stack->array[i];
		i++;
	}
	i = 0;
	while (i < stack->size - 1)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (sorted[i] > sorted[j])
			{
				int tmp = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = tmp;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < stack->size)
	{
		j = 0;
		while (j < stack->size)
		{
			if (stack->array[i] == sorted[j])
			{
				stack->array[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(sorted);
}
