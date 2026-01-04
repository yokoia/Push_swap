/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoia <ykoia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 20:58:44 by ykoia             #+#    #+#             */
/*   Updated: 2026/01/04 11:31:06 by ykoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	free_stack(char *line, t_stack **stacka, t_stack **stackb, char **strs)
{
	t_stack	*tmp;
	int		count;

	count = ft_strslen(strs);
	free_split(strs, count);
	free(line);
	if (stacka)
	{
		while ((*stacka))
		{
			tmp = (*stacka)->next;
			free((*stacka));
			(*stacka) = tmp;
		}
	}
	if (stackb)
	{
		while ((*stackb))
		{
			tmp = (*stackb)->next;
			free((*stackb));
			(*stackb) = tmp;
		}
	}
}

void	valid_line1(char *line, t_stack **stacka, t_stack **stackb, char **av)
{
	if (ft_strcmp(line, "sa\n") == 0)
		ft_swap(stacka, 'z');
	else if (ft_strcmp(line, "sb\n") == 0)
		ft_swap(stackb, 'z');
	else if (ft_strcmp(line, "ss\n") == 0)
		ft_swap_both_bonus(stacka, stackb);
	else if (ft_strcmp(line, "pa\n") == 0)
		ft_push(stackb, stacka, 'z');
	else if (ft_strcmp(line, "pb\n") == 0)
		ft_push(stacka, stackb, 'z');
	else
		valid_line2(line, stacka, stackb, av);
}

void	ft_read_check(t_stack **stacka, t_stack **stackb, char **av)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		valid_line1(line, stacka, stackb, av);
		free(line);
		line = get_next_line(0);
	}
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
	all_err(ac, av);
	dup_err(ac, av);
	a = ft_stack(ac, av);
	b = NULL;
	ft_indexing(ac, av, a);
	ft_read_check(&a, &b, av);
	ok_ko(&a, &b, av);
	return (0);
}
