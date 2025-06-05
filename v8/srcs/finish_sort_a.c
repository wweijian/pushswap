/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_sort_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:58:05 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/05 23:21:01 by wjhoe            ###   ########.fr       */
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
	int	min_index;
	int	min_value;

	i = top_of_stack(stack.a, stack.count);
	max_index = find_max(stack.a, stack.count, top);
	min_index = find_min(stack.a, stack.count, top);
	min_value = stack.a[min_index];
	if (max_index == i + 3)
		return (finish_sort_a_three(stack, top - 1));
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
	while (top < 2)
	{
		reverse_rotate_stack_a(stack);
		top++;
	}
	finish_sort_a_two(stack, top);
	finish_sort_b_two(stack, top);
}

void	finish_sort_a_five(t_stack stack, int top)
{
	int	i;
	int	max_index;
	int	min_index;

	i = top_of_stack(stack.a, stack.count);
	max_index = find_max(stack.a, stack.count, top);
	min_index = find_min(stack.a, stack.count, top);
	if (max_index == i + 3)
		return (finish_sort_a_three(stack, top - 1));
	while (top > 0)
	{
		if (stack.a[i] <= stack.a[i + 1] + 1)
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
