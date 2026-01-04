/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoia <ykoia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 20:58:41 by ykoia             #+#    #+#             */
/*   Updated: 2026/01/04 11:31:42 by ykoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	ok_ko(t_stack **stacka, t_stack **stackb, char **av)
{
	if ((*stackb))
	{
		free_stack(NULL, stacka, stackb, av);
		write(1, "KO\n", 3);
		exit(1);
	}
	if (is_sorted(stacka) == 1)
	{
		write(1, "OK\n", 3);
		free_exit(NULL, av, stacka);
	}
	else
	{
		write(1, "KO\n", 3);
		free_exit(NULL, av, stacka);
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_swap_both_bonus(t_stack **stacka, t_stack **stackb)
{
	ft_swap(stacka, 'z');
	ft_swap(stackb, 'z');
}

void	ft_rotate_both_bonus(t_stack **stacka, t_stack **stackb)
{
	ft_rotate(stacka, 'z');
	ft_rotate(stackb, 'z');
}

void	ft_rrotate_both_bonus(t_stack **stacka, t_stack **stackb)
{
	ft_rrotate(stacka, 'z');
	ft_rrotate(stackb, 'z');
}
