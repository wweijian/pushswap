/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:39:39 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/31 00:23:02 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_stack(int *stack_a, int *stack_b, int count, int top_index)
{
	int	i;
	int	median_index;
	int	push_count;

	push_count = 0;
	median_index = find_median(stack_a, count);
	if (count - top_index < 3)
		return ;
	while (push_count < median_index - top_index)
	{
		i = top_of_stack(stack_a, count);
		while (stack_a[i] <= median_index)
		{
			i = push_a_to_b(stack_a, stack_b, count);
			push_count++;
		}
		if (push_count != median_index - top_index)
			rotate_stack(stack_a, NULL, count);
	}
	i = top_of_stack(stack_a, count);
	if (count - i > 3)
		return (split_stack (stack_a, stack_b, count, i));
}

void	make_base(int *stack_a, int count)
{
	while (stack_a[count - 1] != count)
		rotate_stack(stack_a, NULL, count);
	if (stack_a[count - 2] < stack_a[count - 3])
		swap_top(stack_a, NULL, count);
}

void	populate_stack_a(int *stack_a, int *stack_b, int count)
{
	int	i;
	int	j;
	
	i = top_of_stack(stack_a, count);
	j = top_of_stack(stack_b, count);
	if (j == count || i == 0)
		return ;
	if (stack_a[i] == 1)
		return ;
	stack_dump(stack_a, stack_b, count);
	rotate_to_next_op(stack_a, stack_b, count);
	// for (int i = 0; i < count; i++)
	// 	printf("index %d:\t%d\t\t%d\n", i, stack_a[i], stack_b[i]);
	return (populate_stack_a(stack_a, stack_b, count));
}

void	write_solution(int *stack_a, int *stack_b, int count)
{
	// for (int i = 0; i < count; i++)
	// 	printf("index %d:\t%d\t\t%d\n", i, stack_a[i], stack_b[i]);
	split_stack(stack_a, stack_b, count, 0);
	// for (int i = 0; i < count; i++)
	// 	printf("index %d:\t%d\t\t%d\n", i, stack_a[i], stack_b[i]);
	// printf("\nmake base\n-------\n");
	make_base(stack_a, count);
	for (int i = 0; i < count; i++)
		printf("index %d:\t%d\t\t%d\n", i, stack_a[i], stack_b[i]);
	// printf("\npopulate stack a\n-------\n");
	// for (int i = 0; i < 40; i++)
	populate_stack_a(stack_a, stack_b, count);
	rotate_to_destination(stack_a, count);
	for (int i = 0; i < count; i++)
		printf("index %d:\t%d\t\t%d\n", i, stack_a[i], stack_b[i]);
}

/* 
	for (int i = 0; i < count; i++)
		printf("index %d:\t%d\t\t%d\n", i, stack_a[i], stack_b[i]);
*/

/*
	sa
	ra
	sa
	pa
	sa
	pa
*/

/*  // split_stack implementation that does not binary split
if (stack_a[i] < median)
{
	if (stack_a[i] < stack_a[i + 1])
		push_a_to_b(stack_a, stack_b, count);
	else
		swap_a(stack_a, stack_b, count);
}
 */
/* 
 printf("hi %d  %d  %d  %d\n", j, stack_b[j], i, stack_a[i]);
 */

/* static void	split_stack(int *stack_a, int *stack_b, int count, int index)
{
	int	i;

	i = 0;
	while (count - i > 3)
	{
		if (stack_a[i] < count - 2)
		{
			push_a_to_b(stack_a, stack_a, count);
			i++;
		}
		else
			rotate_stack(stack_a, NULL, count);
	}
	(void) index;
} */