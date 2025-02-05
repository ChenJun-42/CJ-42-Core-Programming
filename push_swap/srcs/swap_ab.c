/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:35:31 by jchen2            #+#    #+#             */
/*   Updated: 2024/12/30 18:37:19 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a)
{
	t_node	*node_a_1;
	t_node	*node_a_2;

	if ((*stack_a)->top == NULL || (*stack_a)->size == 1)
		return ;
	node_a_1 = (*stack_a)->top;
	node_a_2 = node_a_1->next;
	node_a_1->next = node_a_2->next;
	node_a_2->next->prev = node_a_1;
	node_a_2->next = node_a_1;
	node_a_1->prev->next = node_a_2;
	node_a_2->prev = node_a_1->prev;
	node_a_1->prev = node_a_2;
	(*stack_a)->top = node_a_2;
	node_a_1->index = 1;
	node_a_2->index = 0;
}

static void	sb(t_stack **stack_b)
{
	t_node	*node_b_1;
	t_node	*node_b_2;

	if ((*stack_b)->top == NULL || (*stack_b)->size == 1)
		return ;
	node_b_1 = (*stack_b)->top;
	node_b_2 = node_b_1->next;
	node_b_1->next = node_b_2->next;
	node_b_2->next->prev = node_b_1;
	node_b_2->next = node_b_1;
	node_b_1->prev->next = node_b_2;
	node_b_2->prev = node_b_1->prev;
	node_b_1->prev = node_b_2;
	(*stack_b)->top = node_b_2;
	node_b_1->index = 1;
	node_b_2->index = 0;
}

static void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("%s\n", "ss");
}

void	swap_ab(t_stack **stack_a, t_stack **stack_b, int flag)
{
	if (flag == 0)
	{
		sa(stack_a);
		ft_printf("%s\n", "sa");
	}
	else if (flag == 1)
	{
		sb(stack_b);
		ft_printf("%s\n", "sb");
	}
	else if (flag == 2)
		ss(stack_a, stack_b);
}
