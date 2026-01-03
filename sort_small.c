#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	if (a->size != 3)
		return ;
	top = a->array[a->size - 1];
	mid = a->array[a->size - 2];
	bot = a->array[a->size - 3];
	if (top > mid && mid < bot && top < bot)
		sa(a, 1);
	else if (top > mid && mid > bot && top > bot)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a, 1);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a, 1);
}

void	sort_small(t_stack *a, t_stack *b)
{
	int	min_index;
	int	size;

	if (a->size == 2)
	{
		if (a->array[1] > a->array[0])
			sa(a, 1);
		return ;
	}
	if (a->size == 3)
	{
		sort_three(a);
		return ;
	}
	while (a->size > 3)
	{
		size = a->size;
		min_index = find_min_index(a);
		if (min_index > size / 2)
		{
			while (min_index < size - 1)
			{
				ra(a, 1);
				min_index++;
			}
			ra(a, 1);
		}
		else
		{
			while (min_index > 0)
			{
				rra(a, 1);
				min_index--;
			}
		}
		pb(a, b, 1);
	}
	sort_three(a);
	while (b->size > 0)
		pa(a, b, 1);
}
