/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse_ab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:10:16 by jchen2            #+#    #+#             */
/*   Updated: 2024/12/29 17:01:48 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rra(t_stack **stack_a)
{
	t_node	*current;
	int		index;

	if ((*stack_a)->top == NULL || (*stack_a)->size < 2)
		return ;
	(*stack_a)->top = (*stack_a)->top->prev;
	(*stack_a)->top->index = 0;
	current = (*stack_a)->top->next;
	index = 1;
	while (current != (*stack_a)->top)
	{
		current->index = index;
		current = current->next;
		index++;
	}
}

static void	rrb(t_stack **stack_b)
{
	t_node	*current;
	int		index;

	if ((*stack_b)->top == NULL || (*stack_b)->size < 2)
		return ;
	(*stack_b)->top = (*stack_b)->top->prev;
	(*stack_b)->top->index = 0;
	current = (*stack_b)->top->next;
	index = 1;
	while (current != (*stack_b)->top)
	{
		current->index = index;
		current = current->next;
		index++;
	}
}

static void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_printf("%s\n", "rrr");
}

void	rotate_reverse_ab(t_stack **stack_a, t_stack **stack_b, int flag)
{
	if (flag == 0)
	{
		rra(stack_a);
		ft_printf("%s\n", "rra");
	}
	else if (flag == 1)
	{
		rrb(stack_b);
		ft_printf("%s\n", "rrb");
	}
	else if (flag == 2)
		rrr(stack_a, stack_b);
}
