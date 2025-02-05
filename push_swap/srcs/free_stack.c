/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:37:23 by jchen2            #+#    #+#             */
/*   Updated: 2024/12/29 16:59:08 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next_node;

	if (!stack)
		return ;
	if (stack->top)
	{
		current = stack->top;
		if (current->next == stack->top)
			free(current);
		else
		{
			while (current->next != stack->top)
			{
				next_node = current->next;
				free(current);
				current = next_node;
			}
			free(current);
		}
	}
	free(stack);
}
