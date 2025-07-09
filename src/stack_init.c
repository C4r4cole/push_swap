/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:45:22 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/09 18:35:31 by fmoulin          ###   ########.fr       */
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

void	init_stack_a(t_stack_node **a, char **argv, int argc)
{
	int		i;
	long	n;
	int		count;

	i = 0;
	count = ft_count_str(argv[0], ' ');
	if (argc == 1)
		argv = ft_split(argv[0], ' ');
	while (argv[i])
	{
		if (error_synthax(argv[i]) || err_atoi(argv[i], &n)
			|| error_duplicate(*a, (int)n))
		{
			free_errors(a);
			if (argc == 1)
				free_args(argv, count);
			exit(EXIT_SUCCESS);
		}	
		append_node(a, (int)n);
		i++;
	}
	if (argc == 1)
		free_args(argv, count);
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

void	prep_for_push(t_stack_node **stack, t_stack_node *top_node, char name)
{
	while (*stack != top_node)
	{
		if (name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}
