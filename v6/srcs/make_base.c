/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 08:43:43 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/02 14:46:18 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_base(t_stack stack)
{
	int	i;

	i = top_of_stack(stack.a, stack.count);
	if (stack.count - i <= 3)
		make_base_3(stack);
	else
		make_base_5(stack);
	if (stack.a[i] > stack.a [i + 1])
		swap_a(stack);
}

void	make_base_3(t_stack stack)
{
	while (stack.a[stack.count - 1] != stack.count)
		rotate_stack_a(stack);
	if (stack.a[stack.count - 2] < stack.a[stack.count - 3])
		swap_top_a(stack);
}

void	make_base_5(t_stack stack)
{
	int	i;
	int	push_count;
	int	min;

	i = top_of_stack(stack.a, stack.count);
	min = i + 1;
	push_count = 0;
	if (stack.count - 1 == 5)
		min++;
	while (stack.count - i > 3)
	{
		if (stack.a[i] <= min)
		{
			push_a_to_b(stack);
			push_count++;
		}
		else
			rotate_stack_a(stack);
		i = top_of_stack(stack.a, stack.count);
	}
	make_base_3(stack);
	while (push_count-- > 0)
		push_b_to_a(stack);
}
