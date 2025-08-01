/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 10:56:52 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/10 16:49:51 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	execute_op(char *line, t_stack_node **a, t_stack_node **b)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(a, true);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(b, true);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(a, b, true);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(a, b, true);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(b, a, true);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(a, true);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(b, true);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(a, b, true);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(a, true);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(b, true);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(a, b, true);
	else
		return (0);
	return (1);
}

int	read_print_and_execute_operations(t_stack_node **a, t_stack_node **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!execute_op(line, a, b))
		{
			free(line);
			write(2, "Error\n", 6);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**args;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	args = argv + 1;
	init_stack_a(&a, args, argc - 1);
	if (read_print_and_execute_operations(&a, &b))
	{
		if (!b && stack_sorted(a))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
