/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_b_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:17:14 by jchen2            #+#    #+#             */
/*   Updated: 2025/02/02 14:52:33 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rp_b_a(t_stack **stack_a, t_stack **stack_b, t_node *node)
{
	if ((*stack_a)->size < 2)
	{
		push_ab(stack_a, stack_b, 0);
		return ;
	}
	if (node->index <= (*stack_b)->size / 2)
	{
		if ((node->b_node->index) <= (*stack_a)->size / 2)
			ex_same_up_b_a(stack_a, stack_b, node);
		else
			ex_ops_up_b_a(stack_a, stack_b, node);
	}
	else
	{
		if ((node->b_node->index) <= (*stack_a)->size / 2)
			ex_ops_down_b_a(stack_a, stack_b, node);
		else
			ex_same_down_b_a(stack_a, stack_b, node);
	}
}

static t_node	*ministep(t_stack	**stack_b, long x, long y)
{
	t_node	*node;
	t_node	*mini_node;
	long	min_val;

	if (!stack_b || !(*stack_b))
		return (NULL);
	mini_node = (*stack_b)->top;
	node = (*stack_b)->top->next;
	min_val = LONG_MAX;
	while (1)
	{
		if (node->num_index >= x && node->num_index < y)
		{
			if (node->step < min_val)
			{
				min_val = node->step;
				mini_node = node;
			}
		}
		node = node->next;
		if (node == (*stack_b)->top)
			break ;
	}
	return (mini_node);
}

static void	deal_rem(t_stack **stack_a, t_stack **stack_b, long rem)
{
	while (rem--)
		push_ab(stack_a, stack_b, 0);
}

void	p_b_a(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*node;
	long	rem;
	long	range;
	long	j;
	long	g;

	g = 2;
	range = (*stack_b)->size / g;
	rem = (*stack_b)->size % g;
	if (rem > 0)
		deal_rem(stack_a, stack_b, rem);
	while (g--)
	{
		j = 0;
		while (j < range)
		{
			renew_step_node_group(stack_a, stack_b, g * range, (g + 1) * range);
			node = ministep(stack_b, g * range, (g + 1) * range);
			rp_b_a(stack_a, stack_b, node);
			j++;
		}
	}
}
