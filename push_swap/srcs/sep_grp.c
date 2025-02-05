/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sep_grp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:38:30 by jchen2            #+#    #+#             */
/*   Updated: 2025/02/02 16:22:37 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	check_part(t_stack **stack_a, long x, long y)
{
	long	count_0;
	long	count_1;
	t_node	*node;

	node = (*stack_a)->top;
	count_0 = 0;
	count_1 = 0;
	while (1)
	{
		if (node->num_index < y && node->num_index >= x)
		{
			if (node->index <= (*stack_a)->size / 2)
				count_0 += node->index;
			else
				count_1 += (*stack_a)->size - node->index;
		}
		node = node->next;
		if (node == (*stack_a)->top)
			break ;
	}
	if (count_0 < count_1)
		return (1);
	return (0);
}

static t_node	*first_met(t_stack	**stack_a, long flag, long x, long y)
{
	t_node	*node;
	t_node	*fix;

	if (flag == 0)
		node = (*stack_a)->top;
	else
		node = (*stack_a)->top->prev;
	fix = node;
	while (1)
	{
		if (node->num_index >= x && node->num_index < y)
			return (node);
		if (flag == 0)
			node = node->next;
		else if (flag == 1)
			node = node->prev;
		if (node == fix)
			break ;
	}
	return (NULL);
}

static void	rp_a_b(t_stack **stack_a, t_stack **stack_b, t_node *n, long flag)
{
	long	r_a;
	t_node	*node;

	node = n;
	r_a = node->index;
	if (!node)
		return ;
	if (flag == 1)
		r_a = (*stack_a)->size - node->index;
	while (r_a--)
	{
		if (flag == 0)
			rotate_ab(stack_a, stack_b, 0);
		else
			rotate_reverse_ab(stack_a, stack_b, 0);
	}
	push_ab(stack_a, stack_b, 1);
}

void	sep_grp(t_stack **stack_a, t_stack **stack_b)
{
	long	i;
	long	rem;
	long	range;
	long	flag;
	long	j;

	range = (*stack_a)->size / 2;
	rem = (*stack_a)->size % 2;
	i = 0;
	while (i < 2)
	{
		flag = check_part(stack_a, i * range, (i + 1) * range);
		j = 0;
		while (j < range)
		{
			rp_a_b(stack_a, stack_b,
				first_met(stack_a, flag, i * range, (i + 1) * range), flag);
			j++;
		}
		i++;
	}
	while (rem--)
		push_ab(stack_a, stack_b, 1);
}
