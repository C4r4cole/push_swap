/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 10:56:52 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/08 11:37:35 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node 	*a;
	t_stack_node 	*b;
	char 			**args;
	int				count;

	args = argv + 1;
	count = ft_count_str(argv[1], ' ');
	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		args = ft_split(argv[1], ' ');
	init_stack_a(&a, args);
	if (args != argv + 1)
		free_args(args, count);
	if (!stack_sorted(a))
	{
		if(ft_lstsize(a) == 2)
			sa(&a, false);
		else if (ft_lstsize(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}