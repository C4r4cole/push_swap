/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:46:47 by fmoulin           #+#    #+#             */
/*   Updated: 2025/07/09 16:54:51 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *nptr)
{
	size_t	i;
	size_t	sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (nptr[i] == 9 || nptr[i] == 10
		|| nptr[i] == 11 || nptr[i] == 12
		|| nptr[i] == 13 || nptr[i] == 32)
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - 48);
		i++;
	}
	return (nb * sign);
}

//error
int	err_atoi(const char *nptr, long *ptr_to_store_res)
{
	size_t	i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		if (nb * sign > FT_INT_MAX || nb * sign < FT_INT_MIN)
			return (1);
		i++;
	}
	*ptr_to_store_res = nb * sign;
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*nbr;

	nbr = "     -532";
	printf("%d\n", ft_atoi(nbr));
	printf("%d\n", atoi(nbr));
	return (0);
}
*/