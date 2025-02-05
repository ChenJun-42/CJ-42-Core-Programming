/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen2 <jchen2@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:22:49 by jchen2            #+#    #+#             */
/*   Updated: 2025/02/02 16:25:16 by jchen2           ###   ########.fr       */
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
	long			num_index;
	struct s_node	*prev;
	struct s_node	*next;
	struct s_node	*b_node;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	long	size;
}	t_stack;

void	input_valid(int argc, char **argv);
void	free_split(char	**argv);
int		is_num(const char *str);
int		input_string_valid(char **argv);
int		is_sorted(t_stack *stack);
t_stack	*create_stack(int argc, char **argv);
t_stack	*init_stack(void);
void	init_num_index(t_stack **stack_a);
void	push_ab(t_stack **stack_b, t_stack **stack_a, int flag);
void	rotate_reverse_ab(t_stack **stack_a, t_stack **stack_b, int flag);
void	swap_ab(t_stack **stack_a, t_stack **stack_b, int flag);
void	rotate_ab(t_stack **stack_a, t_stack **stack_b, int flag);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
void	sort_three_node(t_stack **stack_a, t_stack **stack_b);
void	sort_four_node(t_stack **stack_a, t_stack **stack_b);
void	sort_five_node(t_stack **stack_a, t_stack **stack_b);
void	a_to_b(t_stack **stack_a, t_stack **stack_b);
void	b_to_a(t_stack **stack_a, t_stack **stack_b);
void	ex_same_down(t_stack **stack_a, t_stack **stack_b, t_node *node);
void	ex_same_up(t_stack **stack_a, t_stack **stack_b, t_node *node);
void	ex_ops_up(t_stack **stack_a, t_stack **stack_b, t_node *node);
void	ex_ops_down(t_stack **stack_a, t_stack **stack_b, t_node *node);
void	renew_step_node(t_stack **stack_a, t_stack **stack_b);
t_node	*find_ministep(t_stack	**stack_a);
void	sep_grp(t_stack **stack_a, t_stack **stack_b);
void	p_b_a(t_stack **stack_a, t_stack **stack_b);
void	renew_step_node_group(t_stack **stack_a,
			t_stack **stack_b, long x, long y);
void	ex_ops_down_b_a(t_stack **stack_a, t_stack **stack_b, t_node *node);
void	ex_ops_up_b_a(t_stack **stack_a, t_stack **stack_b, t_node *node);
void	ex_same_down_b_a(t_stack **stack_a, t_stack **stack_b, t_node *node);
void	ex_same_up_b_a(t_stack **stack_a, t_stack **stack_b, t_node *node);
void	rotate_min_top(t_stack **stack_a, t_stack **stack_b);
void	free_stack(t_stack *stack);

#endif
