/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:58:32 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/04 15:24:35 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ex_same_up(t_stack **stack_a, t_stack **stack_b, t_node *node)
{
	long	mini_rot;
	long	re_rot;
	
	if (node->index < (node->b_node->index))
	{
		mini_rot = node->index;
		re_rot = node->b_node->index - mini_rot;
		while (mini_rot--)
			rotate_ab(stack_a, stack_b, 2);
		while (re_rot--)
			rotate_ab(stack_a, stack_b, 1);
		push_ab(stack_a, stack_b, 1);
	}
	else
	{
		mini_rot = (node->b_node->index);
		re_rot = node->index - mini_rot;
		while (mini_rot--)
			rotate_ab(stack_a, stack_b, 2);
		while (re_rot--)
			rotate_ab(stack_a, stack_b, 0);
		push_ab(stack_a, stack_b, 1);
	}
}

static void	ex_same_down(t_stack **stack_a, t_stack **stack_b, t_node *node)
{
	long	mini_rot;
	long	re_rot;

	if ((*stack_a)->size - node->index < ((*stack_b)->size - node->b_node->index))
	{
		mini_rot = (*stack_a)->size - node->index;
		re_rot = ((*stack_b)->size - node->b_node->index) - ((*stack_a)->size - node->index);
		while (mini_rot--)
			rotate_reverse_ab(stack_a, stack_b, 2);
		while (re_rot--)
			rotate_reverse_ab(stack_a, stack_b, 1);
		push_ab(stack_a, stack_b, 1);
	}
	else
	{
		mini_rot = (*stack_b)->size - node->b_node->index;
		re_rot = (*stack_a)->size - node->index - ((*stack_b)->size - node->b_node->index);
		while (mini_rot--)
			rotate_reverse_ab(stack_a, stack_b, 2);
		while (re_rot--)
			rotate_reverse_ab(stack_a, stack_b, 0);
		push_ab(stack_a, stack_b, 1);
	}
}

static void	ex_ops_up(t_stack **stack_a, t_stack **stack_b, t_node *node)
{
	long	rot_a;
	long	rot_b;
	long	rrot_b;

	rot_a = node->index;
	rot_b = (*stack_b)->size - node->b_node->index;
	rrot_b = (*stack_b)->size - (rot_a + rot_b);
	if (rrot_b < rot_b && rrot_b > 0)
	{
		while (rot_a--)
			rotate_ab(stack_a, stack_b, 2);
		while (rrot_b--)
			rotate_ab(stack_a, stack_b, 1);
		push_ab(stack_a, stack_b, 1);
	}
	else
	{
		while (rot_a--)
			rotate_ab(stack_a, stack_b, 0);
		while (rot_b--)
			rotate_reverse_ab(stack_a, stack_b, 1);
		push_ab(stack_a, stack_b, 1);
	}
}

static void	ex_ops_down(t_stack **stack_a, t_stack **stack_b, t_node *node)
{
	long	rot_a;
	long	rot_b;
	long	rrot_b;

	rot_a = (*stack_a)->size - node->index;
	rot_b = node->b_node->index;
	rrot_b = (*stack_b)->size - (rot_a + rot_b);
	if (rrot_b < rot_b && rrot_b > 0)
	{
		while (rot_a--)
			rotate_reverse_ab(stack_a, stack_b, 2);
		while (rrot_b--)
			rotate_ab(stack_a, stack_b, 1);
		push_ab(stack_a, stack_b, 1);
	}
	else
	{
		while (rot_a--)
			rotate_reverse_ab(stack_a, stack_b, 0);
		while (rot_b--)
			rotate_ab(stack_a, stack_b, 1);
		push_ab(stack_a, stack_b, 1);
	}
}

void	a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*node;

	node = find_ministep(stack_a);
	if (node->index <= (*stack_a)->size / 2)
	{
		if ((node->b_node->index) <= (*stack_b)->size / 2)
			ex_same_up(stack_a, stack_b, node);
		else
			ex_ops_up(stack_a, stack_b, node);
	}
	else
	{
		if ((node->b_node->index) <= (*stack_b)->size / 2)
			ex_ops_down(stack_a, stack_b, node);
		else
			ex_same_down(stack_a, stack_b, node);
	}
}
