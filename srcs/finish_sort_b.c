/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_sort_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 23:19:24 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/05 23:21:47 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish_sort_b(t_stack stack, int elements)
{
	if (elements == 5)
		finish_sort_b_five(stack, elements);
	else if (elements == 4)
		finish_sort_b_four(stack, elements);
	else if (elements == 3)
		finish_sort_b_three(stack, elements);
	else if (elements == 2 || elements == 1)
		finish_sort_b_two(stack, elements);
}

void	finish_sort_b_two(t_stack stack, int elements)
{
	int	max_index;
	int	j;

	max_index = find_max(stack.b, stack.count, elements);
	j = top_of_stack(stack.b, stack.count);
	if (elements == 1)
		push_b_to_a(stack);
	else
	{
		if (max_index == j + 1)
			swap_top_b(stack);
		push_b_to_a(stack);
		push_b_to_a(stack);
	}
}

void	finish_sort_b_three(t_stack stack, int elements)
{
	int	max_index;
	int	j;

	max_index = find_max(stack.b, stack.count, elements);
	j = top_of_stack(stack.b, stack.count);
	if (j == max_index)
	{
		push_b_to_a(stack);
		return (finish_sort_b_two(stack, elements - 1));
	}
	if (j + 1 == max_index)
	{
		swap_top_b(stack);
		return (finish_sort_b_three(stack, elements));
	}
	if (j + 2 == max_index)
	{
		multiple_op(rotate_stack_b, stack, 2);
		push_b_to_a(stack);
		multiple_op(reverse_rotate_stack_b, stack, 2);
		return (finish_sort_b_two(stack, elements - 1));
	}
}

void	finish_sort_b_four(t_stack stack, int elements)
{
	int	max_index;
	int	j;

	max_index = find_max(stack.b, stack.count, elements);
	j = top_of_stack(stack.b, stack.count);
	if (j == max_index)
	{
		push_b_to_a(stack);
		return (finish_sort_b_three(stack, elements - 1));
	}
	if (j + 1 == max_index)
	{
		swap_top_b(stack);
		return (finish_sort_b_four(stack, elements));
	}
	if (max_index - j > 1)
	{
		multiple_op(rotate_stack_b, stack, max_index - j);
		push_b_to_a(stack);
		multiple_op(reverse_rotate_stack_b, stack, max_index - j);
		return (finish_sort_b_three(stack, elements - 1));
	}
}

void	finish_sort_b_five(t_stack stack, int elements)
{
	int	max_index;
	int	j;

	max_index = find_max(stack.b, stack.count, elements);
	j = top_of_stack(stack.b, stack.count);
	if (j == max_index)
	{
		push_b_to_a(stack);
		return (finish_sort_b_four(stack, elements - 1));
	}
	if (j + 1 == max_index)
	{
		swap_top_b(stack);
		return (finish_sort_b_five(stack, elements));
	}
	if (max_index - j > 1)
	{
		multiple_op(rotate_stack_b, stack, max_index - j);
		push_b_to_a(stack);
		multiple_op(reverse_rotate_stack_b, stack, max_index - j);
		return (finish_sort_b_four(stack, elements - 1));
	}
}
