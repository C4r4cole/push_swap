/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:41:10 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/09 16:19:46 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("rr\n");
}

void	rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
	{
		rr(a, b, false);
	}
	current_index(*a);
	current_index(*b);
}
