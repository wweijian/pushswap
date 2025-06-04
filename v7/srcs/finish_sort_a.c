/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_sort_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:58:05 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/04 22:08:21 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish_sort_a(t_stack stack, int top)
{
	if (top == 5)
		finish_sort_a_five(stack, top);
	else if (top == 4)
		finish_sort_a_four(stack, top);
	else if (top == 3)
		finish_sort_a_three(stack, top);
	else if (top == 2 || top == 1)
		finish_sort_a_two(stack, top);
}

void	finish_sort_a_two(t_stack stack, int top)
{
	int	i;

	i = top_of_stack(stack.a, stack.count);
	if (top == 2)
	{
		if (stack.a[i] > stack.a[i + 1])
			swap_top_a(stack);
	}
	return ;
}

void	finish_sort_a_three(t_stack stack, int top)
{
	int	i;
	int	max_index;

	i = top_of_stack(stack.a, stack.count);
	max_index = find_max(stack.a, stack.count, top);
	if (i + 2 == max_index)
		return (finish_sort_a_two(stack, top - 1));
	if (i + 1 == max_index)
	{
		rotate_stack_a(stack);
		swap_top_a(stack);
		reverse_rotate_stack_a(stack);
		return (finish_sort_a_two(stack, top - 1));
	}
	if (i == max_index)
	{
		swap_top_a(stack);
		rotate_stack_a(stack);
		swap_top_a(stack);
		reverse_rotate_stack_a(stack);
		return (finish_sort_a_two(stack, top - 1));
	}
}

void	finish_sort_a_four(t_stack stack, int top)
{
	int	i;
	int	max_index;

	i = top_of_stack(stack.a, stack.count);
	max_index = find_max(stack.a, stack.count, top);
	if (max_index - i < top)
	{
		multiple_op(rotate_stack_a, stack, max_index - i);
		push_a_to_b(stack);
		multiple_op(rotate_stack_a, stack, (i + top) - max_index - 1);
		push_b_to_a(stack);
		multiple_op(reverse_rotate_stack_a, stack, top - 1);
	}
	return (finish_sort_a_three(stack, top - 1));
}

void finish_sort_a_five(t_stack stack, int top)
{
	int	i;
	int	max_index;

	i = top_of_stack(stack.a, stack.count);
	max_index = find_max(stack.a, stack.count, top);
	if (max_index - i < top)
	{
		multiple_op(rotate_stack_a, stack, max_index - i);
		push_a_to_b(stack);
		multiple_op(rotate_stack_a, stack, (i + top) - max_index - 1);
		push_b_to_a(stack);
		multiple_op(reverse_rotate_stack_a, stack, top - 1);
	}
	return (finish_sort_a_four(stack, top - 1));
}