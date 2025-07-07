/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:02:30 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/07 20:41:30 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*b);
	if(cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(b, a, cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
		rev_rotate_both(b, a, cheapest_node);
	prep_for_push(b, cheapest_node, 'b');
	prep_for_push(a, cheapest_node->target_node, 'a');
	pa(a, b, false);
}

// void	move_b_to_a(t_stack_node **a, t_stack_node **b)
// {
// 	prep_for_push(a, (*b)->target_node, 'a');
// 	pa(a, b, false);
// }

void	min_on_top(t_stack_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;
	int total_length;
	
	len_a = ft_lstsize(*a);
	total_length = len_a;
	// if(len_a-- > 3 && !stack_sorted(*a))
	// 	pb(b, a, false);
	// if(len_a-- > 3 && !stack_sorted(*a))
	// 	pb(b, a, false);
	set_index(*a, len_a);
	while(len_a-- > 3 && !stack_sorted(*a))
	{
		pb(b, a, false);
		if ((*b)->index < (total_length / 2))
			rb(b, false);
		// init_nodes_a(*a, *b);
		// move_a_to_b(a, b);
	}
	sort_three(a);
	while(*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
