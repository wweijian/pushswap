/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:14:32 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/02 01:36:22 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(int *stack_a, int *stack_b, int count)
{
	int	j;

	j = top_of_stack(stack_b, count);
	if (j < count - 1)
	{
		if (stack_b[j] < stack_b[j + 1])
		{
			swap_top(stack_a, stack_b, count);
		}
		else
			swap_top(stack_a, NULL, count);
	}
	else
		swap_top(stack_a, NULL, count);
}

void	swap_b(int *stack_a, int *stack_b, int count)
{
	int	i;

	i = top_of_stack(stack_a, count);
	if (i < count - 1)
	{
		if (stack_a[i] > stack_a[i + 1])
		{
			swap_top(stack_a, stack_b, count);
		}
		else
			swap_top(NULL, stack_b, count);
	}
	else
		swap_top(NULL, stack_b, count);
}
