/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:01:50 by jchen2            #+#    #+#             */
/*   Updated: 2025/02/02 19:32:15 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	input_valid(argc, argv);
	stack_a = create_stack(argc, argv);
	if (is_sorted(stack_a) == 1)
	{
		free_stack(stack_a);
		return (0);
	}
	stack_b = init_stack();
	init_num_index(&stack_a);
	sort_stack(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
