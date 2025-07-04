/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:45:22 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/02 17:22:30 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*new;
	t_stack_node	*last_node;
	
	if (!stack)
		return ;
	new = malloc(sizeof(t_stack_node));
	if (!new)
		return ;
	new->next = NULL;
	new->nbr = n;
	new->cheapest = 0;
	if (!(*stack))
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		last_node = ft_lstlast(*stack);
		last_node->next = new;
		new->prev = last_node;
	}
}

void	init_stack_a(t_stack_node **a, char **argv)
{
	int	i;
	long n;

	i = 0;
	while (argv[i])
	{
		if(error_synthax(argv[i]))
			free_errors(a);
		n = ft_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if(error_duplicate(*a, (int)n))
			free_errors(a);
		append_node(a, (int)n);
		i++;
	}
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}
