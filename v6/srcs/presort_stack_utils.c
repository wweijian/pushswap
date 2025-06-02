/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort_stack_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 21:28:22 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/02 12:44:13 by wjhoe            ###   ########.fr       */
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

int	presort_push_btm(t_stack stack)
{
	int	i;

	push_a_to_b(stack.a, stack.b, stack.count, stack);
	i = top_of_stack(stack.a, stack.count);
	if (stack.a[i] > find_top_partition(stack.a, stack.count))
		rotate_stack(stack.a, stack.b, stack.count, stack);
	else
		rotate_stack(NULL, stack.b, stack.count, stack);
	return (1);
}

int	presort_push_top(t_stack stack)
{
	push_a_to_b(stack.a, stack.b, stack.count, stack);
	return (1);
}
