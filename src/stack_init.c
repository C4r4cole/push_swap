/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:45:22 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/01 15:25:32 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*new;
	t_stack_node	*last_node;
	
	// if (!stack)
	// 	return ;
	// new = malloc(sizeof(t_stack_node));
	// if (!new)
	// 	return ;
	// new->nbr = n;
	// new->next = NULL;
	new = ft_lstnew((int)n);
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
		if(error_syntax(argv[i]))
			free_errors(a);
		n = (long)ft_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if(error_duplicate(*a, (int)n))
			free_errors(a);
		append_node(a, (int)n);
		i++;
	}
}