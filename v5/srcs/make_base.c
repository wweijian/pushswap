/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 08:43:43 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/02 01:00:42 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_base(int *stack_a, int *stack_b, int count)
{
	int	i;

	i = top_of_stack(stack_a, count);
	if (count - i <= 3)
		make_base_3(stack_a, count);
	else
		make_base_5(stack_a, stack_b, count);
	if (stack_a[i] > stack_a [i + 1])
		swap_a(stack_a, stack_b, count);
}

void	make_base_3(int *stack_a, int count)
{
	while (stack_a[count - 1] != count)
		rotate_stack(stack_a, NULL, count);
	if (stack_a[count - 2] < stack_a[count - 3])
		swap_top(stack_a, NULL, count);
}

void	make_base_5(int *stack_a, int *stack_b, int count)
{
	int	i;
	int	push_count;
	int	min;

	i = top_of_stack(stack_a, count);
	min = i + 1;
	push_count = 0;
	if (count - 1 == 5)
		min++;
	while (count - i > 3)
	{
		if (stack_a[i] <= min)
		{
			push_a_to_b(stack_a, stack_b, count);
			push_count++;
		}
		else
			rotate_stack(stack_a, NULL, count);
		i = top_of_stack(stack_a, count);
	}
	make_base_3(stack_a, count);
	while (push_count-- > 0)
		push_b_to_a(stack_a, stack_b, count);
}
