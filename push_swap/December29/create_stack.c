/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:44:03 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/04 18:17:27 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	create_node(t_stack *stack, int value, int index)
{
	t_node	*new_node;
	t_node	*tail;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->num = value;
	new_node->index = index;
	new_node->num_index = -1;
	new_node->step = 0;
	new_node->b_node = NULL;
	if (stack->top == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		stack->top = new_node;
	}
	tail = stack->top->prev;
	new_node->next = stack->top;
	new_node->prev = tail;
	stack->top->prev = new_node;
	tail->next = new_node;
	stack->top = new_node;
}

void	free_split(char	**argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	fill_stack(int argc, char **argv, t_stack *stack, int is_split)
{
	int		num;
	int		i;
	int		start;

	if (is_split == 1)
	{
		i = argc - 1;
		start = -1;
	}
	else
	{
		i = argc - 1;
		start = 0;
	}
	while (i > start)
	{
		num = ft_atoi(argv[i]);
		if (is_split)
			create_node(stack, num, (i));
		else
			create_node(stack, num, (i - 1));
		i--;
	}
}

t_stack	*create_stack(int argc, char **argv)
{
	int		is_split;
	t_stack	*stack;

	stack = init_stack();
	is_split = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (NULL);
		is_split = 1;
		argc = 0;
		while (argv[argc])
			argc++;
	}
	fill_stack(argc, argv, stack, is_split);
	if (is_split)
	{
		stack->size = argc;
		free_split(argv);
	}
	else
		stack->size = argc - 1;
	return (stack);
}
