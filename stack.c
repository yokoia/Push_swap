/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoia <ykoia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 20:59:27 by ykoia             #+#    #+#             */
/*   Updated: 2026/01/03 21:07:55 by ykoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

t_stack	*ft_stack(int ac, char **av)
{
	int		i;
	int		n;
	t_stack	*node;
	t_stack	*new;

	new = NULL;
	i = ac - 1;
	while (i > 0)
	{
		n = ft_atoi(av[i]);
		node = malloc(sizeof(t_stack));
		if (!node)
			return (NULL);
		node->content = n;
		node->next = new;
		new = node;
		i--;
	}
	return (new);
}

int	stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

int	find_min(t_stack **stack)
{
	int		min;
	int		index;
	int		i;
	t_stack	*tmp;

	tmp = *stack;
	min = tmp->content;
	index = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->content < min)
		{
			min = tmp->content;
			index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (index);
}

int	find_max(t_stack **stack)
{
	int		max;
	int		index;
	int		i;
	t_stack	*tmp;

	tmp = *stack;
	max = tmp->content;
	index = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->content > max)
		{
			max = tmp->content;
			index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (index);
}

int	find_position(t_stack *stack, int min, int max)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index >= min && stack->index < max)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}
