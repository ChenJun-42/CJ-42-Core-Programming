/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:04:38 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/01 20:41:04 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*detach_top(t_stack **stack)
{
	t_node	*temp;
	t_node	*tail;

	if ((*stack)->top == NULL)
		return (NULL);
	temp = (*stack)->top;
	if ((*stack)->top->next == (*stack)->top)
		(*stack)->top = NULL;
	else
	{
		tail = (*stack)->top->prev;
		tail->next = (*stack)->top->next;
		(*stack)->top = (*stack)->top->next;
		(*stack)->top->prev = tail;
	}
	(*stack)->size--;
	return (temp);
}

static void	attach_top(t_stack **stack, t_node *node)
{
	t_node	*tail;

	if (node == NULL)
		return ;
	if ((*stack)->top == NULL)
	{
		node->next = node;
		node->prev = node;
		(*stack)->top = node;
	}
	else
	{
		tail = (*stack)->top->prev;
		node->next = (*stack)->top;
		node->prev = tail;
		tail->next = node;
		(*stack)->top->prev = node;
		(*stack)->top = node;
	}
	(*stack)->size++;
}

static void	renew_index(t_stack **stack)
{
	t_node	*current;
	int		index;

	if ((*stack)->top == NULL)
		return ;
	current = (*stack)->top;
	index = 0;
	while (current != (*stack)->top || index == 0)
	{
		current->index = index;
		current = current->next;
		index++;
	}
}

void	push_ab(t_stack **stack_a, t_stack **stack_b, int flag)
{
	t_node	*temp_a;
	t_node	*temp_b;
	
	if (flag == 0)
	{
		temp_b = detach_top(stack_b);
		if (temp_b)
		{
			attach_top(stack_a, temp_b);
			renew_index(stack_a);
			renew_index(stack_b);
			ft_printf("%s\n", "pa");
		}
	}
	else if (flag == 1)
	{
		temp_a = detach_top(stack_a);
		if (temp_a)
		{
			attach_top(stack_b, temp_a);
			renew_index(stack_a);
			renew_index(stack_b);
			ft_printf("%s\n", "pb");
		}
	}
}
