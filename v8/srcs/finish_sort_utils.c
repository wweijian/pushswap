/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:29:05 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/05 23:24:25 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_min_to_b(t_stack stack, int top, int min_value)
{
	int	i;

	i = top_of_stack(stack.a, stack.count);
	while (top > 0)
	{
		if (stack.a[i] <= min_value + 1)
		{
			push_a_to_b(stack);
			i = top_of_stack(stack.a, stack.count);
		}
		else
			rotate_stack_a(stack);
		top--;
	}
	while (top < 3)
	{
		reverse_rotate_stack_a(stack);
		top++;
	}
	finish_sort_a_three(stack, top);
	finish_sort_b_two(stack, top);
}
