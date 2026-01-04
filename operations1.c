/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoia <ykoia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 20:59:10 by ykoia             #+#    #+#             */
/*   Updated: 2026/01/03 21:15:58 by ykoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	ft_swap(t_stack **stack, char c)
{
	t_stack	*tmp;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	(*stack) = tmp;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	ft_swap_both(t_stack **stacka, t_stack **stackb)
{
	ft_swap(stacka, 'z');
	ft_swap(stackb, 'z');
	write(1, "ss\n", 3);
}

void	ft_push(t_stack **from, t_stack **to, char c)
{
	t_stack	*tmp;

	if (!from || !(*from))
		return ;
	tmp = (*from)->next;
	(*from)->next = (*to);
	(*to) = (*from);
	(*from) = (tmp);
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}
