/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:02:30 by fmoulin           #+#    #+#             */
/*   Updated: 2025/06/26 16:26:31 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;
	
	len_a = ft_lstsize(*a);
	if(len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if(len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while(len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
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

//Continuer video push swap de Thuggonaut a 34':50"