/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:33:07 by jchen2            #+#    #+#             */
/*   Updated: 2025/02/02 14:57:16 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_more(t_stack **stack_a, t_stack **stack_b)
{
	long	size;

	push_ab(stack_a, stack_b, 1);
	push_ab(stack_a, stack_b, 1);
	size = (*stack_a)->size;
	while (size > 3)
	{
		renew_step_node(stack_a, stack_b);
		a_to_b(stack_a, stack_b);
		size--;
	}
	sort_three_node(stack_a, stack_b);
	b_to_a(stack_a, stack_b);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->size == 1)
		return ;
	if ((*stack_a)->size == 2)
		if ((*stack_a)->top->num > (*stack_a)->top->next->num)
			rotate_ab(stack_a, stack_b, 0);
	if ((*stack_a)->size == 3)
		sort_three_node(stack_a, stack_b);
	if ((*stack_a)->size == 4)
		sort_four_node(stack_a, stack_b);
	if ((*stack_a)->size == 5)
		sort_five_node(stack_a, stack_b);
	if ((*stack_a)->size > 5 && (*stack_a)->size < 300)
		sort_more(stack_a, stack_b);
	if ((*stack_a)->size >= 300)
	{
		sep_grp(stack_a, stack_b);
		p_b_a(stack_a, stack_b);
		rotate_min_top(stack_a, stack_b);
	}
}
