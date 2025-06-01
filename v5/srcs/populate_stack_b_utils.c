/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_stack_b_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 21:28:22 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/01 20:26:18 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_btm_partition(int *stack_a, int count)
{
	int	i;

	i = top_of_stack(stack_a, count);
	return ((count - i) / 3 + i + 1);
}

int	find_top_partition(int *stack_a, int count)
{
	int	i;

	i = top_of_stack(stack_a, count);
	return (count - ((count - i + 1) / 3) + 1);
}

int	presort_push_btm(int *stack_a, int *stack_b, int count)
{
	int	i;

	push_a_to_b(stack_a, stack_b, count);
	i = top_of_stack(stack_a, count);
	if (stack_a[i] > find_top_partition(stack_a, count))
		rotate_stack(stack_a, stack_b, count);
	else
		rotate_stack(NULL, stack_b, count);
	return (1);
}

int	presort_push_top(int *stack_a, int *stack_b, int count)
{
	push_a_to_b(stack_a, stack_b, count);
	return (1);
}