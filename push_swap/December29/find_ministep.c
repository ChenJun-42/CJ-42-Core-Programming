/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ministep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:23:29 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/01 20:07:12 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_ministep(t_stack	**stack_a)
{
	t_node	*init_node;
	t_node	*loop_node;
	t_node	*mini_node;

	if (!stack_a || !(*stack_a))
		return (NULL);
	init_node = (*stack_a)->top;
	mini_node = (*stack_a)->top;
	loop_node = (*stack_a)->top->next;
	while (loop_node != init_node)
	{
		if (mini_node->step > loop_node->step)
			mini_node = loop_node;
		loop_node = loop_node->next;
	}
	return (mini_node);
}
