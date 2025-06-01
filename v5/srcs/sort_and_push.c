/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 23:19:24 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/02 01:17:34 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_and_push(int *stack_a, int *stack_b, int count, int count_top)
{
	if (count_top == 5)
		return (sort_and_push_five(stack_a, stack_b, count, count_top));
	if (count_top == 4)
		return (sort_and_push_four(stack_a, stack_b, count, count_top));
	if (count_top == 3)
		return (sort_and_push_three(stack_a, stack_b, count, count_top));
	if (count_top == 2 || count_top == 1)
		return (sort_and_push_two(stack_a, stack_b, count, count_top));
}

void	sort_and_push_two(int *stack_a, int *stack_b, int count, int count_top)
{
	int	j;

	j = top_of_stack(stack_b, count);
	if (count_top == 2)
	{
		if (stack_b[j] < stack_b[j + 1])
			swap_top(NULL, stack_b, count);
	}
	rotate_a_to_position(stack_a, stack_b, count);
	if (count_top == 2)
	{
		push_b_to_a(stack_a, stack_b, count);
		push_b_to_a(stack_a, stack_b, count);
	}
	else if (count_top == 1)
		push_b_to_a(stack_a, stack_b, count);
	else
		return ;
}

void	sort_and_push_three(int *stack_a, int *stack_b, int count, int count_top)
{
	int	max_index;
	int	j;

	max_index = find_max(stack_b, count, count_top);
	j = top_of_stack(stack_b, count);
	if (j == max_index)
	{
		sort_to_a(stack_a, stack_b, count);
		return (sort_and_push_two(stack_a, stack_b, count, count_top - 1));
	}
	if (j + 1 == max_index)
	{
		swap_top(NULL, stack_b, count);
		return (sort_and_push_three(stack_a, stack_b, count, count_top));
	}
	while (count_top)
	{
		sort_to_a(stack_a, stack_b, count);
		count_top--;
	}
}

void	sort_and_push_four(int *stack_a, int *stack_b, int count, int count_top)
{
	int	max_index;
	int	j;

	max_index = find_max(stack_b, count, count_top);
	j = top_of_stack(stack_b, count);
	if (j == max_index)
	{
		sort_to_a(stack_a, stack_b, count);
		return (sort_and_push_three(stack_a, stack_b, count, count_top - 1));
	}
	if (j + 1 == max_index)
	{
		swap_top(NULL, stack_b, count);
		return (sort_and_push_four(stack_a, stack_b, count, count_top));
	}
	while (count_top)
	{
		sort_to_a(stack_a, stack_b, count);
		count_top--;
	}
}

void	sort_and_push_five(int *stack_a, int *stack_b, int count, int count_top)
{
	int	max_index;
	int	j;

	max_index = find_max(stack_b, count, count_top);
	j = top_of_stack(stack_b, count);
	if (j == max_index)
	{
		sort_to_a(stack_a, stack_b, count);
		return (sort_and_push_four(stack_a, stack_b, count, count_top - 1));
	}
	if (j + 1 == max_index)
	{
		swap_top(NULL, stack_b, count);
		return (sort_and_push_five(stack_a, stack_b, count, count_top));
	}
	while (count_top)
	{
		sort_to_a(stack_a, stack_b, count);
		count_top--;
	}
}
