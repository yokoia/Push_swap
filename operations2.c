/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoia <ykoia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 20:59:12 by ykoia             #+#    #+#             */
/*   Updated: 2026/01/03 21:06:37 by ykoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	ft_rotate(t_stack **stack, char c)
{
	t_stack	*tmp;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	tmp = (*stack);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*stack);
	tmp = (*stack)->next;
	(*stack)->next = NULL;
	(*stack) = tmp;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	ft_rotate_both(t_stack **stacka, t_stack **stackb)
{
	ft_rotate(stacka, 'z');
	ft_rotate(stackb, 'z');
	write(1, "rr\n", 1);
}

void	ft_rrotate(t_stack **stack, char c)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	tmp = (*stack);
	tmp1 = (*stack);
	while (tmp1->next->next)
		tmp1 = tmp1->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*stack);
	tmp1->next = NULL;
	(*stack) = tmp;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}

void	ft_rrotate_both(t_stack **stacka, t_stack **stackb)
{
	ft_rrotate(stacka, 'z');
	ft_rrotate(stackb, 'z');
	write(1, "rrr\n", 4);
}
