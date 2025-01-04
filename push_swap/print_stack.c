/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:11:52 by jchen2            #+#    #+#             */
/*   Updated: 2024/12/29 16:59:42 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
	{
		ft_printf("The stack is empty\n");
		return ;
	}
	current = stack->top;
	ft_printf("The stack contents:\n");
	ft_printf("num: %d, index: %d\n", current->num, current->index);
	current = current->next;
	while (current != stack->top)
	{
		ft_printf("num: %d, index: %d\n", current->num, current->index);
		current = current->next;
	}
}
