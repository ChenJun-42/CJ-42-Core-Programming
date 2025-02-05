/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_num_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:16:52 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/05 10:15:31 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_min(t_stack **stack_a)
{
	t_node	*temp;
	t_node	*min_node;
	long	min_value;

	temp = (*stack_a)->top;
	min_node = NULL;
	min_value = INT_MAX;
	while (1)
	{
		if (temp->num_index == -1 && temp->num < min_value)
		{
			min_node = temp;
			min_value = temp->num;
		}
		temp = temp->next;
		if (temp == (*stack_a)->top)
			break ;
	}
	return (min_node);
}

void	init_num_index(t_stack **stack_a)
{
	t_node	*min_node;
	long	i;

	i = 0;
	while (i < (*stack_a)->size)
	{
		min_node = find_min(stack_a);
		if (!min_node)
			break ;
		min_node->num_index = i;
		i++;
	}
}
