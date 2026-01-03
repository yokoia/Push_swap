#include "push_swap.h"

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static long	ft_atol(const char *str, int *error)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	*error = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
		{
			*error = 1;
			return (0);
		}
		i++;
	}
	return (result * sign);
}

int	ft_atoi(const char *str)
{
	int		error;
	long	result;

	result = ft_atol(str, &error);
	if (error)
		return (0);
	return ((int)result);
}

int	has_duplicates(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->array[i] == stack->array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parse_args(int argc, char **argv, t_stack *a)
{
	int		i;
	int		error;
	long	num;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (0);
		num = ft_atol(argv[i], &error);
		if (error || num > INT_MAX || num < INT_MIN)
			return (0);
		a->array[a->size] = (int)num;
		a->size++;
		i++;
	}
	if (has_duplicates(a))
		return (0);
	return (1);
}
