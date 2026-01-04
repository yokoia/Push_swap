/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoia <ykoia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 09:33:34 by ykoia             #+#    #+#             */
/*   Updated: 2026/01/04 09:33:40 by ykoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	sort_two(t_stack **stack)
{
	if ((*stack)->content > (*stack)->next->content)
		ft_swap(stack, 'a');
}

void	sort_three(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack)->next;
	if ((*stack)->content > tmp->content
		&& (*stack)->content > tmp->next->content)
		ft_rotate(stack, 'a');
	else if (tmp->content > (*stack)->content
		&& tmp->content > tmp->next->content)
		ft_rrotate(stack, 'a');
	if ((*stack)->content > (*stack)->next->content)
		ft_swap(stack, 'a');
}

void	sort_four(t_stack **stacka, t_stack **stackb)
{
	int	index;

	index = find_min(stacka);
	if (index < 2)
	{
		while (index > 0)
		{
			ft_rotate(stacka, 'a');
			index--;
		}
	}
	else
	{
		while (index < 4)
		{
			ft_rrotate(stacka, 'a');
			index++;
		}
	}
	ft_push(stacka, stackb, 'b');
	sort_three(stacka);
	ft_push(stackb, stacka, 'a');
}

static void	sort5_helper(t_stack **stacka, t_stack **stackb)
{
	ft_push(stacka, stackb, 'b');
	sort_four(stacka, stackb);
	ft_push(stackb, stacka, 'a');
}

void	sort_five(t_stack **stacka, t_stack **stackb)
{
	int	index;
	int	len;

	len = stack_len(*stacka);
	index = find_min(stacka);
	if (index <= len / 2)
	{
		while (index > 0)
		{
			ft_rotate(stacka, 'a');
			index--;
		}
	}
	else
	{
		while (index < len)
		{
			ft_rrotate(stacka, 'a');
			index++;
		}
	}
	sort5_helper(stacka, stackb);
	if ((*stacka)->content > (*stacka)->next->content)
		ft_swap(stacka, 'a');
}
