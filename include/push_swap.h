/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 09:12:57 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/01 18:39:20 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node *target_node;
	struct s_stack_node *prev;
	struct s_stack_node *next;
}				t_stack_node;

//Handle errors

//Stack initiation
void	init_stack_a(t_stack_node **a, char **argv);

//Nodes initiation
static void	append_node(t_stack_node **stack, int n);
void	init_nodes_a(t_stack_node *a, t_stack_node *b);
void	current_index(t_stack_node *stack);
static void	set_target_a(t_stack_node *a, t_stack_node *b);
static void cost_analysis_a(t_stack_node *a, t_stack_node *b);
void	set_cheapest(t_stack_node *stack);
static void	move_a_to_b(t_stack_node **a, t_stack_node **b);

//Stack utils
bool	stack_sorted(t_stack_node *stack);

//Commands
void	swap(t_stack_node **stack);
void	sa(t_stack_node **a, bool print);
void	sb(t_stack_node **b, bool print);
void	ss(t_stack_node **a, t_stack_node **b, bool print);
void	ra(t_stack_node **a, bool print);
void	rb(t_stack_node **b, bool print);
void	rr(t_stack_node **a, t_stack_node **b, bool print);
void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);

//Algorithms
void	sort_stacks(t_stack_node **a, t_stack_node **b);
void	sort_three(t_stack_node **a);

#endif