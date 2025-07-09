/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:16:51 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/09 16:24:36 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*create_tab(t_stack_node *a, int len)
{
	int	*tab;
	int	i;

	tab = malloc(sizeof(int) * len);
	if (!tab)
		return (0);
	i = 0;
	while (a)
	{
		tab[i] = a->nbr;
		i++;
		a = a->next;
	}
	return (tab);
}

int	*sort_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	while (size > 0)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
		size--;
	}
	return (tab);
}

void	create_index(t_stack_node *a, int *sorted_tab, int len)
{
	int	i;

	while (a)
	{
		i = 0;
		while (i < len)
		{
			if (a->nbr == sorted_tab[i])
			{
				a->index = i;
				break ;
			}
			i++;
		}
		a = a->next;
	}
}

void	set_index(t_stack_node *a, int len)
{
	int	*tab;
	int	*sorted_tab;

	tab = create_tab(a, len);
	sorted_tab = sort_int_tab(tab, len);
	create_index(a, sorted_tab, len);
	free(tab);
}
