/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 23:19:24 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/04 13:08:24 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_and_push(t_stack stack, int count_top)
{
	if (count_top == 5)
		sort_and_push_five(stack, count_top);
	else if (count_top == 4)
		sort_and_push_four(stack, count_top);
	else if (count_top == 3)
		sort_and_push_three(stack, count_top);
	else if (count_top == 2 || count_top == 1)
		sort_and_push_two(stack, count_top);
	rotate_to_destination(stack);
	// for (int i = 0; i < stack.count; i++)
	// 	printf("index %d:\t%d\t%d\n", i, stack.a[i], stack.b[i]);
}

void	sort_and_push_two(t_stack stack, int count_top)
{
	int	j;

	j = top_of_stack(stack.b, stack.count);
	if (count_top == 2)
	{
		if (stack.b[j] < stack.b[j + 1])
			swap_top_b(stack);
	}
	rotate_a_to_position(stack);
	if (count_top == 2)
	{
		push_b_to_a(stack);
		push_b_to_a(stack);
	}
	else if (count_top == 1)
		push_b_to_a(stack);
	else
		return ;
}

void	sort_and_push_three(t_stack stack, int count_top)
{
	int	max_index;
	int	j;

	max_index = find_max(stack.b, stack.count, count_top);
	j = top_of_stack(stack.b, stack.count);
	if (j == max_index)
	{
		sort_to_a(stack);
		return (sort_and_push_two(stack, count_top - 1));
	}
	if (j + 1 == max_index)
	{
		swap_top_b(stack);
		return (sort_and_push_three(stack, count_top));
	}
	while (count_top)
	{
		sort_to_a(stack);
		count_top--;
	}
}

void	sort_and_push_four(t_stack stack, int count_top)
{
	int	max_index;
	int	j;

	max_index = find_max(stack.b, stack.count, count_top);
	j = top_of_stack(stack.b, stack.count);
	if (j == max_index)
	{
		sort_to_a(stack);
		return (sort_and_push_three(stack, count_top - 1));
	}
	if (j + 1 == max_index)
	{
		swap_top_b(stack);
		return (sort_and_push_four(stack, count_top));
	}
	while (count_top)
	{
		sort_to_a(stack);
		count_top--;
	}
}

void	sort_and_push_five(t_stack stack, int count_top)
{
	int	max_index;
	int	j;

	max_index = find_max(stack.b, stack.count, count_top);
	j = top_of_stack(stack.b, stack.count);
	if (j == max_index)
	{
		sort_to_a(stack);
		return (sort_and_push_four(stack, count_top - 1));
	}
	if (j + 1 == max_index)
	{
		swap_top_b(stack);
		return (sort_and_push_five(stack, count_top));
	}
	while (count_top)
	{
		sort_to_a(stack);
		count_top--;
	}
}
