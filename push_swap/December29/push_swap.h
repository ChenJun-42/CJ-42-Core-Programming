/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:22:49 by jchen2            #+#    #+#             */
/*   Updated: 2025/01/04 18:39:03 by jchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "libftprintf.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_node
{
	long			num;
	long			index;
	long			step;
	long 			num_index;
	struct s_node	*prev;
	struct s_node	*next;
	struct s_node	*b_node;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	long	size;
}	t_stack;

t_stack	*create_stack(int argc, char **argv);
t_stack	*init_stack(void);
t_node	*find_ministep(t_stack	**stack_a);
void	init_num_index(t_stack **stack_a);
void	a_to_b(t_stack **stack_a, t_stack **stack_b);
void	b_to_a(t_stack **stack_a, t_stack **stack_b);
void	renew_step_node(t_stack **stack_a, t_stack **stack_b);
void	input_valid(int argc, char **argv);
char	**input_string_valid(char **argv);
void	push_ab(t_stack **stack_b, t_stack **stack_a, int flag);
void	rotate_ab(t_stack **stack_a, t_stack **stack_b, int flag);
void	rotate_reverse_ab(t_stack **stack_a, t_stack **stack_b, int flag);
void	swap_ab(t_stack **stack_a, t_stack **stack_b, int flag);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
void	print_stack(t_stack *stack);
void	free_stack(t_stack *stack);

#endif
