/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:08:50 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/26 17:28:32 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_limits(char *arg)
{
	long	num;

	num = ft_atol(arg);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

static int	check_digits(char *arg)
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