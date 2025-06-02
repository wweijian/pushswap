/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:08:50 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/02 00:57:27 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_argument(char *arg)
{
	if (!check_digits(arg))
		return (0);
	if (!check_limits(arg))
		return (0);
	return (1);
}

int	check_duplicates(int *stack, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i + 1 < count)
	{
		j = 1;
		while (i + j < count)
		{
			if (stack[i] == stack[i + j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_limits(char *arg)
{
	long	num;

	num = ft_atol(arg);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

int	check_digits(char *arg)
{
	if (*arg == '+' || *arg == '-')
		arg++;
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (0);
		arg++;
	}
	return (1);
}

int	ft_atol(const char *nptr)
{
	int		i;
	long	neg;
	long	res;

	i = 0;
	neg = 1;
	res = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (nptr[i] - '0') + (res * 10);
		i++;
	}
	return (res * neg);
}
