/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:45:21 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/01 10:42:51 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack_node	*ft_lstnew(void *content)
{
	t_stack_node	*new;

	new = malloc(sizeof(t_stack_node));
	if (!new)
		return (NULL);
	new->nbr = content;
	new->next = NULL;
	return (new);
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list	*new_struct;
// 	char	*str = "hello";

// 	new_struct = ft_lstnew(str);
// 	printf("%s\n", (char *)new_struct->content);
// 	return (0);
// }
