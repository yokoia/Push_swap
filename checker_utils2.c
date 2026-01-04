/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoia <ykoia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 09:32:18 by ykoia             #+#    #+#             */
/*   Updated: 2026/01/04 11:32:14 by ykoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	valid_line2(char *line, t_stack **stacka, t_stack **stackb, char **av)
{
	if (ft_strcmp(line, "rra\n") == 0)
		ft_rrotate(stacka, 'z');
	else if (ft_strcmp(line, "rrb\n") == 0)
		ft_rrotate(stackb, 'z');
	else if (ft_strcmp(line, "rrr\n") == 0)
		ft_rrotate_both_bonus(stacka, stackb);
	else if (ft_strcmp(line, "ra\n") == 0)
		ft_rotate(stacka, 'z');
	else if (ft_strcmp(line, "rb\n") == 0)
		ft_rotate(stackb, 'z');
	else if (ft_strcmp(line, "rr\n") == 0)
		ft_rotate_both_bonus(stacka, stackb);
	else
	{
		free_stack(line, stacka, stackb, av);
		write(2, "Error\n", 6);
		exit(1);
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
	if (i == ac - 2)
		free_exit(arr, av, NULL);
	free(arr);
}

int	is_sorted(t_stack **stacka)
{
	t_stack	*tmp;

	tmp = (*stacka);
	while (tmp && tmp->next && tmp->content < tmp->next->content)
	{
		tmp = tmp->next;
	}
	if (tmp->next == NULL)
		return (1);
	return (0);
}

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
