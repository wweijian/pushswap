/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_a_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:58:05 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/04 13:08:19 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish_a_top(t_stack stack, int top)
{
	if (top == 5)
		return (finish_a_top_five(stack, top));
	if (top == 4)
		return (finish_a_top_four(stack, top));
	if (top == 3)
		return (finish_a_top_three(stack, top));
	if (top == 2 || top == 1)
		return (finish_a_top_two(stack, top));
	// for (int i = 0; i < stack.count; i++)
	// 	printf("index %d:\t%d\t%d\n", i, stack.a[i], stack.b[i]);
}

void	finish_a_top_two(t_stack stack, int top)
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

void	finish_a_top_three(t_stack stack, int top)
{
	int	i;
	int	max_index;

	i = top_of_stack(stack.a, stack.count);
	max_index = find_max(stack.a, stack.count, top);
	if (i + 2 == max_index)
		return (finish_a_top_two(stack, top - 1));
	if (i + 1 == max_index)
	{
		rotate_stack_a(stack);
		swap_top_a(stack);
		reverse_rotate_stack_a(stack);
		return (finish_a_top_two(stack, top - 1));
	}
	if (i == max_index)
	{
		rotate_stack_a(stack);
		finish_a_top_two(stack, top - 1);
		reverse_rotate_stack_a(stack);
	}
}

void	finish_a_top_four(t_stack stack, int top)
{
	int	i;
	int	max_index;

	i = top_of_stack(stack.a, stack.count);
	max_index = find_max(stack.a, stack.count, top);
	if (i + 1 == max_index)
	{
		swap_top_a(stack);
		max_index--;
	}
	if (i == max_index)
	{
		push_a_to_b(stack);
		multiple_op(rotate_stack_a, stack, 3);
		push_b_to_a(stack);
		multiple_op(reverse_rotate_stack_a, stack, 3);
	}
	else if (i + 2 == max_index)
	{
		multiple_op(rotate_stack_a, stack, 2);
		swap_top_a(stack);
		multiple_op(reverse_rotate_stack_a, stack, 2);
	}
	return (finish_a_top_three(stack, top - 1));
}

void finish_a_top_five(t_stack stack, int top)
{
	int	i;
	int	max_index;

	i = top_of_stack(stack.a, stack.count);
	max_index = find_max(stack.a, stack.count, top);
	if (i + 1 == max_index)
	{
		swap_top_a(stack);
		max_index--;
	}
	if (i == max_index)
	{
		push_a_to_b(stack);
		multiple_op(rotate_stack_a, stack, 4);
		push_b_to_a(stack);
		multiple_op(reverse_rotate_stack_a, stack, 4);
	}
	if (i + 2 == max_index)
	{
		multiple_op(rotate_stack_a, stack, 2);
		push_a_to_b(stack);
		multiple_op(rotate_stack_a, stack, 2);
		push_b_to_a(stack);
		multiple_op(reverse_rotate_stack_a, stack, 4);
	}
	if (i + 3 == max_index)
	{
		multiple_op(rotate_stack_a, stack, 3);
		push_a_to_b(stack);
		multiple_op(rotate_stack_a, stack, 1);
		push_b_to_a(stack);
		multiple_op(reverse_rotate_stack_a, stack, 4);
	}
	return (finish_a_top_four(stack, top - 1));
}


// utils
void	multiple_op(void (*f)(t_stack), t_stack stack, int n)
{
	while (n)
	{
		f(stack);
		n--;
	}
}