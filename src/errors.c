/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:59:07 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/09 17:18:10 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	error_synthax(char *str_n)
{
	int	i;

	i = 0;
	if (str_n[i] == '+' || str_n[i] == '-')
		++i;
	if (!str_n[i])
		return (1);
	while (str_n[i] >= '0' && str_n[i] <= '9')
		i++;
	if (str_n[i])
		return (1);
	return (0);
}

int	error_duplicate(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}
