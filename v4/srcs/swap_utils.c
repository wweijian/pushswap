/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:14:32 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/27 21:53:29 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(int *stack_a, int *stack_b, int count)
{
	int	i;

	i = top_of_stack(stack_b, count);
	if (i < count - 1)
	{
		if (stack_b[i] < stack_b[i + 1])
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

void	check_swap_a(int *stack_a, int *stack_b, int count)
{
	int	i;

	i = top_of_stack(stack_a, count);
	if (stack_a[i] > stack_a[i + 1])
		swap_a(stack_a, stack_b, count);
}

void	check_swap_b(int *stack_a, int *stack_b, int count)
{
	int	i;

	i = top_of_stack(stack_b, count);
	if (stack_b[i] < stack_b[i + 1])
		swap_b(stack_a, stack_b, count);
}
