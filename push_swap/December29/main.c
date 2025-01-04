/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:01:50 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/04 18:43:15 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	input_valid(argc, argv);
	stack_a = create_stack(argc, argv);
	stack_b = init_stack();
	init_num_index(&stack_a);
	print_stack(stack_a);
	printf("Stack_a size: %zu\n", stack_a->size);
	sort_stack(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}
