/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:24:15 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/08 11:43:34 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if(!stack)
		return ;
	median = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index_median = i;
		if(i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < best_match_index)
			{
				best_match_index = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void cost_analysis_b(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;
	
	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
	while (b)
	{
		b->push_cost = b->index_median;
		if (!(b->above_median))
			b->push_cost = len_b - (b->index_median);
		if (b->target_node->above_median)
			b->push_cost += b->target_node->index_median;
		else
			b->push_cost += len_a - (b->target_node->index_median);
		b = b->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	long			cheapest_value;
	t_stack_node	*cheapest_node;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = stack;
	while (current)
	{
		current->cheapest = false;
		current = current->next;
	}
	cheapest_value = LONG_MAX;
	current = stack;
	while (current)
	{
		if (current->push_cost < cheapest_value)
		{
			cheapest_value = current->push_cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	if (cheapest_node)
		cheapest_node->cheapest = true;
}

void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
	cost_analysis_b(a, b);
	set_cheapest(b);
}