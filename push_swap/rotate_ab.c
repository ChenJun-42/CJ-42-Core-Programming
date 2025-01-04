/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:03:58 by jchen2            #+#    #+#             */
/*   Updated: 2024/12/29 17:00:51 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ra(t_stack **stack_a)
{
	t_node	*current;
	int		index;

	if ((*stack_a)->top == NULL || (*stack_a)->size < 2)
		return ;
	(*stack_a)->top = (*stack_a)->top->next;
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

static void	rb(t_stack **stack_b)
{
	t_node	*current;
	int		index;

	if ((*stack_b)->top == NULL || (*stack_b)->size < 2)
		return ;
	(*stack_b)->top = (*stack_b)->top->next;
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

static void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_printf("%s\n", "rr");
}

void	rotate_ab(t_stack **stack_a, t_stack **stack_b, int flag)
{
	if (flag == 0)
	{
		ra(stack_a);
		ft_printf("%s\n", "ra");
	}
	else if (flag == 1)
	{
		rb(stack_b);
		ft_printf("%s\n", "rb");
	}
	else if (flag == 2)
		rr(stack_a, stack_b);
}
