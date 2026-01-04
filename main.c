/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoia <ykoia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 20:58:22 by ykoia             #+#    #+#             */
/*   Updated: 2026/01/04 13:00:34 by ykoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	free_exit(int *arr, char **strs, t_stack **stack)
{
	int		count;
	t_stack	*tmp;

	free(arr);
	count = ft_strslen(strs);
	free_split(strs, count);
	if (stack)
	{
		while ((*stack))
		{
			tmp = (*stack)->next;
			free((*stack));
			(*stack) = tmp;
		}
	}
	exit(0);
}

void	choose_algo(t_stack **a, t_stack **b)
{
	int	len;
	int	chunk_size;

	len = stack_len(*a);
	if (len == 1)
		return ;
	else if (len == 2)
		sort_two(a);
	else if (len == 3)
		sort_three(a);
	else if (len == 4)
		sort_four(a, b);
	else if (len == 5)
		sort_five(a, b);
	else
	{
		if (len <= 100)
			chunk_size = 15;
		else
			chunk_size = 35;
		sort_all(a, b, chunk_size);
	}
}

void	already_sorted(int ac, char **av)
{
	int	i;
	int	j;
	int	*arr;

	i = 0;
	arr = ft_array(ac, av);
	j = i + 1;
	while (arr[i] < arr[j] && i < ac - 2)
	{
		i++;
		j = i + 1;
	}
	if (i == ac - 2 && ac > 2)
		free_exit(arr, av, NULL);
	free(arr);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*avjoin;

	check_empty2(ac, av);
	avjoin = ft_avjoin(ac, av);
	av = ft_split(avjoin, ' ');
	ac = ft_strslen(av);
	free(avjoin);
	already_sorted(ac, av);
	all_err(ac, av);
	dup_err(ac, av);
	a = ft_stack(ac, av);
	b = NULL;
	ft_indexing(ac, av, a);
	choose_algo(&a, &b);
	free_exit(NULL, av, &a);
	return (0);
}
